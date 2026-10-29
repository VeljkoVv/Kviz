#pragma once
#include <string>
#include <vector>

struct sqlite3;

struct PitanjePodaci{
    int id;
    int id_kviza;
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

class Baza{
    public:
        explicit Baza(const std::string& putanja);
        ~Baza();
        Baza(const Baza&) = delete;
        Baza& operator=(const Baza&) = delete;

        std::vector<KvizPodaci> ucitajSveKvizove();
        std::vector<PitanjePodaci> ucitajSvaPitanjaKviza(int id_kviza);

    private:
        sqlite3* db_p = nullptr;
};