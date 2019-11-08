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
   Card _As = Card();	//ace of spaces
   Card _As2 = Card(1, Card::spades); 
   Card _Jd = Card(11, Card::diamonds);
   Card _Ad = Card(1, Card::diamonds);

   cout << "Testing toString: " << endl;
   cout << "As: " << _As.toString() << endl;
   cout << "As2: " << _As2.toString() << endl;
   cout << "Jd: " << _Jd.toString() << endl;
 
   cout << "Testing sameSuitAs: " << endl;
   if ( _As.sameSuitAs(_As2))
   {
      cout << "_As == _As2" << endl;
   }
   else 
   {
      cout << "_As != _As2" << endl;
   }
  
   if (_As2.sameSuitAs(_Jd))
   {
      cout << "_As2 == _Jd" << endl;
   }
   else 
   {
      cout << "_As2 != _Jd" << endl;
   }
   
   cout << "Testing overriden == / !=" << endl;
   if (_As == _As2)
   {
      cout << "_As == _As2" << endl;
   }
   if (_As != _Jd) 
   {
      cout << "_As != _Jd" << endl;
   }  

   cout << "Testing overridden <<" << endl;
   cout << _As << endl;
   cout << _As2 << endl;
   cout << _Jd << endl;
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
