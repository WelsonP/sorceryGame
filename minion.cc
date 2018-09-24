#include "minion.h"
#include "minionstatmodder.h"
#include "target.h"
#include "killer.h"
using namespace std;

Minion::Minion(string name, int cost, int atk, int def, int action):
  Card{name, cost}, Target{}, atk{atk}, def{def}, action{action} { }

void Minion::attack(Player &opponent) {
  opponent.takeDamage(atk);
}

void Minion::attack(Minion *other) {
  other->lowerDef(atk);
  lowerDef(other->getAtk());
  checkDeath();
}

void Minion::lowerAtk(int amount) {
  atk = (atk - amount <= 0) ? 0 : atk - amount;
}

void Minion::lowerDef(int amount) {
  def = (def - amount <= 0) ? 0 : def - amount;
  checkDeath();
}

void Minion::lowerAction(int amount) {
  action = (action - amount <= 0) ? 0 : action - amount; 
}

bool Minion::isDead() {
  return def == 0;
}

void Minion::checkDeath() {
  if (isDead()) {
    int index;
    for (int i = 0; i < owner->getMinionZone().getSize(); i++) {
      if (owner->getMinion(i) == this) {
	index = i;
      }
    }
    owner->sendCardToGrave(index);
    // notify observers of death, deathrattle will be a little weird if we do <trigger, effect> map for minion effects, might be an edge case?
  }
}

int Minion::getAtk() const {
  return atk;
}

void Minion::play(int i) {
  owner->getHand().transferCard(owner->getMinionZone(), i);
  // i being the index of this card
}

Minion::~Minion() { }

void Minion::react(MinionStatModder &effect) {
  lowerCost(effect.getCost());
  lowerAtk(effect.getAtk());
  lowerDef(effect.getDef());
  lowerAction(effect.getAction());
  makeUntargetable();
}

void Minion::react(Killer &effect) {
  lowerDef(def); // set your def to zero...
  makeUntargetable();
}
