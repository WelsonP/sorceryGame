#ifndef __RITUALZONE__
#define __RITUALZONE__
#include "cardcontainer.h"
#include "constants.h"

class Ritual;
class RitualZone: public CardContainer {
  int size = 0, capacity = RITUALZONE_CAPACITY;
 public:
  Ritual *getRitual();
  void addCard(Card *card) override;
  void transferCard(CardContainer &) override;
  void transferCard(CardContainer &, int) override;
  
  // Card *getRitual();
  bool isFull() const;
};
#endif
