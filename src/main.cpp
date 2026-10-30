#include "kviz.h"
#include "pitanje.h"
#include "baza.h"
#include <iostream>
#include <string>
#include <vector> 

#define DB_PATH "db/kviz.db"
    
void ispisiPitanje(std::ostream& out, const Pitanje& p, int i){
    out << "\nPitanje " << i << ":" << std::endl;
    out << p.getTekst() << std::endl;
    out << std::endl;
    out << "a. " << p.getOdgovor1() << std::endl;
    out << "b. " << p.getOdgovor2() << std::endl;
    out << "c. " << p.getOdgovor3() << std::endl;
    out << "d. " << p.getOdgovor4() << std::endl;
}   
int main(){

    std::cout << "Unesite vase ime: " << std::endl;
    std::string ime;
    std::cin >> ime;

    Baza b(DB_PATH);

    std::cout << "\nTrenutno dostupni kvizovi:" << std::endl;
    std::vector<Kviz> kvizovi;
    kvizovi = b.ucitajSveKvizove();
    if(kvizovi.empty()){
        std::cerr << "\nNema dostupnih kvizova!";
        return 1;
    }
    for (const auto& k : kvizovi){
        std::cout << k.getId() << ". " << k.getNaziv() << std::endl;
    }
    std::cout << "\nOdaberite zeljeni kviz: " << std::endl;
    int i;
    std::cin >> i;

    int index_kviza = Kviz::pronadjiIndeks(kvizovi, i);
    if(index_kviza == -1){
         std::cerr << "\nNepostojeca opcija!";
         return 1;
    }
    std::cout << "\n" << index_kviza + 1 << ". " << kvizovi[index_kviza].getNaziv() << std::endl;

    ucitajPitanja(b, kvizovi, i);

    int score = 0;
    
    
    std::vector<Pitanje> pitanja = kvizovi[index_kviza].getPitanja();

    int index_pitanja = 1;
    for(auto& p : pitanja){

        ispisiPitanje(std::cout, p, index_pitanja);
            
        char c;
        do{
            std::cout << "Vas odgovor: ";
            std::cin >> c;
        } while (c < 'a' || c > 'd');

        if(p.jeTacan(c)){
            score++;
        }
        index_pitanja++;
    }



    std::cout << "\n" << ime << " je pogodio " << score << "/" << pitanja.size() << " pitanja." << std::endl;
    

    return 0;
}