#include "player.h"
#include "minion.h"
#include "spell.h"
#include "ritual.h"
#include "playerstatmodder.h"
// remove this later, just for testing player's methods are getting called
#include <iostream>

using namespace std;

Player::Player(string name, string deckfile):
  name{name}, deckfile{deckfile} {
}

string Player::getName() const {
  return name;
}

string Player::getDeckfile() const {
  return deckfile;
}

int Player::getHP() const {
  return hp;
}

Minion *Player::getMinion(int i) {
  return minionzone.getMinion(i);
}

Ritual *Player::getRitual() {
  return ritualzone.getRitual();
}

Hand &Player::getHand() {
  return hand;
}

MinionZone &Player::getMinionZone() {
  return minionzone;
}

RitualZone &Player::getRitualZone() {
  return ritualzone;
}

DiscardPile &Player::getDiscardPile() {
  return discardpile;
}

void Player::play(int i) {
  cout << name << " " << i << endl;
  // could be a ritual, minion, spell, or enchantment
  
  hand.play(i); // play the card in hand
}

void Player::play(int i, Player &p, int t) { // bad design but im tired
  if (t >= 0 && t < minionzone.getCapacity()) {
    p.getMinion(t)->makeTargetable();
  } else {
    p.getRitual()->makeTargetable();
  }
  hand.play(i);
}

void Player::addCardToDeck(Card *card) {
  deck.addCard(card);
}

void Player::sendCardToGrave(int i) {
  minionzone.transferCard(graveyard, i);
}

void Player::sendRitualToDiscard() {
  ritualzone.transferCard(discardpile);
}

void Player::attack(Player &other, int i) {
  getMinion(i)->attack(other);
}

void Player::attack(Player &other, int i, int j) {
  getMinion(i)->attack(other.getMinion(j));
  
  // FIXLIST #3 -- this might be a logical error
  // with on death triggers later..
  // we are making the player responsible for moving the
  // card to the graveyard.
  // maybe having cards moving themselves between
  // respective zones would be okay
  // would have to test out later

  // respect apnap order
  /*
  if (getMinion(i)->isDead()) {
    cout << "your minion died!" << endl;
    sendCardToGrave(i);
  }
  if (other.getMinion(j)->isDead()) {
    cout << "your opponents minion died!" << endl;
    other.sendCardToGrave(j);
    } // if it's dead, move it to the graveyard*/
}

void Player::takeDamage(int dmg) {
  hp -= dmg;
  // maybe check for player death here?
}

void Player::draw() {
  deck.transferCard(hand);
}

void Player::shuffleDeck() {
  deck.shuffle();
}

// remove this later, just to make sure it works 
void Player::showHand() {
  cout << "displaying the hand" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;  
  for (auto i: hand.getContents()) {
    cout << i->getName() << ", Cost: " << i->getCost() << endl;
  }
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
}

void Player::showDeck() {
  cout << "displaying the deck" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
  for (auto i: deck.getContents()) {
    cout << i->getName() << ", Cost: " << i->getCost() << endl;
  }
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
}

void Player::showMinionZone() {
  cout << "displaying the minionzone" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
  for (auto i: minionzone.getContents()) {
    cout << i->getName() << ", Cost: " << i->getCost() << endl;
  }
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
}

void Player::showGraveyard() {
  cout << "displaying the graveyard" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
  for (auto i: graveyard.getContents()) {
    cout << i->getName() << ", Cost: " << i->getCost() << endl;
  }
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
}

void Player::showRitualZone() {
  cout << "displaying the ritualzone" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
  for (auto i: ritualzone.getContents()) {
    cout << i->getName() << ", Cost: " << i->getCost() << endl;
  }
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
}

void Player::showDiscardPile() {
  cout << "displaying the discardpile" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
  for (auto i: discardpile.getContents()) {
    cout << i->getName() << ", Cost: " << i->getCost() << endl;
  }
  cout << "~~~~~~~~~~~~~~~~~~~" << endl;
} 

void Player::react(PlayerStatModder &effect) {
  takeDamage(effect.getHp());
  //lowerMagic()? later
}
 

