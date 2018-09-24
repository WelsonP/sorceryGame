#ifndef __MINIONKILLER__
#define __MINIONKILLER__
#include "effect.h"
#include <vector>

class MinionZone;
class RitualZone;
class Target;

class Killer final: public Effect {
  std::vector<Target *> targets;
  MinionZone &allyMZ, &opMZ;
  RitualZone &allyRZ, &opRZ;
  bool tgtAllAlly, tgtAllOpponent;
 public:
  Killer(MinionZone &allyMZ, MinionZone &opMZ,
	 RitualZone &allyRZ, RitualZone &opRZ, bool tgtAllAlly, bool tgtAllOpponent);
  void addTarget(Target *newTarget);
  void activate() override;
};

#endif
