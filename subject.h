#ifndef __SUBJECT__
#define __SUBJECT__
#include <vector>

class Observer;

// for now try not using templates, if we absolutely have to we can
class Subject {
  std::vector<Observer *> observers; // is using Observer * okay here?
  // do we need protected: void setState?()
 public:
  void attach(Observer *o);
  void notifyObservers();
};
#endif
