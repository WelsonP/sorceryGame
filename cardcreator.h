#ifndef __CARDCREATOR__
#define __CARDCREATOR__
#include <map>

class Card;
class Player;
class CardCreator {
  std::map<std::string, std::string> cardMap;
 public:
  CardCreator();
  void createCardMap(std::string fname);
  void initDeck(Player &me, Player &opponent, std::string deckfile);
  Card *createCard(Player &me, Player &opponent, std::string);

  std::string test(std::string key);
};
#endif
