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
            "  (2, 1, 'Najduza reka?', 'Dunav', 'Morava', 'Sava', NULL, 2);";

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
