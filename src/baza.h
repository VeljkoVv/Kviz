#pragma once
#include <string>
#include <vector>
#include "kviz.h"
#include "pitanje.h"

struct sqlite3;

class Baza{
    public:
        explicit Baza(const std::string& putanja);
        ~Baza();
        Baza(const Baza&) = delete;
        Baza& operator=(const Baza&) = delete;

        std::vector<Kviz> ucitajSveKvizove() const;
        std::vector<Pitanje> ucitajSvaPitanjaKviza(int kviz_id) const;

    private:
        sqlite3* db_p = nullptr;
};