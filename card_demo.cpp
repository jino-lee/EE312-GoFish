// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


int main()
{
   Card _As = Card();
   cout << _As.rankString(1) << endl;
   cout << _As.rankString(5) << endl;
   cout << _As.rankString(10) << endl;
   cout << _As.rankString(11) << endl;
   cout << _As.rankString(12) << endl;
   cout << _As.rankString(13) << endl;
}
/*
int main( )
{
    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
*/  
