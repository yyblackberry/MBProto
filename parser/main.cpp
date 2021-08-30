#include <iostream>
#include <string>
#include <fstream>
#include <fstream>
#include <assert.h>
#include <regex>
#include <vector>

const std::regex GENERAL_RE(R"(^(?:([a-z]+)\.)?(\w+)#([a-f0-9]+) .*= (?:([a-z]+)\.)?(\w+);\r?$)");
const std::regex ARGS_RE(R"([^{](\w+):([\w?!.<>#]+))");
const std::regex FLAG_RE(R"(flags\.(\d+)\?([\w<>.]+))");
const std::regex VECTOR_RE(R"([vV]ector<([\w.]+)>)", std::regex_constants::icase);
const std::regex SNAKE_CASE_RE(R"(([a-zA-Z\d]+))");
const std::string RESERVED[] = {"long", "static", "public", "delete", "default", "private"};
const std::string BARE[] = {"int", "int128", "int256", "long", "double", "bytes", "string", "Bool", "true"};
const std::string COPYRIGHT = "/* Copyright (c) 2021 Mattia Lorenzo Chiabrando\n * \n * Permission is hereby granted, free of charge, to any person obtaining a copy\n * of this software and associated documentation files (the \"Software\"), to deal\n * in the Software without restriction, including without limitation the rights\n * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n * copies of the Software, and to permit persons to whom the Software is\n * furnished to do so, subject to the following conditions:\n * \n * The above copyright notice and this permission notice shall be included in all\n * copies or substantial portions of the Software.\n * \n * THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n * SOFTWARE.\n */\n\n";

struct Argument
{
    std::string name, type, class_, index;
    bool is_flag, is_vector, is_bare;
};

const Argument parse_arg(const std::string name, const std::string type)
{
    Argument arg{name, type, type};
    arg.class_[0] = toupper(arg.class_[0]);

    if (std::find(std::begin(RESERVED), std::end(RESERVED), arg.name) != std::end(RESERVED))
        arg.name += "_";
    std::smatch flag_match;

    if (std::regex_match(arg.type, flag_match, FLAG_RE))
    {
        arg.index = flag_match.str(1);
        arg.type = flag_match.str(2);
        arg.class_ = flag_match.str(2);
        arg.class_[0] = toupper(arg.class_[0]);
        arg.is_flag = true;
    }
    std::smatch vector_match;

    if (std::regex_match(arg.type, vector_match, VECTOR_RE))
    {
        Argument base_arg = parse_arg(arg.name, vector_match.str(1));
        arg.type = "std::vector<" + base_arg.type + ">";
        arg.class_ = "Vector<" + base_arg.class_ + ">";
        arg.is_vector = true;
        arg.is_bare = true;
    }
    else if (std::find(std::begin(BARE), std::end(BARE), arg.type) != std::end(BARE))
    {
        if (arg.type.substr(0, 3) == "int" and arg.type != "int")
            arg.type += "_t";
        else if (arg.type == "bytes")
            arg.type = "std::vector<unsigned char>";
        else if (arg.type == "string")
            arg.type = "std::string";
        else if (arg.type == "Bool" || arg.type == "true")
        {
            if (arg.type == "true")
                arg.class_ = "Bool";
            arg.type = "bool";
        }
        arg.is_bare = true;
    }
    else if (arg.type == "!X")
        arg.type = arg.class_ = "X";
    else if (arg.type != "#")
        arg.type = arg.class_ = "TLObject";

    if (arg.is_flag)
        arg.type = "std::optional<" + arg.type + ">";
    return arg;
}

std::string snake_to_camel_case(const std::string input)
{
    std::string output;

    for (std::sregex_iterator i(input.begin(), input.end(), SNAKE_CASE_RE); i != std::sregex_iterator(); i++)
    {
        std::smatch match = *i;
        output += toupper(match.str(1)[0]);
        output += match.str(1).substr(1);
    }
    return output;
}

void parse_tl_object()
{
    std::ifstream mtproto("parser/assets/mtproto_api.tl");
    std::ifstream telegram("parser/assets/telegram_api.tl");
    assert(mtproto.is_open());
    assert(telegram.is_open());
    std::ofstream output("src/tl/TLObject.cpp");
    assert(output.is_open());
    output << COPYRIGHT << "#include \"tl/types.h\"\n\nTLObject TLObject::read(Reader reader)\n{\n    int id = Int::read(reader);\n\n    switch (id)\n    {" << std::endl;
    std::string line;
    bool is_type = true;

    while (std::getline(mtproto, line) || std::getline(telegram, line))
    {
        if (line == "---types---\r" || line == "int ? = Int;\r" || line == "---functions---\r")
        {
            is_type = line == "---types---\r" || line == "int ? = Int;\r";
            continue;
        }
        std::smatch match;

        if (!is_type || line.substr(0, 2) == "//" || line == "\r" || !std::regex_match(line, match, GENERAL_RE))
            continue;
        const std::string name = snake_to_camel_case(match.str(2));
        output << "    case " << (match.str(1) != "" ? match.str(1) + "::" : "") << name << "::getId():\n        return " << (match.str(1) != "" ? match.str(1) + "::" : "") << name << "::read(reader);\n"
               << std::endl;
    }
    output << "    default:\n        throw std::runtime_error(\"Unknown id received: \" + std::to_string(id));\n        break;\n    }\n}" << std::endl;
}

void parse(const bool types, const bool header)
{
    std::ifstream mtproto("parser/assets/mtproto_api.tl");
    std::ifstream telegram("parser/assets/telegram_api.tl");
    assert(mtproto.is_open());
    assert(telegram.is_open());
    std::ofstream output(std::string(header ? "include" : "src") + "/tl/" + (types ? "types" : "functions") + "." + (header ? "h" : "cpp"));
    assert(output.is_open());

    if (types)
        output << COPYRIGHT << (header ? "#pragma once\n#include <optional>\n#include \"tl/TLObject.h\"\n#include \"tl/bare.h\"" : "#include \"tl/types.h\"") << std::endl;
    else
        output << COPYRIGHT << (header ? "#pragma once\n#include \"tl/types.h\"" : "#include \"tl/functions.h\"") << std::endl;
    std::string line;
    bool is_type = true;
    std::string last_namespace;

    while (std::getline(mtproto, line) || std::getline(telegram, line))
    {
        if (line == "---types---\r" || line == "int ? = Int;\r" || line == "---functions---\r")
        {
            is_type = line == "---types---\r" || line == "int ? = Int;\r";
            continue;
        }
        std::smatch match;

        if ((types && !is_type) || (!types && is_type) || line.substr(0, 2) == "//" || line == "\r" || !std::regex_match(line, match, GENERAL_RE))
            continue;
        else if (match.str(1) != "" && match.str(1) != last_namespace)
        {
            if (last_namespace != "")
                output << "}" << std::endl;
            output << "\nnamespace " << match.str(1) << " {" << std::endl;
        }
        else if (last_namespace != "" && match.str(1) == "")
            output << "}\n";
        last_namespace = match.str(1);
        const std::string name = snake_to_camel_case(match.str(2));
        std::vector<Argument> args = {};
        bool has_flags = false, is_template = false;
        int i = 0;

        for (std::sregex_iterator i(line.begin(), line.end(), ARGS_RE); i != std::sregex_iterator(); i++)
        {
            std::smatch arg_match = *i;
            const Argument arg = parse_arg(arg_match.str(1), arg_match.str(2));

            if (arg.type == "#")
            {
                has_flags = true;
                continue;
            }
            else if (arg.type == "X")
                is_template = true;
            args.push_back(arg);
        }
        std::string tab = (match.str(1) == "") ? "" : "    ";

        if (args.size() == 0)
        {
            if (header)
            {
                output << "\n"
                       << tab << "class " << name << " : public TLObject\n"
                       << tab << "{\n"
                       << tab << "private:\n"
                       << tab << "    static const int __id = 0x" << match.str(3) << ";\n\n"
                       << tab << "public:\n"
                       << tab << "    static constexpr int getId()\n"
                       << tab << "    {\n"
                       << tab << "        return __id;\n"
                       << tab << "    }\n\n"
                       << tab << "    static " << name << " read(Reader reader);\n"
                       << tab << "    void write(Writer writer);\n"
                       << tab << "};"
                       << std::endl;
            }
            else
            {
                output << "\n"
                       << tab << name << " " << name << "::read(Reader reader)\n"
                       << tab << "{\n"
                       << tab << "    return " << name << "();\n"
                       << tab << "}\n\n"
                       << tab << "void " << name << "::write(Writer writer)\n"
                       << tab << "{\n"
                       << tab << "    Int::write(writer, __id);\n"
                       << tab << "}"
                       << std::endl;
            }
        }
        else if (has_flags)
        {
            if (header)
            {
                if (is_template)
                {
                    std::string declarations, constructors, assigners, readers, returns, flags_writers, writers;

                    for (Argument arg : args)
                    {
                        declarations += "\n        " + arg.type + " " + arg.name + ";";
                        assigners += ", " + arg.name + "(" + arg.name + "_)";

                        if (arg.is_flag)
                        {
                            readers += "\n        " + arg.type + " " + arg.name + "_ = flags & (1 << " + arg.index + ") ? std::optional{" + (arg.type == "std::optional<bool>" ? "true" : arg.class_ + "::read(reader)") + "} : std::nullopt;";
                            flags_writers += "\n        flags |= " + arg.name + " ? 1 << " + arg.index + " : 0;";
                        }
                        else
                        {
                            constructors += ", " + arg.type + " " + arg.name + "_";
                            readers += "\n        " + arg.type + " " + arg.name + "_ = " + arg.class_ + "::read(reader);";
                            returns += ", " + arg.name + "_";
                        }

                        if (arg.type == "std::optional<bool>")
                            continue;
                        else if (arg.is_flag)
                            writers += "\n\n        if (" + arg.name + ")\n            " + (arg.is_bare ? arg.class_ + "::write(writer, " + arg.name + ".value())" : arg.name + ".value().write(writer)") + ";";
                        else
                            writers += "\n        " + (arg.is_bare ? arg.class_ + "::write(writer, " + arg.name + ")" : arg.name + ".write(writer)") + ";";
                    }

                    for (Argument arg : args)
                        if (arg.is_flag)
                        {
                            constructors += ", " + arg.type + " " + arg.name + "_ = std::nullopt";
                            returns += ", " + arg.name + "_";
                        }
                    output << "\ntemplate <class X>\nclass " << name << " : public TLObject\n{\nprivate:\n    static const int __id = 0x" << match.str(3) << ";\n\npublic:\n    " << declarations.substr(9) << "\n\n    " << name << "(" << constructors.substr(2) << ") : " << assigners.substr(2) << " {};\n\n    static constexpr int getId()\n    {\n        return __id;\n    };\n\n    static " << name << "<X> read(Reader reader)\n    {\n        int flags = Int::read(reader);\n        " << readers.substr(9) << "\n        return " << name << "<X>(" << returns.substr(2) << ");\n    };\n\n    void write(Writer writer)\n    {\n        Int::write(writer, __id);\n        int flags = 0;\n        " << flags_writers.substr(9) << "\n        Int::write(writer, flags);\n        " << writers.substr(9) << "\n    };\n};" << std::endl;
                }
                else
                {
                    std::string declarations, constructors, assigners;

                    for (Argument arg : args)
                    {
                        declarations += "\n" + tab + "    " + arg.type + " " + arg.name + ";";

                        if (!arg.is_flag)
                            constructors += ", " + arg.type + " " + arg.name + "_";
                        assigners += ", " + arg.name + "(" + arg.name + "_)";
                    }

                    for (Argument arg : args)
                        if (arg.is_flag)
                            constructors += ", " + arg.type + " " + arg.name + "_ = std::nullopt";
                    output << "\n"
                           << tab << "class " << name << " : public TLObject\n"
                           << tab << "{\n"
                           << tab << "private:\n"
                           << tab << "    static const int __id = 0x" << match.str(3) << ";\n\n"
                           << tab << "public:\n"
                           << tab << "    " << declarations.substr(5 + tab.length()) << "\n\n"
                           << tab << "    " << name << "(" << constructors.substr(2) << ") : " << assigners.substr(2) << " {};\n\n"
                           << tab << "    static constexpr int getId()\n"
                           << tab << "    {\n"
                           << tab << "        return __id;\n"
                           << tab << "    };\n\n"
                           << tab << "    static " << name << " read(Reader reader);\n"
                           << tab << "    void write(Writer writer);\n"
                           << tab << "};"
                           << std::endl;
                }
            }
            else if (!is_template)
            {
                std::string readers, returns, flags_writers, writers;

                for (Argument arg : args)
                {
                    if (arg.is_flag)
                    {
                        readers += "\n" + tab + "    " + arg.type + " " + arg.name + "_ = flags & (1 << " + arg.index + ") ? std::optional{" + (arg.type == "std::optional<bool>" ? "true" : arg.class_ + "::read(reader)") + "} : std::nullopt;";
                        flags_writers += "\n" + tab + "    flags |= " + arg.name + " ? 1 << " + arg.index + " : 0;";
                    }
                    else
                    {
                        readers += "\n" + tab + "    " + arg.type + " " + arg.name + "_ = " + arg.class_ + "::read(reader);";
                        returns += ", " + arg.name + "_";
                    }

                    if (arg.type == "std::optional<bool>")
                        continue;
                    else if (arg.is_flag)
                        writers += "\n\n" + tab + "    if (" + arg.name + ")\n" + tab + "        " + (arg.is_bare ? arg.class_ + "::write(writer, " + arg.name + ".value())" : arg.name + ".value().write(writer)") + ";";
                    else
                        writers += "\n" + tab + "    " + (arg.is_bare ? arg.class_ + "::write(writer, " + arg.name + ")" : arg.name + ".write(writer)") + ";";
                }

                for (Argument arg : args)
                    if (arg.is_flag)
                        returns += ", " + arg.name + "_";
                output << "\n"
                       << tab << name << " " << name << "::read(Reader reader)\n"
                       << tab << "{\n"
                       << tab << "    int flags = Int::read(reader);\n"
                       << tab << "    " << readers.substr(5 + tab.length()) << "\n"
                       << tab << "    return " << name << "(" << returns.substr(2) << ");\n"
                       << tab << "}\n\n"
                       << tab << "void " << name << "::write(Writer writer)\n"
                       << tab << "{\n"
                       << tab << "    Int::write(writer, __id);\n"
                       << tab << "    int flags = 0;\n"
                       << tab << "    " << flags_writers.substr(5 + tab.length()) << "\n"
                       << tab << "    Int::write(writer, flags);\n"
                       << (writers.length() != 0 ? tab + "    " + writers.substr(5 + tab.length()) + "\n" : "")
                       << tab << "}"
                       << std::endl;
            }
        }
        else
        {
            if (header)
            {
                if (is_template)
                {
                    std::string declarations, constructors, assigners, readers, returns, writers;

                    for (Argument arg : args)
                    {
                        declarations += "\n    " + arg.type + " " + arg.name + ";";
                        constructors += ", " + arg.type + " " + arg.name + "_";
                        assigners += ", " + arg.name + "(" + arg.name + "_)";
                        readers += "\n        " + arg.type + " " + arg.name + "_ = " + arg.class_ + "::read(reader);";
                        returns += ", " + arg.name + "_";
                        writers += "\n        " + (arg.is_bare ? arg.class_ + "::write(writer, " + arg.name + ")" : arg.name + ".write(writer)") + ";";
                    }
                    output << "\ntemplate <class X>\nclass " << name << " : public TLObject\n{\nprivate:\n    static const int __id = 0x" << match.str(3) << ";\n\npublic:\n    " << declarations.substr(5 + tab.length()) << "\n\n    " << name << "(" << constructors.substr(2) << ") : " << assigners.substr(2) << " {};\n\n    static constexpr int getId()\n    {\n        return __id;\n    };\n\n    static " << name << "<X> read(Reader reader)\n    {\n        " << readers.substr(9) << "\n        return " << name << "<X>(" << returns.substr(2) << ");\n    };\n\n    void write(Writer writer)\n    {\n        Int::write(writer, __id);\n        " << writers.substr(9) << "\n    };\n};" << std::endl;
                }
                else
                {
                    std::string declarations, constructors, assigners;

                    for (Argument arg : args)
                    {
                        declarations += "\n" + tab + "    " + arg.type + " " + arg.name + ";";
                        constructors += ", " + arg.type + " " + arg.name + "_";
                        assigners += ", " + arg.name + "(" + arg.name + "_)";
                    }
                    output << "\n"
                           << tab << "class " << name << " : public TLObject\n"
                           << tab << "{\n"
                           << tab << "private:\n"
                           << tab << "    static const int __id = 0x" << match.str(3) << ";\n\n"
                           << tab << "public:\n"
                           << tab << "    " << declarations.substr(5 + tab.length()) << "\n\n"
                           << tab << "    " << name << "(" << constructors.substr(2) << ") : " << assigners.substr(2) << " {};\n\n"
                           << tab << "    static constexpr int getId()\n"
                           << tab << "    {\n"
                           << tab << "        return __id;\n"
                           << tab << "    };\n\n"
                           << tab << "    static " << name << " read(Reader reader);\n"
                           << tab << "    void write(Writer writer);\n"
                           << tab << "};" << std::endl;
                }
            }
            else if (!is_template)
            {
                std::string readers, returns, writers;

                for (Argument arg : args)
                {
                    readers += "\n" + tab + "    " + arg.type + " " + arg.name + "_ = " + arg.class_ + "::read(reader);";
                    returns += ", " + arg.name + "_";
                    writers += "\n" + tab + "    " + (arg.is_bare ? arg.class_ + "::write(writer, " + arg.name + ")" : arg.name + ".write(writer)") + ";";
                }
                output << "\n"
                       << tab << name << " " << name << "::read(Reader reader)\n"
                       << tab << "{\n"
                       << tab << "    " << readers.substr(5 + tab.length()) << "\n"
                       << tab << "    return " << name << "(" << returns.substr(2) << ");\n"
                       << tab << "}\n\n"
                       << tab << "void " << name << "::write(Writer writer)\n"
                       << tab << "{\n"
                       << tab << "    Int::write(writer, __id);\n"
                       << tab << "    " << writers.substr(5 + tab.length()) << "\n"
                       << tab << "}"
                       << std::endl;
            }
        }
    }

    if (!types)
        output << "}" << (header ? ";" : "") << "\n"
               << std::endl;
}

void show_help(const std::string name)
{
    std::cerr << "Usage: " << name << " [options]\n\n"
              << "Options:\n"
              << "\t-h, --help\t\tShow this message\n"
              << "\t-t, --types\t\tWrite the types file. Requires the --header or the --source flag\n"
              << "\t-f, --functions\t\tWrite the functions file. Requires the --header or the --source flag\n"
              << "\t-h, --header\t\tWrite the header file of the specified category. Requires the --types or the --functions flag\n"
              << "\t-s, --source\t\tWrite the source file of the specified category. Requires the --types or the --functions flag\n"
              << "\t-tl, --tl_object\tWrite the tl object file\n"
              << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 4)
    {
        show_help(argv[0]);
        return 1;
    }
    bool types, functions, header, source, tl_object;

    for (size_t i = 1; i < argc; i++)
    {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help")
        {
            show_help(argv[0]);
            return 0;
        }
        else if (arg == "-t" || arg == "--types")
            types = true;
        else if (arg == "-f" || arg == "--functions")
            functions = true;
        else if (arg == "-h" || arg == "--header")
            header = true;
        else if (arg == "-s" || arg == "--source")
            source = true;
        else if (arg == "-tl" || arg == "--tl_object")
            tl_object = true;
        else
        {
            std::cerr << "Invalid parameter \"" << arg << "\"\n\n";
            show_help(argv[0]);
            return 1;
        }
    }

    if ((types || functions) && (header || source))
        parse(types, header);
    else if (tl_object)
        parse_tl_object();
    else
    {
        std::cerr << "Invalid parameters\n\n";
        show_help(argv[0]);
        return 1;
    }
    return 0;
}
