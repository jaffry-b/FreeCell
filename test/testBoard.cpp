#include <vector>
#include "catch.h"
#include "CardADT.h"
#include "DeckADT.h"
#include <iostream>
#include "Board.h"
TEST_CASE( "tests for Board", "[Board]"){

    Board newBoard;
    vector<vector<Card>> celltest1 = newBoard.getGameCells();
    vector<vector<Card>> celltest2 = newBoard.getHomeCells();
    vector<Card> celltest3 = newBoard.getFreeCells();

    Card newCard;
    Card newCard2;

    newCard2.setRank(TWO);
    newCard2.setSuit(HEART);

    bool booltest1 = newBoard.rankMatch(newCard2.getRank(), newCard.getRank());
    bool booltest2 = newBoard.suitMatch(newCard2.getSuit(), newCard.getSuit());

        SECTION("constructor for Board and suitMatch and rankMatch"){
            REQUIRE( celltest1.size() == NUM_OF_GAMECELLS );
            REQUIRE( celltest2.size() == NUM_OF_HOMECELLS );
            REQUIRE( celltest3.size() == NUM_OF_FREECELLS );
            REQUIRE( booltest1 );
            REQUIRE( booltest2 );
        }
    Card newCard3;
    for(int j = SPADE; j < int(DIAMOND)+1; j++){
        for(int i = ACE; i <= int(KING); i++){
            if(i%2 == 0){
                newCard3.setRank(Rank(i));
                newCard3.setSuit(Suit(j));
                newBoard.setGameCells(newCard3,7);
                newBoard.moveGameToHome(7,j);
            }
            newCard3.setRank(Rank(i));
            newCard3.setSuit(Suit(j));
            newBoard.setGameCells(newCard3,7);
            newBoard.moveGameToHome(7,j);
        }
    }

        SECTION("movement test for GameToHome"){
            REQUIRE(!newBoard.isEmptyHomeCell(0));
            REQUIRE(!newBoard.isEmptyHomeCell(1));
            REQUIRE(!newBoard.isEmptyHomeCell(2));
            REQUIRE(!newBoard.isEmptyHomeCell(3));
            REQUIRE(newBoard.WinGame());
        }

    Card newCard4;
    for(int j = SPADE; j < int(DIAMOND)+1; j++){
        for(int i = ACE; i <= int(KING); i++){
            if(i%2 == 0){
                newCard4.setRank(Rank(i));
                newCard4.setSuit(Suit(j));
                newBoard.setGameCells(newCard4,7);
                newBoard.moveGameToFree(7,j);
            }
                newCard4.setRank(Rank(i));
                newCard4.setSuit(Suit(j));
                newBoard.setGameCells(newCard4,7);
                newBoard.moveGameToFree(7,j);
        }
    }

        SECTION("movement test for GameToFree"){
            REQUIRE(!newBoard.isEmptyFreeCell(0));
            REQUIRE(!newBoard.isEmptyFreeCell(1));
            REQUIRE(!newBoard.isEmptyFreeCell(2));
            REQUIRE(!newBoard.isEmptyFreeCell(3));
            REQUIRE(newBoard.getFreeCells().size() == 4);
        }

    Board newBoard2;

    newBoard2.moveFreeToGame(2,3);
    newBoard2.moveFreeToGame(1,4);
    newBoard2.moveFreeToGame(3,3);
    newBoard2.moveFreeToGame(0,3);

        SECTION("movement test for FreeToGame"){
            REQUIRE(newBoard2.isEmptyFreeCell(0));
            REQUIRE(newBoard2.isEmptyFreeCell(1));
            REQUIRE(newBoard2.isEmptyFreeCell(2));
            REQUIRE(newBoard2.isEmptyFreeCell(3));
        }

    Card newCard5;
    newCard5.setSuit(HEART);
    newCard5.setRank(ACE);


    Board newBoard3;
    newBoard3.setGameCells(newCard5,7);
    newBoard3.setGameCells(newCard5,6);
    newBoard3.setGameCells(newCard5,5);
    newBoard3.setGameCells(newCard5,4);
    newBoard3.moveGameToFree(7,0);
    newBoard3.moveGameToFree(6,1);
    newBoard3.moveGameToFree(5,2);
    newBoard3.moveGameToFree(4,3);
    newBoard3.moveFreeToHome(0,0);
    newBoard3.moveFreeToHome(1,1);
    newBoard3.moveFreeToHome(2,2);
    newBoard3.moveFreeToHome(3,3);


        SECTION("movement test for  FreeToHome"){
            REQUIRE(!newBoard3.isEmptyHomeCell(0));
            REQUIRE(!newBoard3.isEmptyHomeCell(1));
            REQUIRE(!newBoard3.isEmptyHomeCell(2));
            REQUIRE(!newBoard3.isEmptyHomeCell(3));
        }

    Board newBoard4;



    for(int i = 0; i < NUM_OF_GAMECELLS; i++)
        newBoard4.moveGameToGame(1,0,i);
    for(int i = 0; i < NUM_OF_GAMECELLS; i++)
        newBoard4.moveGameToGame(1,1,i);
    for(int i = 0; i < NUM_OF_GAMECELLS; i++)
        newBoard4.moveGameToGame(1,2,i);
    for(int i = 0; i < NUM_OF_GAMECELLS; i++)
        newBoard4.moveGameToGame(1,3,i);
    for(int i = 0; i < NUM_OF_GAMECELLS; i++)
        newBoard4.moveGameToGame(1,4,i);
    for(int i = 0; i < NUM_OF_GAMECELLS; i++)
        newBoard4.moveGameToGame(1,5,i);
    for(int i = 0; i < NUM_OF_GAMECELLS; i++)
        newBoard4.moveGameToGame(1,6,i);
    for(int i = 0; i < NUM_OF_GAMECELLS; i++)
        newBoard4.moveGameToGame(1,7,i);

    int size[NUM_OF_GAMECELLS];

    for(int i = 0; i < NUM_OF_GAMECELLS; i++){
        size[i] = newBoard4.getGameCells().at(i).size();
    }

    bool finalTrue = false;

    for(int i = 0; i < NUM_OF_GAMECELLS; i++){
            finalTrue = (size[i] == newBoard4.getGameCells().at(i).size());
    }
        SECTION("movement test for  GameToGame"){
           REQUIRE(finalTrue);
        }
}