#include "CardADT.h"

using namespace std;
Card :: Card(){
    this->rnk = ACE;
    this->st = SPADE;
}

Card :: Card(Suit s, Rank r) {
            this->rnk = r;
            this->st = s;
}

Rank Card :: getRank() { return this->rnk; }
Suit Card :: getSuit() { return this->st; }
void Card :: setRank(Rank r) { this-> rnk = r; }
void Card :: setSuit(Suit s) { this->st = s; }