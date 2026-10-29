#pragma once
#include <string>
#include <vector>
#include "pitanje.h"

class Kviz{
    public:
        Kviz();
        Kviz(int i, const std::string& n);
        Kviz(int i, const std::string& n, const std::vector<Pitanje>& p);
        Kviz(const Kviz& kviz);


        int getId() const;
        std::string getNaziv() const;
        const std::vector<Pitanje> getPitanja() const;

        void setId(int i);
        void setNaziv(const std::string& n);
        void setPitanja(const std::vector<Pitanje>& p);
    private:
        int id;
        std::string naziv;
        std::vector<Pitanje> pitanja;

};