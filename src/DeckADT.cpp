//
// Created by Bilal's PC on 4/7/2018.
//

#include "CardADT.h"
#include "DeckADT.h"
#include <iostream>
#include <time.h>
#include "Exceptions.h"
using namespace std;
Deck :: Deck() {
   numCard = 0;
    int decCounter = MAX_CARDS;
    for (int i = 1; i <= numOfRanks; i++) {
        for (int j = 0; j < numOfSuits ; j++) {
            decCounter--;
            deckOfCards[decCounter].setRank(static_cast<Rank>(i));
            deckOfCards[decCounter].setSuit(static_cast<Suit>(j));
        }
    }
}

Card Deck ::dealCard() {
    try {
        if(numCard > MAX_CARDS || numCard < 0){ throw outside_bounds(); }
        else
            return deckOfCards[numCard++];
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }

}

void Deck :: shuffleDeck() {
    srand(time(NULL));
    for (int i = sizeof(deckOfCards)/sizeof(deckOfCards[0]) - 1; i > 0; i--){
        int ran = rand() % (i+1);
        swap(&deckOfCards[i], &deckOfCards[ran]);
    }
}

void Deck :: swap(Card* a, Card* b){
    Card temp = *a;
    *a = *b;
    *b = temp;

}