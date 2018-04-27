#include <vector>
#include "catch.h"
#include "CardADT.h"
#include "DeckADT.h"
#include <iostream>
TEST_CASE( "tests for DeckADT", "[DeckADT]"){

Deck newDeck;
Card newCard = newDeck.dealCard();

SECTION("dealing"){
    REQUIRE(newCard.getSuit() == DIAMOND);
    REQUIRE(newCard.getRank() == KING);
}

    for(int i = 1 ; i < MAX_CARDS; i++){
        newCard = newDeck.dealCard();
    }

SECTION("dealing2"){
    REQUIRE(newCard.getSuit() == SPADE);
    REQUIRE(newCard.getRank() == ACE);

}


    Deck newDeck2;
    Deck newDeck3;

    newDeck2.shuffleDeck();
    newDeck3.shuffleDeck();
    newDeck2.shuffleDeck();

    Card newCard1;
    Card newCard2;
    int count = 0;
    for(int i = 0; i < MAX_CARDS; i++){
        newCard1 = newDeck2.dealCard();
        newCard2 = newDeck3.dealCard();
        if((newCard1.getSuit() == newCard2.getSuit()) && (newCard1.getRank() == newCard2.getRank()) ){
            count++;
        }
    }



SECTION("shuffle testing"){
    REQUIRE(count != MAX_CARDS);

}

}