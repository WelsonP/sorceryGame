#include "minionzone.h"
#include <stdexcept>
#include <iostream>
#include "minion.h"
using namespace std;

Minion *MinionZone::getMinion(int i) {
  return static_cast<Minion *>(getCard(i));
}

int MinionZone::getCapacity() const {
  return capacity;
}

void MinionZone::addCard(Card *card) {
  //if (size < capacity)

  if (!isFull()) {
    CardContainer::addCard(card);
    ++size;
  } else {
    throw runtime_error{"minionzone was full"} ;
  }
}

void MinionZone::transferCard(CardContainer &other) {
  // no real use
}

void MinionZone::transferCard(CardContainer &other, int index) {
  // move minion at index back to hand,
  // 
  Card *card = cards[index];
  cards.erase(cards.begin() + index);
  try {
    other.addCard(card);
    size--;
  } catch (runtime_error container_full) {
    cout << container_full.what() << endl;
    delete card; // burn your minion
  }
}

int MinionZone::onField() const {
  return size;
}

bool MinionZone:: isFull() const {
  return size >= capacity;
}
