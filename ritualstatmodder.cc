#include "ritualstatmodder.h"
#include "ritualzone.h"
#include "ritual.h"

int RitualStatModder::getCharges() const {
  return charges;
}

int RitualStatModder::getActivationCost() const {
  return activationCost;
}

RitualStatModder::RitualStatModder(int charges, int activationCost, RitualZone &ally, RitualZone &opponent):
  charges{charges}, activationCost{activationCost}, ally{ally}, opponent{opponent} { }

void RitualStatModder::addTarget(Ritual *newRitual) {
  targets.emplace_back(newRitual);
}

void RitualStatModder::activate() {
  for (int i = 0; i < ally.getSize(); i++) {
    if (ally.getRitual()->isTargetable()) {
      addTarget(ally.getRitual());
    }
  }
  for (int i = 0; i < opponent.getSize(); i++) {
    if (opponent.getRitual()->isTargetable()) {
      addTarget(opponent.getRitual());
    }
  }
  for (auto x: targets) {
    x->react(*this);
  }
}
