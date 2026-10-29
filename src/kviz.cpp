#include "kviz.h"
#include "baza.h"
#include <iostream>


Kviz::Kviz() : id(0), naziv("") {}
Kviz::Kviz(int i, const std::string& n) : 
    id(i), naziv(n) {}
Kviz::Kviz(int i, const std::string& n, const std::vector<Pitanje>& p) : 
    id(i), naziv(n), pitanja(p) {}
Kviz::Kviz(const Kviz& kviz) : id(kviz.id), naziv(kviz.naziv), pitanja(kviz.pitanja) {}

void ispisiPitanje(){
    
}

int Kviz::getId() const {return id;}
std::string Kviz::getNaziv() const {return naziv;}
const std::vector<Pitanje> Kviz::getPitanja() const {return pitanja;}

void Kviz::setId(int i) {id = i;}
void Kviz::setNaziv(const std::string& n) {naziv = n;}
void Kviz::setPitanja(const std::vector<Pitanje>& p) {pitanja = p;}