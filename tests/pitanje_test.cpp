#include <gtest/gtest.h>
#include "../src/pitanje.h"
#include <sstream>

class PitanjeTest {
    Pitanje p{1, 1, "Koliko poena vredi kos iza linije 6.75?", "1", "2", "3", "4", 3};
};

TEST_F(PitanjeTest, TacanVracaTrue){
    EXPECT_TRUE(p.jeTacan('b'));
}