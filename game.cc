
#include "game.h"
#include "board.h"
#include "constants.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <memory>

using namespace std;

void Game::start(int argc, const char *argv[]) {
  // srand(time(NULL));
  string p1_name, p2_name;
  
  string deck1 = "", deck2 = "";
  if (argc >= 2) {
    for (int i = 1; i < argc; i++) {
      string arg = argv[i];
      if (arg == "-init") {
	string fname = argv[i+1];
	ifstream initFile{fname};
	init(initFile);
	play(initFile);
      } else if (arg == "-deck1") {
	deck1 = argv[i+1];
      } else if (arg == "-deck2") {
	deck2 = argv[i+1];
      } else if (arg == "-testing") {
	testing = true;
      } else if (arg == "-graphics") {
	graphics = true;
      }
    }
  }

  if (deck1 == "") {
    p1_deck = DEFAULT_DECK_PATH;
  } else {
    p1_deck = deck1;
  }
  if (deck2 == "") {
    p2_deck = DEFAULT_DECK_PATH;
  } else {
    p2_deck = deck2;
  }
  init(cin);
  play(cin);
}

bool Game::inIsReadable(istream &in) {
  return !in.eof();
  // hasn't reached eof
}

void Game::init(istream &in) {
  string str;
  while (p1_name == "" || p2_name == "") {
    if (inIsReadable(in)) {
      getline(in, str);

      if (p1_name == "") {
	p1_name = str;
      }
      else if (p2_name == "") {
	p2_name = str;
	initBoard();
	initPlayerHands();
      }
    } else {
      break; // in is no longer readable
    }
  }
}

void Game::initBoard() {
  board = make_unique<Board>(p1_name, p2_name, p1_deck, p2_deck);
}

void Game::initPlayerHands() {
  cout << "initializing player hands: " << p1_name << ", " << p2_name << endl;
  for (int i = 0; i < 5; ++i) {
    board->getActivePlayer().draw();
    board->getInactivePlayer().draw();
  }
}

void Game::play(istream &in) {
  string str;  
  while (!isOver()) {
    // check to make sure the stream is still readable
    if (inIsReadable(in)) {
      getline(in, str);

      istringstream iss(str);
      string s;
      while (iss >> s) {
	if (s == "play") {
	  int i, p; // there are gonna be used later for spells
	  char t;
	  iss >> i;
	  if (iss >> p >> t) {
	    if (p == 1) {
	      board->getActivePlayer().play(i-1, board->getPlayer1(), t-'0'-1);
	    }
	    else if (p == 2) {
	      board->getActivePlayer().play(i-1, board->getPlayer2(), t-'0'-1);
	    }
	  } else {
	    board->getActivePlayer().play(i-1);
	  }
	}
	else if (s == "hand") {
	  board->getActivePlayer().showHand();
	}
	else if (s == "deck") {
	  board->getActivePlayer().showDeck();
	}
	else if (s == "minionzone") {
	  board->getActivePlayer().showMinionZone();
	}
	else if (s == "graveyard") {
	  board->getActivePlayer().showGraveyard();
	}
	else if (s == "rituals") {
	  board->getActivePlayer().showRitualZone(); // 
	}
	else if (s == "discardpile") { 
	  board->getActivePlayer().showDiscardPile();
	}
	else if (s == "attack") {
	  int i, j;
	  iss >> i;
	  if (iss >> j) {
	    // minion attacks enemy minion, pass it the other minion?
	    board->getActivePlayer().attack(board->getInactivePlayer(), i-1, j-1);
	  } else {
	    board->getActivePlayer().attack(board->getInactivePlayer(), i-1);
	  }
	}
	else if (s == "hp") {
	  cout << board->getActivePlayer().getHP() << endl;
	}
	else if (s == "end") {
	  board->changeTurn();
	  // should board change the state?
	  // drawing from deck here
	  board->getActivePlayer().draw();
	}
      }
    } else {
      break;
    }
  }
  // check this later
  if (isOver()) {
    cout << getWinner().getName() << " wins!" << endl;
  }
}

bool Game::isOver() { // implement this when HP is introduced
  if (p1_name == "" || p2_name == "") return false;
  return board->getActivePlayer().getHP() <= 0 || board->getInactivePlayer().getHP() <= 0;
}

Player &Game::getWinner() {
  if (board->getActivePlayer().getHP() <= 0)
    return board->getInactivePlayer();
  return board->getActivePlayer();
}
