#ifndef __MINIONSTATMODDER__
#define __MINIONSTATMODDER__
#include "effect.h"
#include <vector>

class MinionZone;
class Minion;
class MinionStatModder final: public Effect {
  std::vector<Minion *> targets;
  int cost, atk, def, action;
  MinionZone &ally, &opponent;
  bool tgtAllAlly, tgtAllOpponent;
 public:
  int getCost() const;
  int getAtk() const;
  int getDef() const;
  int getAction() const;
  MinionStatModder(int cost, int atk, int def, int action, MinionZone &ally, MinionZone &opponent,
		   bool tgtAllAlly, bool tgtAllOpponent);
  void addTarget(Minion *newTarget);
  void activate() override;
};
#endif
