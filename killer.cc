#include "killer.h"
#include "minion.h"
#include "minionzone.h"
#include "ritualzone.h"
#include "ritual.h"
#include "target.h"
using namespace std;

Killer::Killer(MinionZone &allyMZ, MinionZone &opMZ,
	       RitualZone &allyRZ, RitualZone &opRZ,
	       bool tgtAllAlly,
	       bool tgtAllOpponent):
  allyMZ{allyMZ}, opMZ{opMZ}, allyRZ{allyRZ}, opRZ{opRZ},
  tgtAllAlly{tgtAllAlly}, tgtAllOpponent{tgtAllOpponent} {}

void Killer::addTarget(Target *newTarget) {
  targets.emplace_back(newTarget);
}

void Killer::activate() {
  if (allyRZ.isFull() && allyRZ.getRitual()->isTargetable()) {
    // this is hacky
    addTarget(allyRZ.getRitual());
  }
  
  for (int i = 0; i < allyMZ.getSize(); i++) {
    if (tgtAllAlly || allyMZ.getMinion(i)->isTargetable()) {
      addTarget(allyMZ.getMinion(i));
    }
  }

  if (opRZ.isFull() && opRZ.getRitual()->isTargetable()) {
    addTarget(opRZ.getRitual());
  }

  for (int i = 0; i < opMZ.getSize(); i++) {
    if (tgtAllOpponent || opMZ.getMinion(i)->isTargetable()) {
      addTarget(opMZ.getMinion(i));
    }
  }

  for (auto &target: targets) { // targets need to have a interface for reacting to effects
    target->react(*this);
  }
}


// wait.. this is not good ... banish should only have one effect, not two
