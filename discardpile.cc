#include "discardpile.h"
#include <stdexcept>
#include <iostream>
using namespace std;

// i just copied graveyard into here basically, make changes if needed

void DiscardPile::addCard(Card *card) {
  CardContainer::addCard(card);
}

void DiscardPile::transferCard(CardContainer &other) {
  Card *top = cards.back();
  cards.pop_back();
  try {
  } catch (runtime_error container_full) {
    cout << container_full.what() << endl;
    // keep it or delete it
    // i say keep
    addCard(top);
  }
}

void DiscardPile::transferCard(CardContainer &other, int i) {
  // does nothing for now, since you don't usually llow random access into graveyards
}
