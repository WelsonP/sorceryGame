#ifndef __GAME__
#define __GAME__

#include "board.h"
#include <string>
#include <iostream>
#include <memory>

class Player;

class Game {
  std::unique_ptr<Board> board;
  std::string p1_name, p2_name;
  std::string p1_deck, p2_deck;
  bool testing, graphics;
  
  void init(std::istream &);
  void initBoard();
  void initPlayerHands();
  
  bool inIsReadable(std::istream &);
  void play(std::istream &);
  bool isOver();
  
 public:
  void start(int argc, const char *argv[]);
  
  Player &getWinner();
};

#endif 
