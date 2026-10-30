#pragma once
#include <string>

class Pitanje{
    public:
        Pitanje();
        Pitanje(int i, int ik, const std::string& t, const std::string& o1, const std::string& o2, 
            const std::string& o3, const std::string& o4, int to);
        Pitanje(const Pitanje& p);

        int getId() const;
        int getIdKviza() const;
        const std::string& getTekst() const;
        const std::string& getOdgovor1() const;
        const std::string& getOdgovor2() const;
        const std::string& getOdgovor3() const;
        const std::string& getOdgovor4() const;
        int getTacanOdgovor() const;

        void setId(int id);
        void setIdKviza(int id_kviza);
        void setTekst(const std::string& tekst);
        void setOdgovor1(const std::string& odgovor1);
        void setOdgovor2(const std::string& odgovor2);
        void setOdgovor3(const std::string& odgovor3);
        void setOdgovor4(const std::string& odgovor4);
        void setTacanOdgovor(int tacan_odgovor);

    private:
        int id;
        int id_kviza;
        std::string tekst;
        std::string odgovor1;
        std::string odgovor2;
        std::string odgovor3;
        std::string odgovor4;
        int tacan_odgovor;
};