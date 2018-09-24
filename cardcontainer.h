#ifndef __CARDCONTAINER__
#define __CARDCONTAINER__

#include <memory>
#include <vector>
#include "card.h"

class CardContainer {
  // weird bug with unique ptr, use raw for now
 protected:
  std::vector<Card *> cards;
 public:
  // individual getter
  Card *getCard(int);

  int getSize();
  virtual ~CardContainer() = 0; // does this need to be pure virtual?
  virtual void addCard(Card *) = 0;

  // note: transferCard is a one way transfer,
  // i.e. you move the card in your container
  // to the other container in the argument
  virtual void transferCard(CardContainer &) = 0;
  virtual void transferCard(CardContainer &, int) = 0;
  // moves a card to another card container

  // this is used to tie a card with a player, be careful
  std::vector<Card *> &getContents();
};
#endif
