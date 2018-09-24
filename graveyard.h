#ifndef __GRAVEYARD__
#define __GRAVEYARD__
#include "cardcontainer.h"

class Graveyard final: public CardContainer {
 public:
  void addCard(Card *card) override;
  void transferCard(CardContainer &) override;
  void transferCard(CardContainer &, int) override;
  // for summoning from the graveyard
};
#endif
