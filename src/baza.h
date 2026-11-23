#pragma once
#include <string>
#include <map>
#include <iostream>
#include "kviz.h"
#include "pitanje.h"

struct sqlite3;

class Baza{
    public:
        explicit Baza(const std::string& putanja);
        explicit Baza(sqlite3* db);
        ~Baza();
        Baza(const Baza&) = delete;
        Baza& operator=(const Baza&) = delete;

        std::map<int, Kviz> ucitajKvizove() const;
        void ucitajPitanjaKviza(Kviz& k) const;
        void rangListaUpis(std::string ime, int bodovi, int id_kviza) const;
        void rangListaKviza(int id_kviza, std::string ime_kviza, std::ostream& out) const;
    private:
        sqlite3* db_p = nullptr;
        bool vlasnik;
};