#include "cardcreator.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "constants.h"
#include "concreteminion.h"
#include "spell.h"
#include "ritual.h"
#include "enchantment.h"
#include "minionstatmodder.h"
#include "playerstatmodder.h"
#include "ritualstatmodder.h"
#include "killer.h"
using namespace std;

void CardCreator::createCardMap(string fname) {
  ifstream file{fname};
  string cardName;
  string cardInfo;
  while (getline(file, cardName)) {
    getline(file, cardInfo);
    cardMap[cardName] = cardInfo;
  }
}

CardCreator::CardCreator() {
  createCardMap(CARD_LIST);
}

// do we need effects to be effect *'s? does stack work? or should we use unique_ptr for ownership?
Effect *make_effect(Player &me, Player &opponent, istream &in, string type) {
  if (type == "MinionStatModder") {
    int cost, atk, def, action;
    in >> cost >> atk >> def >> action;
    string rs;
    in >> rs;
    bool tgtAllAlly = (rs == "tgtAllAlly") ? true : false; // tgt all ally
    in >> rs;
    bool tgtAllEnemy = (rs == "tgtAllEnemy") ? true: false;
    
    MinionStatModder *effect = new MinionStatModder(cost, atk, def, action, me.getMinionZone(), opponent.getMinionZone(), tgtAllAlly, tgtAllEnemy);
    return effect;
  } else if (type == "RitualStatModder") {
    int charges, activationCost;
    in >> charges >> activationCost;
    RitualStatModder *effect = new RitualStatModder(charges, activationCost, me.getRitualZone(), opponent.getRitualZone());
    return effect;
  } else if (type == "Killer") {
    string rs;
    in >> rs;
    bool tgtAllAlly = (rs == "tgtAllAlly") ? true: false;
    in >> rs;
    bool tgtAllEnemy = (rs == "tgtAllEnemy") ? true: false;

    Killer *effect = new Killer(me.getMinionZone(), opponent.getMinionZone(),
				me.getRitualZone(), opponent.getRitualZone(), tgtAllAlly, tgtAllEnemy);
    return effect;
  }
  return nullptr; // temp, throw exception for bad file
}

string CardCreator::test(string key) {
  return cardMap[key];
}


Card *CardCreator::createCard(Player &me, Player &opponent, string name) { 
  istringstream ss(cardMap[name]);
  string type;
  int cost;
  ss >> type >> cost;
  
  if (type == "Minion") { // Name\nCost Atk Def Action
    int atk, def, action;
    ss >> atk;
    ss >> def;
    ss >> action;
    ConcreteMinion *cm = new ConcreteMinion(name, cost, atk, def, action);
    cm->setOwner(&me);
    return cm;
  } else if (type == "Spell") { // Name\nCost
    Spell *s = new Spell(name, cost);
    string effectType;
    while (ss >> effectType) { // only supports one line reading at a time
      s->addEffect(make_effect(me, opponent, ss, effectType));
    }
    s->setOwner(&me);
    return s;
  } else if (type == "Ritual") { // Name\nCost
    int charges, activationCost;
    ss >> charges >> activationCost;
    Ritual *r = new Ritual(name, cost, charges, activationCost);
    r->setOwner(&me);
    return r;
  } else if (type == "Enchantment") { // Name \nCost
    Enchantment *e = new Enchantment(name, cost);
    e->setOwner(&me);
    return e;
  }
    // invalid file format, throw exception or something here?
  return nullptr;
    // FOR NOW TO AVOID END OF NON VOID FUNCTION CONtrol flow error 
}

void CardCreator::initDeck(Player &me, Player &opponent, string deckfile) {
  ifstream file{deckfile};
  string name;
  while (getline(file, name)) { // default.deck
    me.addCardToDeck(createCard(me, opponent, name));
  }
  me.shuffleDeck();
}
