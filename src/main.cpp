#include "kviz.h"
#include "pitanje.h"
#include "baza.h"
#include <iostream>


int igraj(const Baza& b){
    
    std::cout << "\nTrenutno dostpni kvizovi:" << std::endl;
    std::vector<Kviz> kvizovi;
    kvizovi = b.ucitajSveKvizove();
    for (const auto& k : kvizovi){
        std::cout << k.getId() << ". " << k.getNaziv() << std::endl;
    }

    std::cout << "\nOdaberite zeljeni kviz: " << std::endl;
    int i;
    std::cin >> i;
    return i;
}

void zapocniKviz(int i, const Baza& b){
    Kviz k;
    k.setPitanja(b.ucitajSvaPitanjaKviza(i));
   / k.ispisiPitanje();
}

int main(){

    std::cout << "Unesite vase ime: " << std::endl;
    std::string ime;
    std::cin >> ime;

    Baza b("db/kviz.db");
    int broj_kviza;
    broj_kviza = igraj(b);
    zapocniKviz(broj_kviza, b);
    
    

    return 0;
}