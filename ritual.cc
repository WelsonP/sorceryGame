#include "ritual.h"
#include "player.h"
#include "ritualstatmodder.h"
#include "target.h"

using namespace std;

Ritual::Ritual(string name, int cost, int charges, int activationCost):
  Card{name, cost}, Target{}, charges{charges}, activationCost{activationCost} { }

void Ritual::lowerCharges(int amount) {
  charges = (charges - amount <= 0) ? 0 : charges - amount;
}

void Ritual::lowerActivationCost(int amount) {
  activationCost = (activationCost - amount <= 0) ? 0 : activationCost - amount;
}

void Ritual::play(int i) {
  owner->getHand().transferCard(owner->getRitualZone(), i);
}
void Ritual::react(RitualStatModder &effect) {
  lowerCharges(effect.getCharges());
  lowerActivationCost(effect.getActivationCost());
  makeUntargetable();
}

void Ritual::react(Killer &killerEffect) {
  die();
}

void Ritual::die() {
  owner->sendRitualToDiscard();
}
