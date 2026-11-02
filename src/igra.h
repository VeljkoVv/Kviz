#pragma once
#include "kviz.h"
#include "baza.h"

class Igra{

    public:
        Igra();
        Igra(std::string i, Kviz k, int b);

        void zapocniIgru();
        void igrajKviz(Baza& b);
        bool odaberiKviz(Baza& bp);
        void proveriOdgovor(Pitanje& p, char c);
        void krajKviza();

        std::string getIme() const;
        Kviz getKviz() const;
        int getBodovi() const;

        void setIme(std::string i);
        void setBodovi(int b);
        void setKviz(const Kviz& k);
    private:
        std::string ime;
        Kviz kviz;         
        int bodovi;
};