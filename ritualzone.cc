#include "ritualzone.h"
#include "ritual.h"

Ritual *RitualZone::getRitual() {
  return static_cast<Ritual *>(getCard(0));
}

void RitualZone::addCard(Card *card) {
  if (!isFull()) { // not full <=> empty 
    CardContainer::addCard(card);
    ++size;
  } else {
    // it IS full
    //move to the discard pile, and decrement the size
    
    // by default, replace the last ritual with this one
    // Card *old = cards.back(); /// old ritual
      // cards.pop_back();
    getRitual()->die(); // ?
    CardContainer::addCard(card);
    // delete old; // delETES ritual
    // move ritual to the discard pile
  }

  // need to make a distinction between EMPTY, not full, and full 
}

// do nothing, rituals don't get transferred
void RitualZone::transferCard(CardContainer &other) {
  if (isFull()) {
    CardContainer::transferCard(other);
    --size; // updates ritual zone size accurately now
  } // throw an exception here
}

void RitualZone::transferCard(CardContainer &other, int i) {
}


bool RitualZone::isFull() const {
  return size >= capacity;
}
