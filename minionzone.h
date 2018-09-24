#ifndef __MINIONZONE__
#define __MINIONZONE__
#include "cardcontainer.h"
#include "constants.h"

class Card;

class Minion;
class MinionZone: public CardContainer {
  int size = 0, capacity = MINIONZONE_CAPACITY;
 public:
  Minion *getMinion(int i);
  int getCapacity() const;
  
  void addCard(Card *) override;
  void transferCard(CardContainer &) override;
  void transferCard(CardContainer &, int) override; // this isn't overriden?
  // Card *getCard(int); // this method should be in superclass
  int onField() const;
  bool isFull() const;
};
#endif
