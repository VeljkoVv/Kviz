#include <gtest/gtest.h>
#include <sstream>
#include "../src/igra.h"

class IgraTest : public :: testing :: Test {
    protected:
        Igra i;
        Pitanje p{1, 1, "Koliko poena vredi kos iza linije 6.75?", "1", "2", "3", "4", 3};
};

TEST_F(IgraTest, novaIgraPocinjeSa0Bodova){
    EXPECT_EQ(i.getBodovi(), 0);
}

TEST_F(IgraTest, bodoviSePovecavaju){
    i.proveriOdgovor(p, 'c');
    EXPECT_EQ(i.getBodovi(), 1);
}

TEST_F(IgraTest, bodoviSeNePovecavaju){
    i.proveriOdgovor(p, 'b');
    EXPECT_EQ(i.getBodovi(), 0);
}

TEST_F(IgraTest, bodoviSeSabiraju){
    i.proveriOdgovor(p, 'a');
    i.proveriOdgovor(p, 'b');
    i.proveriOdgovor(p, 'c');
    i.proveriOdgovor(p, 'd');
    i.proveriOdgovor(p, 'c');
    EXPECT_EQ(i.getBodovi(), 2);
}




