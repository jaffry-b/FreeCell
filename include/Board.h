#ifndef BOARD_H
#define BOARD_H
/**
 * @author - Bilal Jaffry, Jaffryb
 * @version - April 9th/2018
 */

#include "CardADT.h"
#include "DeckADT.h"
#include <vector>

using namespace std;
/**
 * Constant set for number of free cells in a game board.
 */
const int NUM_OF_FREECELLS = 4;
/**
 * Constant set for number of home cells in a game board.
 */
const int NUM_OF_HOMECELLS = 4;
/**
 * Constant set for number of game cells in a game board.
 */
const int NUM_OF_GAMECELLS = 8;


/**
 * Class created for a board set for free cell.
 */
class Board{
    private:
        vector<vector<Card>> HomeCells;
        vector<Card> FreeCells;
        vector<vector<Card>> GameCells;
        bool emptyFreeCell [NUM_OF_FREECELLS];
        /**
         * Checks the validity of a game cell, if it is within range.
         * @param gameCol the index at which the a function is trying to access.
         * @return returns if the given game cell exists on the board.
         */
        bool validGameCol(int gameCol);
        /**
         * Checks the validity of a free cell, if it is within range.
         * @param freeCol the index at which the a function is trying to access.
         * @return returns if the given free cell exists on the board.
         */
        bool validFreeCol(int freeCol);
         /**
         * Checks the validity of a home cell, if it is within range.
         * @param homeCol the index at which the a function is trying to access.
         * @return returns if the given home cell exists on the board.
         */
        bool validHomeCol(int homeCol);
        /**
         * Checks to see how many moves are available to move in the deck.
         * @param targetCol target column of cell.
         * @return returns the number of cards/moves possible to be moved into a given cell.
         */
        int availableMoves(int targetCol);
        Deck dck;
        bool win;
    public:
        /**
         * Constructor to create a board fill of empty free and home cells, but occupied gamecells.
         */
        Board();
        /**
         * Moves a game card to another set of cards in game cell.
         * @param numOfCards number of cards that you wish to move.
         * @param col1 starting column to move the card.
         * @param col2 ending column to move the card.
         */
        void moveGameToGame(int numOfCards, int col1, int col2);
        /**
         * Moves a game card from game cell to home cell if able to.
         * @param gameCol starting column in GameCell to move card.
         * @param homeCol ending column in HomeCell card is being moved to.
         */
        void moveGameToHome(int gameCol, int homeCol);
        /**
         * Moves a game card from game cell to free cell if able to.
         * @param gameCol starting column in GameCell to move card.
         * @param freeCol ending column in FreeCell card is being moved to.
         */
        void moveGameToFree(int gameCol, int freeCol);
        /**
        * Moves a game card from free cell to game cell if able to.
        * @param freeCol starting column in FreeCell move card.
        * @param gameCol ending column in Gamecell card is being moved to.
        */
        void moveFreeToGame(int freeCol, int gameCol);
        /**
         * Moves a game card from free cell to home cell if able to.
         * @param freeCol starting column in FreeCell move card.
         * @param homeCol ending column in HomeCell card is being moved to.
         */
        void moveFreeToHome(int freeCol, int homeCol);
        /**
         * Checks the suits and if they are proper alternating colors for movement.
         * @param a first card suit.
         * @param b second card suit.
         * @return returns if the suit the first card is not the same color of the second card.
        */
        bool suitMatch(Suit a, Suit b);
        /**
         * Checks the suits and if they are proper alternating colors for movement.
         * @param a first card rank.
        * @param b second card rank.
        * @return returns if the rank the card differences is equal to 1.
        */
        bool rankMatch(Rank a, Rank b);
        /**
         * Sets the game cell at specific index of game cell to a new card.
        * @param a card being inserted into given cell.
        * @param i the position at which the card is being inserted.
        */
        void setGameCells(Card a, int i);
        /**
         * Checks if column for game cell is empty.
         * @param col the column for specific cell.
         * @return returns if the game cell is empty or not.
        */
        bool isEmptyGameCell(int col);
        /**
         * Checks if column for home cell is empty.
        * @param col the column for specific cell.
        * @return returns if the home cell is empty or not.
       */
        bool isEmptyHomeCell(int col);
        /**
         * Checks if column for free cell is empty.
        * @param col the column for specific cell.
        * @return returns if the free cell is empty or not.
       */
        bool isEmptyFreeCell(int col);
       /**
         * Returns a 2D vector representing a copy of the game cells.
        * @return returns 2D vector of game cells, full of cards.
       */
        vector<vector<Card>> getGameCells();
      /**
        * Returns a 2D vector representing a copy of the home cells.
       * @return returns 2D vector of home cells, full or empty of cards.
      */
        vector<vector<Card>> getHomeCells();
    /**
        * Returns a vector representing a copy of the free cells.
       * @return returns vector of free cells, full or empty of cards.
      */
        vector<Card> getFreeCells();
        /**
         * Checks if the game has been won.
         * @return returns if all cards in the home cell.
         */
        bool WinGame();
};



#endif
