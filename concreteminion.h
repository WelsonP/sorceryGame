#ifndef __CONCRETEMINION__
#define __CONCRETEMINION__
#include "minion.h"

class ConcreteMinion final: public Minion {
 public:
  /*  void attack(int dmg) override;
  void attack(int, int) override;
  void getAttacked() override;
  void die() override;*/
  // TODO const, param names

  //void notify(Subject &whoFrom) override;
  
  ConcreteMinion(std::string name, int cost, int atk, int def, int action);
  //How do we construct minions, we need some way of giving them their effects
  // maybe we should have a text file for list of all possible cards/minions, and effects as well, then iterate
  // through to add effects? for now only simple params
  // do we need big 5?
};
#endif
