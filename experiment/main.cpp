/*
 *  use this file for experimenting with your code,
 *  testing things that don't work, debugging, etc.
 *  
 *  you can compile and run this via 'make experiment'
 *
 *  this file will not be graded
 */
#include "CardADT.h"
#include "DeckADT.h"
#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
  cout << "make experiment' will run this main" << endl;
    Card card1(Spade,rnk);

    /*
    Card card1();
    Card card2(SPADE,KING);

    if(card2.getRank() == KING)
        cout << "Rank is KING. CORRECT!" << endl;
    else
        cout << "'Rank is INCORRECT'" << endl;

    if(card2.getSuit() == SPADE)
        cout << "Suit is SPADE. CORRECT!" << endl;
    else
        cout << "'Suit is INCORRECT'" << endl;

    card2.setRank(QUEEN);
    card2.setSuit(HEART);

    if(card2.getRank() == QUEEN)
        cout << "Rank is QUEEN. CORRECT!" << endl;
    else
        cout << "'Rank is INCORRECT'" << endl;


    if(card2.getSuit() == HEART)
        cout << "Suit is HEART. CORRECT!" << endl;
    else
        cout << "'Suit is INCORRECT'" << endl;


    /*
    for(int i = 1; i <= MAX_CARDS; i++){
        l.dealCard();
    }

    Deck l;
    l.shuffleDeck();
    Card newCard = l.dealCard();
    bool t =  newCard.getSuit() == SPADE;
    cout << t << endl;
    /*
   bool t1 = newCard.getSuit() == SPADE;
   bool t2 = newCard.getSuit() == DIAMOND;
   bool t3 = newCard.getSuit() == CLUB;

   cout << t1 << endl;
   cout << t2 << endl;
   cout << t3 << endl;
             cout << "Home Cell #" << i << " is " << newBoard.isEmptyHomeCell(i) << endl;
/*

    Board newBoard;

    newBoard.moveGameToGame(2,1,2);
    for(int i = 0; i < NUM_OF_GAMECELLS; i++)
        cout << "Game Cell #" << i << " is " << newBoard.isEmptyGameCell(i) << endl;

    for(int i = 0; i < NUM_OF_HOMECELLS; i++)

    newBoard.moveGameToFree(1,0);
    newBoard.moveGameToFree(1,1);
    newBoard.moveGameToFree(1,2);
    newBoard.moveGameToFree(1,3);
    */

    /*
       newBoard.moveFreeToGame(2,3);
       newBoard.moveFreeToGame(1,4);
       newBoard.moveFreeToGame(3,3);
       newBoard.moveFreeToGame(0,3);
       for(int i = 0 ; i < NUM_OF_FREECELLS; i++){
           cout << "Free Cell #" << i << " is " << newBoard.isEmptyFreeCell(i) << endl;
       }

       newBoard.moveFreeToHome(0,3);
       newBoard.moveFreeToHome(1,3);
       newBoard.moveFreeToHome(2,3);
       newBoard.moveFreeToHome(3,3);

       for(int i = 0; i < NUM_OF_GAMECELLS; i++){
           for(int j = 0; j < NUM_OF_HOMECELLS; j++){
               newBoard.moveGameToHome(i,j);
           }
       }

         for(int i = 0; i < NUM_OF_HOMECELLS; i++) {
             cout << "Home Cell #" << i << " is " << newBoard.isEmptyHomeCell(i) << endl;
         }


         for(int i = 0; i < NUM_OF_GAMECELLS; i++)
             newBoard.moveGameToGame(1,i,1);

         for(int i = 0; i < NUM_OF_GAMECELLS; i++)
             cout << "Game Cell #" << i << " is " << newBoard.isEmptyGameCell(i) << endl;

         for(int i = 0; i< NUM_OF_GAMECELLS; i++)
             cout << newBoard.availableMoves(i) << endl;
     */
  return 0;



}