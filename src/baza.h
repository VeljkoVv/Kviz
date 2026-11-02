#pragma once
#include <string>
#include <vector>
#include <map>
#include "kviz.h"
#include "pitanje.h"

struct sqlite3;

class Baza{
    public:
        explicit Baza(const std::string& putanja);
        ~Baza();
        Baza(const Baza&) = delete;
        Baza& operator=(const Baza&) = delete;

        std::map<int, Kviz> ucitajKvizove() const;
        void ucitajPitanjaKviza(Kviz& k) const;

    private:
        sqlite3* db_p = nullptr;
};