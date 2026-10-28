#include "pitanje.h"
#include <iostream>

Pitanje::Pitanje() : id(0), id_kviza(0), tekst(""), odgovor1(""), odgovor2(""), odgovor3(""), odgovor4(""), tacan_odgovor(0) {}
Pitanje::Pitanje(int i, int ik, std::string t, std::string o1, std::string o2, std::string o3,
     std::string o4, int to) : id(i), id_kviza(ik), tekst(t), odgovor1(o1), odgovor2(o2), odgovor3(o3), odgovor4(o4), tacan_odgovor(to) {}
Pitanje::Pitanje(const Pitanje& p) : id(p.id), id_kviza(p.id_kviza), tekst(p.tekst), odgovor1(p.odgovor1), odgovor2(p.odgovor2), odgovor3(p.odgovor3), odgovor4(p.odgovor4), tacan_odgovor(p.tacan_odgovor) {}

int Pitanje::getId() const {return id;}
int Pitanje::getIdKviza() const {return id_kviza;}
std::string Pitanje::getTekst() const {return tekst;}
std::string Pitanje::getOdgovor1() const {return odgovor1;}
std::string Pitanje::getOdgovor2() const {return odgovor2;}
std::string Pitanje::getOdgovor3() const {return odgovor3;}
std::string Pitanje::getOdgovor4() const {return odgovor4;}
int Pitanje::getTacanOdgovor() const {return tacan_odgovor;}

void Pitanje::setId(int i) {id = i;}
void Pitanje::setIdKviza(int ik) {id_kviza = ik;}
void Pitanje::setTekst(std::string t) {tekst = t;}
void Pitanje::setOdgovor1(std::string o1) {odgovor1 = o1;}
void Pitanje::setOdgovor2(std::string o2) {odgovor2 = o2;}
void Pitanje::setOdgovor3(std::string o3) {odgovor3 = o3;}
void Pitanje::setOdgovor4(std::string o4) {odgovor4 = o4;}
void Pitanje::setTacanOdgovor(int to) {tacan_odgovor = to;}