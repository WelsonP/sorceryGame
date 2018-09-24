#ifndef __BOARD__
#define __BOARD__

#include <string>
#include "player.h"

class Board { // remember to make this a subject later
  Player p1, p2;
  bool p1isActive = true;
 public:
  Board(std::string p1_name, std::string p2_name, std::string p1_deck, std::string p2_deck); // there should be no default ctor
  Player &getActivePlayer(); // breaks encapsulation
  Player &getInactivePlayer();

  Player &getPlayer1();
  Player &getPlayer2();
  
  void changeTurn();  
};

#endif
