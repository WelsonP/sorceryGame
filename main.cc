#include "player.h"
#include "board.h"
#include "game.h"

#include <random>

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[]) {
  // seed the random number generator?
  Game g;
  g.start(argc, argv);  
}
