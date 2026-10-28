#pragma once
#include "../lib/sqlite/sqlite3.h"
#include <string>

class Baza{
    public:
        Baza(const std::string& putanja);
        ~Baza();
    private:
        sqlite3* db_ = nullptr;
};