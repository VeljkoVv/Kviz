#include <gtest/gtest.h>
#include <sstream>
#include "../src/baza.h"
#include "../lib/sqlite/sqlite3.h"

class BazaTest : public :: testing :: Test {
    protected:
        sqlite3* db = nullptr;
        
        void SetUp() override {
        ASSERT_EQ(sqlite3_open(":memory:", &db), SQLITE_OK);

        const char* sql =
            "CREATE TABLE kviz (id INTEGER PRIMARY KEY, naziv TEXT);"
            "CREATE TABLE pitanja (id INTEGER PRIMARY KEY, kviz_id INTEGER, tekst TEXT,"
            "  odgovor1 TEXT, odgovor2 TEXT, odgovor3 TEXT, odgovor4 TEXT, tacan_odgovor INTEGER);"
            "INSERT INTO kviz VALUES (1, 'Geografija'), (2, 'Istorija');"
            "INSERT INTO pitanja VALUES"
            "  (1, 1, 'Glavni grad Srbije?', 'Novi Sad', 'Beograd', 'Nis', 'Subotica', 2),"
            "  (2, 1, 'Najduza reka?', 'Dunav', 'Morava', 'Sava', NULL, 2);"
            "CREATE TABLE Rang_lista (id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "  ime_igraca TEXT, id_kviza INTEGER, bodovi INTEGER);";
        ASSERT_EQ(sqlite3_exec(db, sql, nullptr, nullptr, nullptr), SQLITE_OK);
    }

    void TearDown() override {
        sqlite3_close(db);
    }
};

TEST_F(BazaTest, NepostojecaException){
    EXPECT_THROW(Baza("nepostoji.db"), std::runtime_error);
}

TEST_F(BazaTest, UcitavaKvizove) {
    Baza b(db);
    auto kvizovi = b.ucitajKvizove();

    EXPECT_EQ(kvizovi.size(), 2);
    EXPECT_EQ(kvizovi[1].getNaziv(), "Geografija");
}

TEST_F(BazaTest, UcitavaPitanjaKviza) {
    Baza b(db);
    Kviz k(1, "Geografija");

    b.ucitajPitanjaKviza(k);

    EXPECT_EQ(k.getPitanja().size(), 2);
}

TEST_F(BazaTest, KvizBezPitanja) {
    Baza b(db);
    Kviz k(2, "Istorija");

    b.ucitajPitanjaKviza(k);

    EXPECT_TRUE(k.getPitanja().empty());
}

TEST_F(BazaTest, UpisSeDodaje){
    Baza b(db);
    b.rangListaUpis("tester", 7, 1);

    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(db, "SELECT ime_igraca, bodovi, id_kviza FROM Rang_lista;", -1, &stmt, nullptr);
    ASSERT_EQ(sqlite3_step(stmt), SQLITE_ROW);
    EXPECT_STREQ(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)), "tester");
    EXPECT_EQ(sqlite3_column_int(stmt, 1), 7);
    EXPECT_EQ(sqlite3_column_int(stmt, 2), 1);
    sqlite3_finalize(stmt);
}

TEST_F(BazaTest, RangListaJeSortirana){
    Baza b(db);
    b.rangListaUpis("tester1", 3, 1);
    b.rangListaUpis("tester2", 8, 1);
    b.rangListaUpis("tester3", 5, 1);

    std::ostringstream out;
    b.rangListaKviza(1, "Geografija", out);
    std::string s = out.str();

    size_t t2 = s.find("1. tester2 | 8");
    size_t t3 = s.find("2. tester3 | 5");
    size_t t1 = s.find("3. tester1 | 3");
    ASSERT_NE(t2, std::string::npos);
    ASSERT_NE(t3, std::string::npos);
    ASSERT_NE(t1, std::string::npos);
    EXPECT_LT(t2, t3);
    EXPECT_LT(t3, t1);
}
TEST_F(BazaTest, RangListaPrikazujeSamoIzabraniKviz) {
    Baza b(db);
    b.rangListaUpis("tester1", 8, 1);
    b.rangListaUpis("tester2", 9, 2);

    std::ostringstream out;
    b.rangListaKviza(1, "Geografija", out);

    EXPECT_NE(out.str().find("tester1"), std::string::npos);
    EXPECT_EQ(out.str().find("tester2"), std::string::npos);
}
TEST_F(BazaTest, PravilniOblikReciBod) {
    Baza b(db);
    b.rangListaUpis("A", 1, 1);
    b.rangListaUpis("B", 3, 1);
    b.rangListaUpis("C", 7, 1);

    std::ostringstream out;
    b.rangListaKviza(1, "Geografija", out);
    std::string s = out.str();

    EXPECT_NE(s.find("| 1 bod\n"), std::string::npos);
    EXPECT_NE(s.find("| 3 boda\n"), std::string::npos);
    EXPECT_NE(s.find("| 7 bodova\n"), std::string::npos);
}