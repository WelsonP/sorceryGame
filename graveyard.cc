#include "graveyard.h"
#include <stdexcept>
#include <iostream>
using namespace std;

void Graveyard::addCard(Card *card) {
  CardContainer::addCard(card);
}

void Graveyard::transferCard(CardContainer &other) {
  Card *top = cards.back();
  cards.pop_back();
  try {
    other.addCard(top);
  } catch (runtime_error container_full) {
    cout << container_full.what() << endl;
    // keep it or delete it?
    // i say keep
    addCard(top);
  }
}

void Graveyard::transferCard(CardContainer &other, int i) {
  // does nothing for now, since you don't usually allow random access into graveyards
}
