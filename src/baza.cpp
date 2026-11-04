#include "baza.h"
#include "../lib/sqlite/sqlite3.h"
#include <iostream>
#include <stdexcept>
#include <map>


Baza::Baza(const std::string& putanja){
    vlasnik = true;
    if(sqlite3_open_v2(putanja.c_str(), &db_p, SQLITE_OPEN_READWRITE, nullptr) != SQLITE_OK){
        std::string err = sqlite3_errmsg(db_p);
        sqlite3_close(db_p);
        throw std::runtime_error("\nGreska pri otvaranju BP: " + err);
    }
}

Baza::Baza(sqlite3* db) : db_p(db), vlasnik(false) {}

Baza::~Baza(){
    if(vlasnik && db_p != nullptr){
        int status = sqlite3_close_v2(db_p);

        if (status == SQLITE_OK) {
            std::cerr << "\nBP uspesno zatvorena.\n";
        }
        else {
            std::cerr << "\nGreska pri zatvaranju BP (" << status << "): " << sqlite3_errstr(status) << '\n';
        }

        db_p = nullptr;
    }
}

std::map<int, Kviz> Baza::ucitajKvizove() const{
    std::map<int, Kviz> kvizovi;
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

        kvizovi[k.getId()] = k;
     }

    sqlite3_finalize(stmt);
    return kvizovi;
}

void Baza::ucitajPitanjaKviza(Kviz& kviz) const{
    std::vector<Pitanje> pitanja;
    sqlite3_stmt* stmt = nullptr;

    const char* sql = "SELECT id, kviz_id, tekst, odgovor1, odgovor2, odgovor3, odgovor4, tacan_odgovor FROM pitanja WHERE kviz_id = ?;";

    if (sqlite3_prepare_v2(db_p, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::string err = sqlite3_errmsg(db_p);
        throw std::runtime_error("Greska pri upitu: " + err);
    }

    sqlite3_bind_int(stmt, 1, kviz.getId());

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
    kviz.setPitanja(pitanja);
}

void Baza::rangListaUpis(std::string ime, int bodovi, int id_kviza) const{
    sqlite3_stmt* stmt = nullptr;

    const char* sql = "INSERT INTO Rang_lista (ime_igraca, id_kviza, bodovi) VALUES (?, ?, ?)";
    
    if (sqlite3_prepare_v2(db_p, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::string err = sqlite3_errmsg(db_p);
        throw std::runtime_error("Greska pri upisu: " + err);
    }

    sqlite3_bind_text(stmt, 1, ime.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, id_kviza);
    sqlite3_bind_int(stmt, 3, bodovi);

    if(sqlite3_step(stmt) != SQLITE_DONE){
        std::string err = sqlite3_errmsg(db_p);
        sqlite3_finalize(stmt);
        throw std::runtime_error("Greska pri upisu u rang listu: " + err);
    }

    sqlite3_finalize(stmt);
}

void Baza::rangListaKviza(int id_kviza, std::string ime_kviza, std::ostream& out) const{
    sqlite3_stmt* stmt = nullptr;
    const char* sql = "SELECT ime_igraca, bodovi FROM Rang_lista WHERE id_kviza = ? ORDER BY bodovi DESC, id ASC LIMIT 10;";

    if (sqlite3_prepare_v2(db_p, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::string err = sqlite3_errmsg(db_p);
        throw std::runtime_error("Greska pri upitu rang liste: " + err);
    }
    
    sqlite3_bind_int(stmt, 1, id_kviza);
    int mesto = 1;

    out << "\n------------------------" << std::endl;
    out << "Rang lista kviza " << ime_kviza << ":" << std::endl;
    while(sqlite3_step(stmt) == SQLITE_ROW){
        
        const unsigned char* ime = sqlite3_column_text(stmt, 0);
        int bodovi = sqlite3_column_int(stmt, 1);

        out << mesto++ << ". " << (ime ? reinterpret_cast<const char*>(ime) : "") << " | " << bodovi;
        switch (bodovi){
            case 1:
                out << " bod";
                break;
            case 2:
            case 3:
            case 4:
                out << " boda";
                break;
            default:
                out << " bodova";
                break;
        } 
        out << "\n";
    }
    sqlite3_finalize(stmt);
}