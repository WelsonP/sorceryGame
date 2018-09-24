#ifndef __DECK__
#define __DECK__

#include <string>
#include "cardcontainer.h"
#include "constants.h"
#include <fstream>
#include <map>

class Card;

class Deck: public CardContainer {
  static std::string cardList;
  static std::map<std::string, std::string> cardMap;
 public:
  void shuffle();
  void init();

  void drawCard();

  ~Deck();
   // probably wrong here
  void addCard(Card *) override;
  void transferCard(CardContainer &) override; 
  void transferCard(CardContainer &, int ) override;
  
  // void draw();
};
#endif
