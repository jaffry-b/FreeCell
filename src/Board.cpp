#include "CardADT.h"
#include "DeckADT.h"
#include "Board.h"
#include <vector>
#include "Exceptions.h"
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

Board :: Board(){
    this->HomeCells.resize(NUM_OF_HOMECELLS);
    this->FreeCells.resize(NUM_OF_FREECELLS);
    this->GameCells.resize(NUM_OF_GAMECELLS);
    this->dck.shuffleDeck();
    this->win= false;

    int count = 0;
    srand(time(NULL));
    while(count < MAX_CARDS){
        for(int newCol = 0; newCol < NUM_OF_GAMECELLS && count < MAX_CARDS; newCol++){
            int ran = rand() % (8);
            this->GameCells[ran].push_back(this->dck.dealCard());
            count++;
        }
    }
    for(int i = 0; i < NUM_OF_FREECELLS; i++){
        emptyFreeCell[i] = true;
    }
}
void Board :: moveGameToGame(int numOfCards, int col1, int col2) {
    vector <Card> movingCard(numOfCards);
    int numMovedCards = 0;

    try {
        if(numOfCards > availableMoves(col2)){ throw invalid_move(); }
        if(!validGameCol(col1) || !validGameCol(col2)){
            throw outside_bounds();
        }

        if (!isEmptyGameCell(col1)) {
            movingCard.push_back(this->GameCells.at(col1).back());
            this->GameCells.at(col1).pop_back();
            numMovedCards++;

            for (int i = 0; i < numOfCards - 1; i++) {

                if (isEmptyGameCell(col1)) {

                    for (int i = 0; i < numMovedCards; i++) {

                        this->GameCells.at(col1).push_back(movingCard.back());
                        movingCard.pop_back();

                    }
                }


                if (rankMatch(this->GameCells.at(col1).back().getRank(),movingCard.back().getRank())) {

                    if ( suitMatch(movingCard.back().getSuit(), this->GameCells.at(col1).back().getSuit()) ) {

                        movingCard.push_back(this->GameCells.at(col1).back());
                        this->GameCells.at(col1).pop_back();
                        numMovedCards++;
                    } else {

                        for (int i = 0; i < numMovedCards; i++) {

                            this->GameCells.at(col1).push_back(movingCard.back());
                            movingCard.pop_back();

                        }

                    }
                } else {
                    for(int i = 0; i < numMovedCards; i++){

                        this->GameCells.at(col1).push_back(movingCard.back());
                        movingCard.pop_back();

                    }
                    throw invalid_move();
                }
            }
        } else
            throw invalid_move();

        if(isEmptyGameCell(col2)){

            for(int i = 0; i < numMovedCards ; i++){

                this->GameCells[col2].push_back(movingCard.back());
                movingCard.pop_back();
            }
        }
        else if (rankMatch(this->GameCells[col2].back().getRank(),movingCard.back().getRank())){

            if (suitMatch(movingCard.back().getSuit(), this->GameCells.at(col1).back().getSuit())){

                for(int i = 0; i < numMovedCards; i++){

                    this->GameCells[col2].push_back(movingCard.back());
                    movingCard.pop_back();
                }
            }else {

                for(int i = 0; i < numMovedCards; i++){

                    this->GameCells.at(col1).push_back(movingCard.back());
                    movingCard.pop_back();

                }
                throw invalid_move();
            }
        } else {

            for(int i = 0; i < numMovedCards; i++){

                this->GameCells.at(col1).push_back(movingCard.back());
                movingCard.pop_back();

            }
            throw invalid_move();
        }
    }catch (std::exception& e){ std::cout << e.what() << std::endl; }
}

void Board :: moveGameToFree(int gameCol, int freeCol){
    try {
        if( isEmptyFreeCell(freeCol) && validGameCol(gameCol) && validFreeCol(freeCol)) {
            if (!isEmptyGameCell(gameCol)) {
                if (emptyFreeCell[freeCol]) {
                    this->FreeCells[freeCol] = this->GameCells[gameCol].back();
                    this->GameCells[gameCol].pop_back();
                    emptyFreeCell[freeCol] = false;
                } else
                    throw invalid_move();
            } else {
                throw invalid_move();
            }
        } else
            throw outside_bounds();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }
}
void Board :: moveGameToHome(int gameCol, int homeCol){
    try {
        if (!isEmptyGameCell(gameCol) && validGameCol(gameCol) && validHomeCol(homeCol)) {
            if (isEmptyHomeCell(homeCol)) {
                if (this->GameCells[gameCol].back().getRank() == ACE){
                    this->HomeCells[homeCol].push_back(this->GameCells[gameCol].back());
                    this->GameCells[gameCol].pop_back();
                } else
                    throw invalid_card();
            } else {
                if(rankMatch(this->GameCells[gameCol].back().getRank(),this->HomeCells[homeCol].back().getRank())){
                    if(this->GameCells[gameCol].back().getSuit() == this->HomeCells[homeCol].back().getSuit()){
                        this->HomeCells[homeCol].push_back(this->GameCells[gameCol].back());
                        this->GameCells[gameCol].pop_back();
                    } else
                        throw invalid_move();
                } else
                    throw invalid_move();
            }
        } else
            throw empty_outside_bounds();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }

}
void Board :: moveFreeToGame(int freeCol, int gameCol){
    try {
        if (!isEmptyFreeCell(freeCol) && validGameCol(gameCol) && validFreeCol(freeCol)) {
            if (isEmptyGameCell(gameCol)) {
                this->GameCells[gameCol].push_back(this->FreeCells[freeCol]);
                emptyFreeCell[freeCol] = true;
            } else {
                if (rankMatch(this->GameCells[gameCol].back().getRank(), this->FreeCells[freeCol].getRank())
                    &&
                    suitMatch(this->FreeCells[freeCol].getSuit(), this->GameCells[gameCol].back().getSuit())) {
                    this->GameCells[gameCol].push_back(this->FreeCells[freeCol]);
                    emptyFreeCell[freeCol] = true;
                } else
                    throw invalid_move();
            }
        } else
            throw empty_outside_bounds();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }
}
void Board :: moveFreeToHome(int freeCol, int homeCol){
    try {

        if (!isEmptyFreeCell(freeCol)) {
            if (isEmptyHomeCell(homeCol) && validHomeCol(homeCol) && validFreeCol(freeCol)) {
                if (this->FreeCells[freeCol].getRank() == ACE) {
                    this->HomeCells[homeCol].push_back(this->FreeCells[freeCol]);
                    emptyFreeCell[freeCol] = true;
                } else {
                    throw invalid_card();
                }
            } else {
                if (rankMatch(this->FreeCells[freeCol].getRank(), this->HomeCells[homeCol].back().getRank())
                    && (this->FreeCells[freeCol].getSuit() == this->HomeCells[homeCol].back().getSuit())) {
                    this->HomeCells[homeCol].push_back(this->FreeCells[freeCol]);
                    emptyFreeCell[freeCol] = true;
                } else
                    throw invalid_move();
            }
        } else
            throw empty_cells();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }
}
bool Board :: WinGame(){
    int occupiedHomeCells = 0;
    for(int i = 0; i < NUM_OF_HOMECELLS; i++){
        if(this->HomeCells[i].size() == numOfRanks)
            occupiedHomeCells++;
    }
    if(occupiedHomeCells == NUM_OF_HOMECELLS || this->GameCells.empty()){
        win = true;
    }
    return win;
}

vector<vector<Card>> Board :: getGameCells(){
    try {
        if (!GameCells.empty())
            return this->GameCells;
        else
            throw empty_cells();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }
}
vector<vector<Card>> Board :: getHomeCells(){
try {
    if (!HomeCells.empty())
        return this->HomeCells;
    else
        throw empty_cells();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }
}
vector<Card> Board :: getFreeCells() {
try {
    if (!FreeCells.empty())
        return  this->FreeCells;
    else
        throw empty_cells();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }
}
void Board :: setGameCells(Card a, int i){
    try {
        if (validGameCol(i))
            this->GameCells[i].push_back(a);
        throw outside_bounds();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }
}


bool Board :: isEmptyGameCell(int col){
    try {
        if(0 <= col && col < NUM_OF_GAMECELLS)
            return this->GameCells[col].empty();
        throw outside_bounds();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }

}
bool Board :: isEmptyHomeCell(int col){
    try {
        if(0 <= col && col < NUM_OF_HOMECELLS)
            return  this->HomeCells[col].empty();
        throw outside_bounds();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }
}
bool Board :: isEmptyFreeCell(int col){
    try {
        if(0 <= col && col < NUM_OF_FREECELLS)
            return  emptyFreeCell[col];
        throw outside_bounds();
    }
    catch (std::exception& e){ std::cout << e.what() << std::endl; }
}

int Board :: availableMoves(int targetCol){
    int freeSpots = 1;
    int gameSpots = 0;
    for(int i = 0; i < NUM_OF_FREECELLS; i++){
        if(isEmptyFreeCell(i)){
            freeSpots++;
        }
    }
    for(int i = 0; i < NUM_OF_GAMECELLS; i++){
        if(isEmptyGameCell(i))
            gameSpots++;
    }

    if(this->GameCells[targetCol].empty()){
        gameSpots--;
    }
        int gameSpotsMoves = pow(2,gameSpots);
        return (freeSpots) * gameSpotsMoves ;


}

bool Board :: suitMatch(Suit a, Suit b) {
    if (a + 3 == b || a - 3 == b|| a + 1 == b  || a - 1 == b )
        return true;
    return false;
}
bool Board :: rankMatch(Rank a, Rank b){
    if(a - b == 1)
        return true;
    return false;
}
bool Board :: validGameCol(int gameCol){
    if (0 <= gameCol && gameCol < NUM_OF_GAMECELLS)
        return true;
    return false;
}
bool Board :: validFreeCol(int freeCol){
    if (0 <= freeCol && freeCol < NUM_OF_FREECELLS)
        return true;
    return false;
}
bool Board :: validHomeCol(int homeCol){
    if (0 <= homeCol && homeCol < NUM_OF_HOMECELLS)
        return true;
    return false;
}
