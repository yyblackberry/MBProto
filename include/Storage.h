#pragma once
#include <sqlite3.h>
#include <string>
#include <cstring>
#include <stdexcept>

class Storage
{
private:
    bool __is_started = false;
    std::string __storage_name;
    sqlite3 *__db;

public:
    Storage(std::string storage_name);
    void start();
    void stop();
    ~Storage();
};
