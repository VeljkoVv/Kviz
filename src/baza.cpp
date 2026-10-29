#include "baza.h"
#include "../lib/sqlite/sqlite3.h"
#include <iostream>


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

std::vector<KvizPodaci> Baza::ucitajSveKvizove() {
    std::vector<KvizPodaci> kvizovi;
    sqlite3_stmt* stmt = nullptr;

    const char* sql = "SELECT id, naziv FROM kvizovi;";

     if (sqlite3_prepare_v2(db_p, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::string err = sqlite3_errmsg(db_p);
        throw std::runtime_error("Greska pri upitu: " + err);
     }

     while(sqlite3_step(stmt) == SQLITE_ROW){
        KvizPodaci k;
        k.id = sqlite3_column_int(stmt, 0);
        const unsigned char* naziv = sqlite3_column_text(stmt, 1);
        k.naziv = naziv ? reinterpret_cast<const char*>(naziv) : "";

        kvizovi.push_back(k);
     }

    sqlite3_finalize(stmt);
    return kvizovi;
}

std::vector<PitanjePodaci> Baza::ucitajSvaPitanjaKviza(int id_kviza) {
    std::vector<PitanjePodaci> pitanja;
    sqlite3_stmt* stmt = nullptr;

    const char* sql = "SELECT id, id_kviza, tekst, odgovor1, odgovor2, odgovor3, odgovor4, tacan_odgovor FROM pitanja WHERE id_kviza = ?;";

    if (sqlite3_prepare_v2(db_p, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::string err = sqlite3_errmsg(db_p);
        throw std::runtime_error("Greska pri upitu: " + err);
     }

    sqlite3_bind_int(stmt, 1, id_kviza);

    while(sqlite3_step(stmt) == SQLITE_ROW){
        PitanjePodaci p;
        p.id = sqlite3_column_int(stmt, 0);
        p.id_kviza = sqlite3_column_int(stmt, 1);
    
        const unsigned char* tekst = sqlite3_column_text(stmt, 1);
        p.tekst = tekst ? reinterpret_cast<const char*>(tekst) : "";
        const unsigned char* o1 = sqlite3_column_text(stmt, 2);
        p.odgovor1 = o1 ? reinterpret_cast<const char*>(o1) : "";
        const unsigned char* o2 = sqlite3_column_text(stmt, 3);
        p.odgovor2 = o2 ? reinterpret_cast<const char*>(o2) : "";
        const unsigned char* o3 = sqlite3_column_text(stmt, 4);
        p.odgovor3 = o3 ? reinterpret_cast<const char*>(o3) : "";
        const unsigned char* o4 = sqlite3_column_text(stmt, 5);
        p.odgovor4 = o4 ? reinterpret_cast<const char*>(o4) : "";
        
        p.tacan_odgovor = sqlite3_column_int(stmt, 6);

        pitanja.push_back(p);
    }

    sqlite3_finalize(stmt);
    return pitanja;
}