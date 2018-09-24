#ifndef __SPELL__
#define __SPELL__
#include "card.h"
#include "player.h"

#include <memory> // smart ptr
#include <vector>
#include "effect.h"

class Spell final: public Card {
  
  //  std::vector<std::unique_ptr<Effect *>> effects;
  std::vector<Effect *> effects; // try just effect pointers right now
  // unique _ ptrs 
 public:
  ~Spell();
  Spell(std::string name, int cost);
  void addEffect(Effect *effect);
  void play(int) override;
  
  void activateEffects();
};
#endif
