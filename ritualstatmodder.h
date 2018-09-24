#ifndef __RITUALSTATMODDER__
#define __RITUALSTATMODDER__
#include "effect.h"
#include <vector>

class RitualZone;
class Ritual;
class RitualStatModder final: public Effect {
  std::vector<Ritual *> targets;
  int charges, activationCost;
  RitualZone &ally, &opponent;
 public:
  int getCharges() const;
  int getActivationCost() const;
  RitualStatModder(int charges, int activationCost, RitualZone &ally, RitualZone &opponent);
  void addTarget(Ritual *newRitual);
  void activate();
};
#endif
