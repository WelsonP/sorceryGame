#ifndef __ENCHANTMENT__
#define __ENCHANTMENT__
#include "card.h"
#include "player.h"

// final?
class Enchantment final: public Card {
 public:
  Enchantment(std::string name, int cost);
  void play(int i) override;
};
#endif
