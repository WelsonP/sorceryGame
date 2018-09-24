CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Werror -MMD -Werror=vla
EXEC = main
OBJECTS = main.o board.o deck.o hand.o player.o game.o card.o cardcontainer.o minion.o concreteminion.o ability.o effect.o spell.o enchantment.o ritual.o minionzone.o graveyard.o ritualzone.o constants.o discardpile.o cardcreator.o minionstatmodder.o playerstatmodder.o ritualstatmodder.o killer.o target.o
DEPENDS = ${OBJECTS:.o=.d} 

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
