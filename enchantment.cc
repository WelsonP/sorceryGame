#include "enchantment.h"

// remove later
#include <iostream>
using namespace std;

Enchantment::Enchantment(string name, int cost): Card{name, cost} { }

void Enchantment::play(int i) {
  cout << "enchantment called" << endl;
}
