#include <gtest/gtest.h>
#include <sstream>
#include "../src/pitanje.h"

class PitanjeTest : public :: testing :: Test {
    protected:
        Pitanje p{1, 1, "Koliko poena vredi kos iza linije 6.75?", "1", "2", "3", "4", 3};
};

TEST_F(PitanjeTest, TacanOdgovorVracaTrue) {
    EXPECT_TRUE(p.jeTacan('c'));
}

TEST_F(PitanjeTest, NetacniOdgovoriVracajuFalse) {
    EXPECT_FALSE(p.jeTacan('a'));
    EXPECT_FALSE(p.jeTacan('b'));
    EXPECT_FALSE(p.jeTacan('d'));
}

TEST_F(PitanjeTest, NevalidanUnosVracaFalse) {
    EXPECT_FALSE(p.jeTacan('e'));
    EXPECT_FALSE(p.jeTacan('B'));   
    EXPECT_FALSE(p.jeTacan('2'));
}

TEST_F(PitanjeTest, PrviIPoslednjiOdgovorRade) {
    Pitanje prvi(1, 1, "?", "x", "y", "z", "w", 1);
    EXPECT_TRUE(prvi.jeTacan('a'));
    Pitanje poslednji(2, 1, "?", "x", "y", "z", "w", 4);
    EXPECT_TRUE(poslednji.jeTacan('d'));
}

TEST_F(PitanjeTest, SadrzajIspisa) {
    std::ostringstream out;
    p.ispisiPitanje(out, 3);
    std::string s = out.str();

    EXPECT_NE(s.find("Pitanje 3:"), std::string::npos);
    EXPECT_NE(s.find("Koliko poena vredi kos iza linije 6.75?"), std::string::npos);
    EXPECT_NE(s.find("a. 1"), std::string::npos);
    EXPECT_NE(s.find("b. 2"), std::string::npos);
    EXPECT_NE(s.find("c. 3"), std::string::npos);
    EXPECT_NE(s.find("d. 4"), std::string::npos);
}