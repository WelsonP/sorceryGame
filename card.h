#ifndef __CARD__
#define __CARD__

#include <string>
//#include "observer.h"
class Player;

class Card {
  std::string name;
  int cost;
 protected: // dangerous?
  Player *owner; 
 public:
  void lowerCost(int amount);
  Card(std::string name, int cost);
  virtual ~Card() = 0;
  // 
  void setOwner(Player *);
  // they will have shared ptrs to other cards later
  std::string getName() const;
  int getCost() const;
  
  virtual void play(int) = 0;
};
#endif
