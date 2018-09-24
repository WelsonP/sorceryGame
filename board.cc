#include "board.h"
#include <iostream>
#include "cardcreator.h"

using namespace std;

Board::Board(string p1_name, string p2_name, string p1_deckfile, string p2_deckfile):
  p1{Player(p1_name, p1_deckfile)}, p2{Player(p2_name, p2_deckfile)}, p1isActive{true} {
    CardCreator cc; // initialize the player's hands here
    cout << "initializing player hands..." << endl;
    cc.initDeck(p1, p2, p1.getDeckfile());
    cc.initDeck(p2, p1, p2.getDeckfile());
					    }

Player &Board::getActivePlayer() {
  if (p1isActive) return p1;
  else return p2;
}

Player &Board::getInactivePlayer() {
  if (p1isActive) return p2;
  else return p1;
}

Player &Board::getPlayer1() {
  return p1;
}

Player &Board::getPlayer2() {
  return p2;
}

void Board::changeTurn() {
  cout << "changing turns" << endl;
  p1isActive = !p1isActive;
}
