final: go_fish.o card.o deck.o player.o
	g++ -std=c++11 -o test go_fish.o card.o deck.o player.o
demo: go_fish.cpp card.h deck.h player.h
	g++ -std=c++11 go_fish.cpp
player: player.cpp player.h card.h
	g++ -std=c++11 player.cpp
deck: deck.cpp deck.h card.h
	g++ -std=c++11 deck.cpp
card: card.cpp card.h
	g++ -std=c++11 card.cpp
