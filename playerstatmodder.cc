#include "playerstatmodder.h"
#include "player.h"
using namespace std;

PlayerStatModder::PlayerStatModder(int hp, Player &ally, Player &opponent):
  hp{hp}, ally{ally}, opponent{opponent} { }

int PlayerStatModder::getHp() const {
  return hp;
}

void PlayerStatModder::addTarget(Player *newPlayer) {
  targets.emplace_back(newPlayer);
}

void PlayerStatModder::activate() {
  if (true) {
    addTarget(&ally);
  }
  if (true) {
    addTarget(&opponent);
  }
  for (auto x: targets) {
    x->react(*this);
  }
}

