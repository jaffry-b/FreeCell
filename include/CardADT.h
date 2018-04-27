#ifndef CARDADT_H
#define CARDADT_H
/**
 * @author - Bilal Jaffry, Jaffryb
 * @version - April 9th/2018
 */

using namespace std;

enum Rank {ACE=1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING};
enum Suit {SPADE,HEART,CLUB,DIAMOND};

/**
 * Constant integer for the number of different ranks in a deck.
 */
const int numOfRanks = 13;
/**
 * Constant integer for the number of different suits in a deck.
 */
const int numOfSuits = 4;
/**
 * Class to create a set of different cards based on their respective rank and suit.
 */
class Card{

    private:
        Rank rnk;
        Suit st;
    public:
        /**
        * Empty Constructor to create a single card, initially set with suit as Spade, rank is Ace.
        */
        Card();
        /**
        * Constructor to create a card given a suit and rank.
        * @param s suit that has been passed in as parameter.
        * @param r rank that hs been passed in as parameter.
        */
        Card(Suit s, Rank r);
        /**
         * Accessor to get the rank of a given card.
         * @return returns the rank of a the card.
         */
        Rank getRank();
        /**
         * Accessor to get the suit of a given card.
         * @return returns the suit of a the card.
         */
        Suit getSuit();
        /**
         * Mutator to set the rank of a given card.
         */
        void setRank(Rank r);
        /**
        * Mutator to set the suit of a given card.
        */
        void setSuit(Suit s);

};
#endif