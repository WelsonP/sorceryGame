#include "minionstatmodder.h"
#include "minion.h"
#include "minionzone.h"
#include <iostream>
using namespace std;

MinionStatModder::MinionStatModder(int cost, int atk, int def, int action, MinionZone &ally, MinionZone &opponent,
				   bool tgtAllAlly, bool tgtAllOpponent):
  cost{cost}, atk{atk}, def{def}, action{action}, ally{ally}, opponent{opponent},
  tgtAllAlly{tgtAllAlly}, tgtAllOpponent{tgtAllOpponent} {} // tgts single targey might not be needed

int MinionStatModder::getCost() const {
  return cost;
}

int MinionStatModder::getAtk() const {
  return atk;
}

int MinionStatModder::getDef() const {
  return def;
}

int MinionStatModder::getAction() const {
  return action;
}

void MinionStatModder::addTarget(Minion *newTarget) {
  targets.emplace_back(newTarget);
}

void MinionStatModder::activate() {
  for (int i = 0; i < ally.getSize(); i++) {
    if (tgtAllAlly || ally.getMinion(i)->isTargetable()) {
      addTarget(ally.getMinion(i));
    }
  }
  for (int i = 0; i < opponent.getSize(); i++) {
    if (tgtAllOpponent || opponent.getMinion(i)->isTargetable()) { // sets i up
      addTarget(opponent.getMinion(i));
    }
  }
  
  for(auto &minion: targets) {
    minion->react(*this); // reacting makes it not targetable 
  }
}
