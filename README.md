Hearthstone-esque card game with over 20 different cards. To run, download the project and call ```make```. Then run ./sorcery. The first two inputs should be the names of the two players. 

# Command Line Arguments #
```-deck1 filename1``` and/or ```-deck2 filename2``` -- Specifies that player 1's deck will be supplied in filename1, and/or player 2's deck will be supplied in filename2. Not specifying which decks to use will make the players default to default.deck.


# Commands #
```help``` -- Displays help message
```end``` -- End the current s turn.
          ``` quit ``` -- End the game.
          ```attack minion``` other-minion -- Orders minion to attack other-minion.
          ```attack minion``` -- Orders minion to attack the opponent.
          ```play card [target-player target-card]``` -- Play card, optionally targeting target-card owned by target-player.
          ```use minion [target-player target-card]``` -- Use a special ability, optionally targeting target-card owned by target-player.
          ```inspect minion``` -- View a card and all enchantments on that minion.
          ```hand``` -- Describe all cards in your hand.
          ```board``` -- Describe all cards on the board.

