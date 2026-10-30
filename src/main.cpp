#include "kviz.h"
#include "pitanje.h"
#include "baza.h"
#include <iostream>
#include <cstdlib>  
    
void ispisiPitanje(const Pitanje& p, int i){
    std::cout << "\nPitanje " << i << ":" << std::endl;
    std::cout << p.getTekst() << std::endl;
    std::cout << std::endl;
    std::cout << "a. " << p.getOdgovor1() << std::endl;
    std::cout << "b. " << p.getOdgovor2() << std::endl;
    std::cout << "c. " << p.getOdgovor3() << std::endl;
    std::cout << "d. " << p.getOdgovor4() << std::endl;
}   
int main(){

    std::cout << "Unesite vase ime: " << std::endl;
    std::string ime;
    std::cin >> ime;

    Baza b("db/kviz.db");

    std::cout << "\nTrenutno dostpni kvizovi:" << std::endl;
    std::vector<Kviz> kvizovi;
    kvizovi = b.ucitajSveKvizove();
    if(kvizovi.empty()){
        std::cerr << "\nNema dostupnih kizova!";
        std::exit(1);
    }
    for (const auto& k : kvizovi){
        std::cout << k.getId() << ". " << k.getNaziv() << std::endl;
    }
    std::cout << "\nOdaberite zeljeni kviz: " << std::endl;
    int i;
    std::cin >> i;
    int match = 1;
    int index_kviza = 0;
    for (const auto& k : kvizovi){
        if(i == k.getId()){
            match = 0;

            break;
        }
        index_kviza++;
    }
    if(match){
        std::cerr << "\nNepostojeca opcija!";
        std::exit(1);
    }
    
    std::cout << "\n" << index_kviza + 1 << ". " << kvizovi[index_kviza].getNaziv() << std::endl;

    ucitajPitanja(b, kvizovi, i);

    int score = 0;
    for (auto& k : kvizovi) {
        if (k.getId() != i) continue;

        std::vector<Pitanje> pitanja = k.getPitanja();

        int index_pitanja = 1;
        for(auto& p : pitanja){

            ispisiPitanje(p, index_pitanja);
            
            std::cout << "Vas odgovor: ";
            char c;
            do{
                std::cin >> c;
            } while (c < 'a' || c > 'd');

            if(c - 'a' + 1 == p.getTacanOdgovor()){
                score++;
            }
            index_pitanja++;
        }

    }

    std::cout << "\n" << ime << " je pogodio " << score << "/10 pitanja." << std::endl;
    

    return 0;
}