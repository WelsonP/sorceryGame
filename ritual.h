#ifndef __RITUAL__
#define __RITUAL__
#include "card.h"

#include <vector>
#include "effect.h"
#include "target.h"
class RitualStatModder; 
class Killer;

class Ritual final: public Card, public Target {
  int charges, activationCost;
  //std::map<Trigger, Effect> for the ability
  bool targetable = false;
  std::vector<Effect *> effects;
  // can a class have more than one trigger?
  // keep things simple for now, just have one trigger
 public:
  Ritual(std::string name, int cost, int charges, int activationCost);
  void lowerCharges(int amount);
  void lowerActivationCost(int amount);
  void play(int) override;
  void react(RitualStatModder &effect); // set its targetability to false;
  void react(Killer &killerEffect) override;
  void die();
};
#endif
