#ifndef __PLAYERSTATMODDER__
#define __PLAYERSTATMODDER__
#include "effect.h"
#include <vector>

class Player;
class PlayerStatModder final: public Effect {
  std::vector<Player *> targets;
  int hp; // magic later?
  Player &ally, &opponent;
 public:
  int getHp() const;
  // int getMagic() const;
  PlayerStatModder(int hp,/* int magic,*/ Player &ally, Player &opponent);
  void addTarget(Player *newPlayer);
  void activate() override;
};
#endif
