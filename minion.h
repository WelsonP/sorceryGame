#ifndef __MINION__
#define __MINION__
#include "card.h"
#include "player.h"
#include "target.h"

 // for now the unique ptr needs this
#include <memory>
class Ability;
class MinionStatModder;
class Killer;

class Minion : public Card, public Target {
  int atk, def, action;
  // std::map<Trigger, Effect>;
  //  std::unique_ptr<Ability *> ability;
 public:
  int getAtk() const;
  void attack(Player &); // attack a player

  void attack(Minion *); // attack a minion
  void lowerAtk(int amount);
  void lowerDef(int amount);
  void lowerAction(int amount);
  bool isDead();
  void checkDeath();
  virtual ~Minion() = 0;
  void play(int) override; // overrides the play from Card
  
  Minion(std::string name, int cost, int atk, int def, int action);
  void react(MinionStatModder &effect); 
  void react(Killer &killerEffect) override;
};
#endif
