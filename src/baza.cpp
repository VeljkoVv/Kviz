#include "baza.h"
#include "../lib/sqlite/sqlite3.h"
#include <iostream>
#include <stdexcept>


Baza::Baza(const std::string& putanja){
    if(sqlite3_open_v2(putanja.c_str(), &db_p, SQLITE_OPEN_READONLY, nullptr) != SQLITE_OK){
        std::string err = sqlite3_errmsg(db_p);
        sqlite3_close(db_p);
        throw std::runtime_error("Greska pri otvaranju BP: " + err);
    }
}

Baza::~Baza(){
    sqlite3_close(db_p);
}

std::vector<Kviz> Baza::ucitajSveKvizove() const{
    std::vector<Kviz> kvizovi;
    sqlite3_stmt* stmt = nullptr;

    const char* sql = "SELECT id, naziv FROM kviz;";

     if (sqlite3_prepare_v2(db_p, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::string err = sqlite3_errmsg(db_p);
        throw std::runtime_error("Greska pri upitu: " + err);
     }

     while(sqlite3_step(stmt) == SQLITE_ROW){
        Kviz k;
        k.setId(sqlite3_column_int(stmt, 0));
        const unsigned char* naziv = sqlite3_column_text(stmt, 1);
        k.setNaziv(naziv ? reinterpret_cast<const char*>(naziv) : "");

        kvizovi.push_back(k);
     }

    sqlite3_finalize(stmt);
    return kvizovi;
}

std::vector<Pitanje> Baza::ucitajSvaPitanjaKviza(int kviz_id) const{
    std::vector<Pitanje> pitanja;
    sqlite3_stmt* stmt = nullptr;

    const char* sql = "SELECT id, kviz_id, tekst, odgovor1, odgovor2, odgovor3, odgovor4, tacan_odgovor FROM pitanja WHERE kviz_id = ?;";

    if (sqlite3_prepare_v2(db_p, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::string err = sqlite3_errmsg(db_p);
        throw std::runtime_error("Greska pri upitu: " + err);
     }

    sqlite3_bind_int(stmt, 1, kviz_id);

    while(sqlite3_step(stmt) == SQLITE_ROW){
        Pitanje p;
        p.setId(sqlite3_column_int(stmt, 0));
        p.setIdKviza(sqlite3_column_int(stmt, 1));
    
        const unsigned char* tekst = sqlite3_column_text(stmt, 2);
        p.setTekst(tekst ? reinterpret_cast<const char*>(tekst) : "");
        const unsigned char* o1 = sqlite3_column_text(stmt, 3);
        p.setOdgovor1(o1 ? reinterpret_cast<const char*>(o1) : "");
        const unsigned char* o2 = sqlite3_column_text(stmt, 4);
        p.setOdgovor2(o2 ? reinterpret_cast<const char*>(o2) : "");
        const unsigned char* o3 = sqlite3_column_text(stmt, 5);
        p.setOdgovor3(o3 ? reinterpret_cast<const char*>(o3) : "");
        const unsigned char* o4 = sqlite3_column_text(stmt, 6);
        p.setOdgovor4(o4 ? reinterpret_cast<const char*>(o4) : "");
        
        p.setTacanOdgovor(sqlite3_column_int(stmt, 7));

        pitanja.push_back(p);
    }

    sqlite3_finalize(stmt);
    return pitanja;
}