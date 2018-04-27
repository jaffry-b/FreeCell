#include <vector>
#include "catch.h"
#include "CardADT.h"

TEST_CASE( "tests for CardADT", "[CardADT]"){
Card card1;
Card card2(SPADE,KING);

    SECTION("accessors for Card"){
        REQUIRE(card1.getRank() == ACE);
        REQUIRE(card1.getSuit() == SPADE);
        REQUIRE(card2.getRank() == KING);
        REQUIRE(card2.getSuit() == SPADE);
    }
    card2.setRank(QUEEN);
    card2.setSuit(HEART);
    SECTION("mutators for CardADT"){
        REQUIRE(card2.getRank() == QUEEN);
        REQUIRE(card2.getSuit() == HEART);
    }
}

