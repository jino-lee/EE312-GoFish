final: card_demo.o card.o
	g++ -std=c++11 -o test card_demo.o card.o
demo: card_demo.cpp card.h
	g++ -std=c++11 card_demo.cpp
card: card.cpp card.h
	g++ -std=c++11 card.cpp
