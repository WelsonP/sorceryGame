#include "card.h"
#include <string>
using namespace std;

Card::Card(string name, int cost): name{name}, cost{cost} { }

string Card::getName() const {
  return name;
}

void Card::lowerCost(int amount) {
  cost = (cost - amount <= 0) ? 0 : cost - amount;
}

int Card::getCost() const {
  return cost;
}

Card::~Card() { }

void Card::setOwner(Player *newOwner) {
  owner = newOwner;
}

