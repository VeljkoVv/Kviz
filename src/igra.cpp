#include "igra.h"
#include <iostream>

Igra::Igra() : ime(""), kviz(Kviz()), bodovi(0) {}
Igra::Igra(std::string i, Kviz k, int b) : ime(i), kviz(k), bodovi(b) {}

void Igra::zapocniIgru(){
    std::cout << "Unesite vase ime: " << std::endl;
    std::cin >> ime;
    setIme(ime);
}
    
bool Igra::odaberiKviz(Baza& bp){
    std::cout << "\nTrenutno dostupni kvizovi:" << std::endl;
    std::map<int, Kviz> kvizovi;
    kvizovi = bp.ucitajKvizove();
    if(kvizovi.empty()){
        std::cerr << "\nNema dostupnih kvizova!";
        return false;
    }
    for (const auto& [id, kviz] : kvizovi){
        std::cout << kviz.getId() << ". " << kviz.getNaziv() << std::endl;
    }
    std::cout << "\nOdaberite zeljeni kviz: " << std::endl;
    int i;
    std::cin >> i;

    if(!kvizovi.contains(i)){
        std::cerr << "\nNepostojeca opcija!";
        return false;
    }
    setKviz(kvizovi[i]);
    return true;
}

void Igra::igrajKviz(Baza& b){
    std::cout << "\n" << kviz.getId() << ". " << kviz.getNaziv() << std::endl;

    b.ucitajPitanjaKviza(kviz);

    std::vector<Pitanje> pitanja = kviz.getPitanja();

    int index_pitanja = 1;
    for(auto& p : pitanja){

        p.ispisiPitanje(std::cout, index_pitanja);
            
        char c;
        do{
            std::cout << "Vas odgovor: ";
            std::cin >> c;
        } while (c < 'a' || c > 'd');

        proveriOdgovor(p, c);
        index_pitanja++;
    }
}

void Igra::proveriOdgovor(Pitanje& p, char c){
    if(p.jeTacan(c)) bodovi++;
}

void Igra::krajKviza(){
    std::cout << "\n" << getIme() << " je pogodio " << getBodovi() << "/" << getKviz().getPitanja().size() << " pitanja." << std::endl;
}

std::string Igra::getIme(){
    return ime;
}
Kviz Igra::getKviz(){
    return kviz;
}
int Igra::getBodovi(){
    return bodovi;
}

void Igra::setIme(std::string i){
    ime = i;
}
void Igra::setBodovi(int b){
    bodovi = b;
}
void Igra::setKviz(Kviz& k){
    kviz = k;
}