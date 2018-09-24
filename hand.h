#ifndef __HAND__
#define __HAND__
#include "cardcontainer.h"
#include "constants.h"

class Hand : public CardContainer {
  int size = 0, capacity = HAND_CAPACITY;
  // bad style right now
 public:
  ~Hand();
  bool isFull();
  void addCard(Card *) override;

  void play(int);
  void play(int, Card *);
  
  // this method has no use in this class 
  void transferCard(CardContainer &) override; // meant for playing later
  void transferCard(CardContainer &, int) override; // indexing
};
#endif
