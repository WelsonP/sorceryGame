#ifndef __DISCARDPILE__
#define __DISCARDPILE__
#include "cardcontainer.h"

class DiscardPile final: public CardContainer {
 public:
  void addCard(Card *card) override;
  void transferCard(CardContainer &) override;
  void transferCard(CardContainer &, int) override;
};
#endif
