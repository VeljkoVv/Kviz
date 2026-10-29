#include "baza.h"
#include "sqlite3.h"
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

std::vector<KvizPodaci> ucitajSveKvizove(sqlite3* db_p) const{
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
        if (naziv != nullptr) {
            k.naziv = reinterpret_cast<const char*>(naziv);
        } else {
            k.naziv = "";
        }

        kvizovi.push_back(k);
     }

    sqlite3_finalize(stmt);
    return kvizovi;
}

std::vector<PitanjePodaci> ucitajSvaPitanjaKviza(int id_kviza, sqlite3* db_p) const{
    
    return ;
}