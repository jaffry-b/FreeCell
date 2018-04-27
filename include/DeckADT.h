#ifndef DECKADT_H
#define DECKADT_H
/**
 * @author - Bilal Jaffry, Jaffryb
 * @version - April 9th/2018
 */

using namespace std;
#include <vector>

/**
 * Initialize constant for max number of cards.
 */
const int MAX_CARDS = 52;

/**
 * Class to hold Cards in a deck.
 */
class Deck{
    private:
        /**
        * Array of cards size of the maximum cards allowed in a deck.
        */
        Card deckOfCards[MAX_CARDS];
        /**
        * Number of cards drawn from the deck.
        */
        int numCard;
        /**
        * Swaps the addresses of two Card types, used in the random function.
        * @param a takes in the pointer to a card.
        * @param b takes in the pointer to another card.
        */
        void swap(Card* a, Card* b);

    public:

        /**
        * Creates a deck object with state variables for numOfCards dealt and an array holding a deck of cards.
        */
        Deck();

        /**
        * Accessor to get a card from the deck.
        * @return removes a card from the top of the deck.
        */
        Card dealCard();

        /**
        * Mutator to change the order of the cards in the deck, shuffling them. Swapping two addresses of randomized index of cards.
        */
        void shuffleDeck();
};




#endif
