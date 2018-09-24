#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include <map>

#include "deck.h"
#include "hand.h"
#include "minionzone.h"
#include "graveyard.h"
#include "ritualzone.h"
#include "discardpile.h"

class Minion;
class Ritual;
class PlayerStatModder;

class Player { // does it inherit from anything?
  std::string name; // just have a simple string for now
  std::string deckfile;
  int hp = PLAYER_MAX_HP;
  
  Deck deck;
  Hand hand;
  MinionZone minionzone;
  Graveyard graveyard;
  RitualZone ritualzone;
  DiscardPile discardpile;

 public:
  Player(std::string name, std::string deckfile);
  std::string getName() const;
  std::string getDeckfile() const;
  int getHP() const;

  // getter methods
  Minion *getMinion(int); // return the minion at the index specified
  Ritual *getRitual();
  
  Hand &getHand();
  MinionZone &getMinionZone();
  RitualZone &getRitualZone(); // these getters aren't actually required
  DiscardPile &getDiscardPile();
  // could just do something similar to what was done for graveyard
  
  // what if i tied a card to a player instead?
  
  void play(int); // generally, play a card
  void play(int, Player &, int);
	    //index, 
	    // first int is your index, (in hand)
	    // second is target card...
  
  void attack(Player &, int); // for attacking the player
  void attack(Player &, int, int); // for attacking the minion
  // void attack(Card &, int) // maybe this should be used instead
  
  void takeDamage(int);
  
  // CardContainer related methods
  void draw(); // player draws a card from their deck
  void shuffleDeck();
  
  void addCardToDeck(Card *card);
  void sendCardToGrave(int i); // move a card to the grave after it's dead
  void sendRitualToDiscard();
  
  // testing methods
  void showHand();
  void showDeck();
  void showMinionZone();
  void showGraveyard();
  void showRitualZone();
  void showDiscardPile();

  // react methods
  void react(PlayerStatModder &effect);
};
#endif
