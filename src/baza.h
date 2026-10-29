#pragma once
#include <string>
#include <vector>
#include "kviz.h"
#include "pitanje.h"

struct sqlite3;
/*
struct PitanjePodaci{
    int id;
    int kviz_id;
    std::string tekst;
    std::string odgovor1;
    std::string odgovor2;
    std::string odgovor3;
    std::string odgovor4;
    int tacan_odgovor;
};

struct KvizPodaci {
    int id;
    std::string naziv;
};
*/
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