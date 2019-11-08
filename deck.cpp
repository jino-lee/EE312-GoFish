/* Member function definitions for Deck class
 * Created by Jin Lee & Andy Wu
 * 11/7/2019
*/

#include "deck.h"
#include "card.h"

using namespace std;

//Default constructor 
//creates a sorted deck
Deck()
{
   myIndex = 0; 
   
   for (int i = 0; i < 13; i++)
   {
      myCards[myIndex] = Card(i, spades);
      myIndex = myIndex + 1;       
   }
   //repeat for remaing suits?
}

//shuffle the deck, all 52 cards present
void shuffle()
{

}

//get a card
//after 52 are dealt, fail
Card dealCard()
{

}

//# of cards left in the deck
int size() const
{

}
