#include "hand.h"
#include <stdexcept>
#include <iostream>
using namespace std;

bool Hand::isFull() {
  return size >= capacity;
}

void Hand::addCard(Card *card) {
  if (!isFull()) {
    CardContainer::addCard(card);
    ++size;
  } else {
    throw runtime_error{"hand was full"};
  }
    
  // do nothing if the hand is full
}

void Hand::play(int i) {
  cards[i]->play(i); // you don't know what card type it is,
  size--;// let the card figure it out
}

/*
void Hand::play(int i, Card *tgt) {
  //  cards[i]->play(tgt); // play on the target
  // this only makes sense in the context of
  // enchantments, and spells
}
*/

void Hand::transferCard(CardContainer &other) {
  // move it into the minion zone or ritual zone
  // or graveyard etc...  
}

void Hand::transferCard(CardContainer &other, int index) {
  // something special could happen here,
  // we might have to make sure that the other thing isn't full
  Card *card = cards[index];
  cards.erase(cards.begin() + index);
  try {
    other.addCard(card);
  } catch (runtime_error container_full) {
    cout << container_full.what() << endl;
    // keep your card
    cards.insert(cards.begin() + index, card);
  }
  // this should be the general case as well actually
}

Hand::~Hand() {}
