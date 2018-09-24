#include "spell.h"
using namespace std;

Spell::Spell(std::string name, int cost): Card{name, cost} { }

void Spell::play(int i) {
  owner->getHand().transferCard(owner->getDiscardPile(), i);
  activateEffects();
}

/*
void Spell::play(Card *tgt) {
  cout << "targeted spell played" << endl;
  owner->getHand().transferCard(owner->getDiscardPile(), i);
  activateEffects();
} // how to incorporate targetting?
*/
void Spell::addEffect(Effect *effect) {
  effects.emplace_back(effect);
}

void Spell::activateEffects() {
  for (auto effect: effects) {
    effect->activate();
  }
}

Spell::~Spell() {
  for (auto effect: effects) {
    delete effect;
  }
}
