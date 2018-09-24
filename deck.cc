#include "deck.h"

#include <string>
#include <memory>
#include <utility>
#include <iostream>

#include <sstream>
#include <stdexcept>

// for shuffling
#include <algorithm>
#include <random>
using namespace std;

Deck::~Deck() {}

void Deck::addCard(Card *card) {
  CardContainer::addCard(card);
}

void Deck::transferCard(CardContainer &other) {
  Card *top = cards.back();
  cards.pop_back();
  try {
    other.addCard(top);
  } catch(runtime_error container_full) {
    cout << container_full.what() << endl;
    delete top;
  }
}

void Deck::transferCard(CardContainer &hand, int i) {
  // does nothing (for now)
  // since we don't usually allow for random access into the deck
}

void Deck::shuffle() {
  std::random_shuffle(cards.begin(), cards.end());
  // shuffles the deck
}
