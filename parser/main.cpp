/* Copyright (C) 2021  Mattia  Lorenzo Chiabrando <https://github.com/mattiabrandon>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <fstream>
#include <regex>
#include <vector>
#include <map>

std::regex general_regex(R"(^(?:([a-z]+)\.)?([a-zA-Z_]+)#([a-f0-9]+) .*= .+;$)");
std::regex args_regex(R"([^{](\w+):([\w?!.<>#]+))");
std::regex flag_regex(R"(flags\.(\d+)\?([\w<>.]+))");
std::regex vector_regex(R"(vector<(\w+)>)", std::regex_constants::icase);

struct Argument
{
    std::string name, type, flag_index, read, write;
    bool is_flag, is_template;
};

std::string snake_to_camel(std::string string)
{
    std::string result;
    size_t position = 0;
    std::string token;

    while ((position = string.find('_')) != std::string::npos)
    {
        token = string.substr(0, position);
        token[0] = toupper(token[0]);
        result += token;
        string.erase(0, position + 1);
    }
    string[0] = toupper(string[0]);
    return result + string;
}

Argument parse_arg(std::string name, std::string type)
{
    Argument arg = {name == "default" ? "default_" : name, type};

    if (arg.name == "long" || arg.name == "static" || arg.name == "public" || arg.name == "delete")
        arg.name = arg.name + "_";
    std::smatch flag_match, vector_match;

    if (std::regex_match(arg.type, flag_match, flag_regex))
    {
        arg.flag_index = flag_match.str(1);
        arg.type = flag_match.str(2);
        arg.is_flag = true;
    }
    std::string type_class;
    bool is_bare;

    if (arg.type == "int" || arg.type == "long" || arg.type == "double" || arg.type == "string" || arg.type == "int128" || arg.type == "int256" || arg.type == "bytes")
    {
        type_class = arg.type;
        type_class[0] = toupper(type_class[0]);
        is_bare = true;
    }

    if (arg.type == "string" || arg.type == "bytes")
        arg.type = "std::string";
    else if (arg.type == "int128" || arg.type == "int256")
        arg.type = "uint" + arg.type.substr(3) + "_t";
    else if (std::regex_match(arg.type, vector_match, vector_regex))
    {
        std::string base_type = parse_arg(arg.name, vector_match[1].str()).type;
        type_class = "Vector<" + base_type + ">";
        arg.type = "std::vector<" + base_type + ">";
        is_bare = true;
    }
    else if (arg.type == "true" || arg.type == "Bool")
    {
        type_class = "Bool";
        arg.type = "bool";
        is_bare = true;
    }
    else if (arg.type == "!X")
    {
        type_class = "X";
        arg.type = "X";
        arg.is_template = true;
    }
    else if (arg.type != "int" && arg.type != "long" && arg.type != "double")
    {
        type_class = "TLObject";
        arg.type = type_class;
    }

    if (arg.type == "TLObject" || arg.type.substr(0, 11) == "std::vector")
        arg.read = "\n    " + arg.type + " " + arg.name + "_ = std::get<" + arg.type + ">(TLObject::read(reader));";
    else
        arg.read = "\n    " + arg.type + " " + arg.name + "_ = " + type_class + "::read(reader);";

    if (arg.is_flag)
    {
        if (arg.type == "bool")
        {
            arg.read = "\n    std::optional<bool> " + arg.name + "_;\n    " + arg.name + "_ = (1 << " + arg.flag_index + ") ? std::optional{true} : std::nullopt;";
            return arg;
        }
        else if (arg.type == "TLObject" || arg.type.substr(0, 11) == "std::vector")
            arg.read = "\n    std::optional<" + arg.type + "> " + arg.name + "_;\n    " + arg.name + "_ = (1 << " + arg.flag_index + ") ? std::optional{std::get<" + arg.type + ">(TLObject::read(reader))} : std::nullopt;";
        else
            arg.read = "\n    std::optional<" + arg.type + "> " + arg.name + "_;\n    " + arg.name + "_ = (1 << " + arg.flag_index + ") ? std::optional{" + type_class + "::read(reader)} : std::nullopt;";

        if (is_bare)
            arg.write = "\n\n    if (" + arg.name + ")\n        buffer += " + type_class + "::write(" + arg.name + ".value());";
        else
            arg.write = "\n\n    if (" + arg.name + ")\n        buffer += " + arg.name + ".value().write();";
    }
    else if (is_bare)
        arg.write = "\n    buffer += " + type_class + "::write(" + arg.name + ");";
    else
        arg.write = "\n    buffer += " + arg.name + ".write();";
    return arg;
}

int main()
{
    std::ifstream mtproto_api("mtproto_api.tl"), telegram_api("telegram_api.tl");

    if (!mtproto_api.good() || !telegram_api.good())
        throw std::runtime_error("Couldn't open 'mtproto_api.tl' or 'telegram_api.tl'");
    std::string line;
    bool is_type = true;
    std::map<std::string, std::ofstream *[2]> functions;
    std::map<std::string, std::ofstream *[2]> types;
    std::ofstream tl_object("../src/tl/TLObject.cpp");
    tl_object << "/* Copyright (C) 2021  Mattia  Lorenzo Chiabrando <https://github.com/mattiabrandon>\n *\n * This program is free software: you can redistribute it and/or modify\n * it under the terms of the GNU General Public License as published by\n * the Free Software Foundation, either version 3 of the License, or\n * (at your option) any later version.\n *\n * This program is distributed in the hope that it will be useful,\n * but WITHOUT ANY WARRANTY; without even the implied warranty of\n * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n * GNU General Public License for more details.\n *\n * You should have received a copy of the GNU General Public License\n * along with this program.  If not, see <https://www.gnu.org/licenses/>.\n */\n\n#include \"tl/TLObject.h\"\n";
    std::string tl_object_elements = "\nstd::variant<TLObject, std::vector<TLObject>> TLObject::read(Reader reader)\n{\n    int id = unpackInt(reader.read(4));\n\n";

    while (std::getline(mtproto_api, line) || std::getline(telegram_api, line))
    {
        std::smatch general_match;
        line = line[line.length() - 1] == '\r' ? line.substr(0, line.length() - 1) : line;

        if (line == "---types---" || line == "---functions---")
        {
            is_type = line == "---types---";
            continue;
        }
        else if (line.empty() || (line.length() > 2 && line.substr(0, 2) == "//") || !std::regex_match(line, general_match, general_regex))
            continue;
        std::string filename = general_match[1].str().empty() ? "base" : general_match[1].str();

        if (!(is_type ? types : functions).count(filename))
        {
            if (is_type)
            {
                types[filename][0] = new std::ofstream("../include/tl/types/" + filename + ".h");
                *types[filename][0] << "/* Copyright (C) 2021  Mattia  Lorenzo Chiabrando <https://github.com/mattiabrandon>\n *\n * This program is free software: you can redistribute it and/or modify\n * it under the terms of the GNU General Public License as published by\n * the Free Software Foundation, either version 3 of the License, or\n * (at your option) any later version.\n *\n * This program is distributed in the hope that it will be useful,\n * but WITHOUT ANY WARRANTY; without even the implied warranty of\n * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n * GNU General Public License for more details.\n *\n * You should have received a copy of the GNU General Public License\n * along with this program.  If not, see <https://www.gnu.org/licenses/>.\n */\n\n#pragma once\n#include \"tl/bare.h\"\n#include \"tl/TLObject.h\"\n#include <optional>\n";
                types[filename][1] = new std::ofstream("../src/tl/types/" + filename + ".cpp");
                *types[filename][1] << "/* Copyright (C) 2021  Mattia  Lorenzo Chiabrando <https://github.com/mattiabrandon>\n *\n * This program is free software: you can redistribute it and/or modify\n * it under the terms of the GNU General Public License as published by\n * the Free Software Foundation, either version 3 of the License, or\n * (at your option) any later version.\n *\n * This program is distributed in the hope that it will be useful,\n * but WITHOUT ANY WARRANTY; without even the implied warranty of\n * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n * GNU General Public License for more details.\n *\n * You should have received a copy of the GNU General Public License\n * along with this program.  If not, see <https://www.gnu.org/licenses/>.\n */\n\n#include \"tl/types/" + filename + ".h\"\n";
                tl_object << "#include \"tl/types/" + filename + ".h\"\n";
            }
            else
            {
                functions[filename][0] = new std::ofstream("../include/tl/functions/" + filename + ".h");
                *functions[filename][0] << "/* Copyright (C) 2021  Mattia  Lorenzo Chiabrando <https://github.com/mattiabrandon>\n *\n * This program is free software: you can redistribute it and/or modify\n * it under the terms of the GNU General Public License as published by\n * the Free Software Foundation, either version 3 of the License, or\n * (at your option) any later version.\n *\n * This program is distributed in the hope that it will be useful,\n * but WITHOUT ANY WARRANTY; without even the implied warranty of\n * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n * GNU General Public License for more details.\n *\n * You should have received a copy of the GNU General Public License\n * along with this program.  If not, see <https://www.gnu.org/licenses/>.\n */\n\n#pragma once\n#include \"tl/bare.h\"\n#include \"tl/TLObject.h\"\n#include <optional>\n";
                functions[filename][1] = new std::ofstream("../src/tl/functions/" + filename + ".cpp");
                *functions[filename][1] << "/* Copyright (C) 2021  Mattia  Lorenzo Chiabrando <https://github.com/mattiabrandon>\n *\n * This program is free software: you can redistribute it and/or modify\n * it under the terms of the GNU General Public License as published by\n * the Free Software Foundation, either version 3 of the License, or\n * (at your option) any later version.\n *\n * This program is distributed in the hope that it will be useful,\n * but WITHOUT ANY WARRANTY; without even the implied warranty of\n * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n * GNU General Public License for more details.\n *\n * You should have received a copy of the GNU General Public License\n * along with this program.  If not, see <https://www.gnu.org/licenses/>.\n */\n\n#include \"tl/functions/" + filename + ".h\"\n";
                tl_object << "#include \"tl/functions/" + filename + ".h\"\n";
            }
        }
        std::string name = snake_to_camel(general_match[2].str());

        if (name == "True" || name == "BoolFalse" || name == "BoolTrue" || name == "Vector")
        {
            if (name == "Vector")
                tl_object_elements += "    else if (id == 0x" + general_match[3].str() + ")\n        return Vector<TLObject>::read(reader);\n";
            continue;
        }
        std::sregex_iterator args_begin(line.begin(), line.end(), args_regex);
        std::sregex_iterator args_end;
        bool is_template = false;
        std::string reads, writes, flags_writes, arguments, constructor_header, flags_constructor_header, constructor_source, flags_constructor_source, returns, flags_returns;

        for (std::sregex_iterator i = args_begin; i != args_end; ++i)
        {
            std::smatch arg_match = *i;

            if (arg_match[1].str() == "flags")
            {
                reads += "\n    int flags = Int::read(reader);";
                flags_writes += "\n    int flags = 0;";
                continue;
            }
            Argument arg = parse_arg(arg_match[1].str(), arg_match[2].str());

            if (arg.is_template)
                is_template = true;
            reads += arg.read;
            writes += arg.write;

            if (arg.is_flag)
            {
                flags_writes += "\n    flags |= " + arg.name + " ? 1 << " + arg.flag_index + " : 0;";
                arguments += "\n    std::optional<" + arg.type + "> " + arg.name + ";";
                flags_constructor_header += "std::optional<" + arg.type + "> " + arg.name + "_ = std::nullopt, ";
                flags_constructor_source += "std::optional<" + arg.type + "> " + arg.name + "_, ";
                flags_returns += arg.name + "_, ";
            }
            else
            {
                arguments += "\n    " + arg.type + " " + arg.name + ";";
                constructor_header += arg.type + " " + arg.name + "_, ";
                constructor_source += arg.type + " " + arg.name + "_, ";
                returns += arg.name + "_, ";
            }
        }
        tl_object_elements += "    " + std::string(name == "ResPQ" ? "" : "else ") + "if (id == 0x" + general_match[3].str() + ")\n        return " + name + std::string(is_template ? "<TLObject>" : "") + "::read(reader);\n";
        constructor_header += flags_constructor_header;
        constructor_source += flags_constructor_source;
        returns += flags_returns;
        *(is_type ? types : functions)[filename][0] << "\n"
                                                    << (is_template ? "template <class X>\n" : "") << "class " << name << " : public TLObject\n{\nprivate:\n    int __id = 0x" << general_match[3].str() << ";\n\npublic:" << (!arguments.empty() ? arguments : "") << "\n    " << name << "("
                                                    << (!constructor_header.empty() ? constructor_header.substr(0, constructor_header.length() - 2) : "") << ")" << (constructor_header.empty() ? " = default" : "") << ";\n    static " << name << (is_template ? "<X>" : "") << " read(Reader reader);\n    std::string write();\n};\n";

        if (!constructor_source.empty())
            *(is_type ? types : functions)[filename][1] << "\n"
                                                        << (is_template ? "template <class X>\n" : "") << name << (is_template ? "<X>" : "") << "::" << name << "(" << constructor_source.substr(0, constructor_source.length() - 2) << ") {}\n\n";
        *(is_type ? types : functions)[filename][1] << (is_template ? "template <class X>\n" : "") << name << (is_template ? "<X>" : "") << " " << name << (is_template ? "<X>" : "") << "::read(Reader reader)\n{" << reads << "\n    return " << name << (is_template ? "<X>" : "") << "(" << (!constructor_source.empty() ? returns.substr(0, returns.length() - 2) : "") << ");\n}\n\n"
                                                    << (is_template ? "template <class X>\n" : "") << "std::string " << name << (is_template ? "<X>" : "") << "::write()\n{\n    std::string buffer;\n    buffer += Int::write(__id);" << flags_writes << writes << "\n    return buffer;\n}\n";
    }
    tl_object << tl_object_elements << "}\n";

    for (auto &&pair : functions)
    {
        delete pair.second[0];
        delete pair.second[1];
    }

    for (auto &&pair : types)
    {
        delete pair.second[0];
        delete pair.second[1];
    }
    return 0;
}
