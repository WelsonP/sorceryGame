#include "cardcontainer.h"
#include <vector>

using namespace std;

void CardContainer::addCard(Card *cardptr) {
  cards.emplace_back(cardptr);
}

// this should be standard across all card containers
// when there is no target card specified, the card
// will usually be the top of the deck
// i.e. drawing from deck to hand
// i.e. summoning from graveyard to minionzone

// these should be pure virtual?
void CardContainer::transferCard(CardContainer &target) {
  Card *top = cards.back();
  cards.pop_back();
  target.addCard(top);
}

void CardContainer::transferCard(CardContainer &other, int index) {
  Card *card = cards[index];
  cards.erase(cards.begin() + index);
  other.addCard(card);
}

vector<Card *> &CardContainer::getContents() {
  return cards;
}

CardContainer::~CardContainer() {
  for (auto cardptr: cards) delete cardptr;
}

Card *CardContainer::getCard(int i) {
  return cards[i];
}

int CardContainer::getSize() {
  return cards.size();
}
