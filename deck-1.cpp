/* Member function definitions for Deck class
 * Created by Jin Lee & Andy Wu
 * 11/7/2019
*/

#include "deck.h"
#include "card.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

//Default constructor 
//creates a sorted deck
Deck::Deck()
{
   myIndex = 0; 
   srand(time(0)); //seed random number generator in constructor (seed only once per deck)
   
   //Initializes all cards in order (13 cards of spades, diamonds, clubs, then hearts)
   for (int i = 1; i <= 13; i++) {
      myCards[myIndex] = Card(i, Card::spades);
      myIndex = myIndex + 1;       
   }
   for (int i = 1; i <= 13; i++) {
      myCards[myIndex] = Card(i, Card::diamonds);
      myIndex = myIndex + 1;       
   }
   for (int i = 1; i <= 13; i++) {
      myCards[myIndex] = Card(i, Card::clubs);
      myIndex = myIndex + 1;       
   }
   for (int i = 1; i <= 13; i++) {
      myCards[myIndex] = Card(i, Card::hearts);
      myIndex = myIndex + 1;       
   }
   
   myIndex = myIndex - 1;//decrement to valid index (51)
}

//-----Shuffle-----
// shuffle the deck, ONLY if all 52 cards present
void Deck::shuffle()
{
   if (myIndex == 51) { // only shuffle if no cards have been dealt
      int index1, index2;
      Card temp;

      for (int i = 0; i < 104; i++) {
         // get two random index values between 0 - 51
         index1 = rand() % 52;
         index2 = rand() % 52;

         // swap cards at these indexes
         temp = myCards[index1];
         myCards[index1] = myCards[index2];
         myCards[index2] = temp;
      }
   }
}

//-----dealCard-----
// Get a card from the deck
// Pre-condition: MAKE SURE DECK IS NOT EMPTY (check d.size() != 0) before calling this function
Card Deck::dealCard()
{
   Card topCard;
   
   if (myIndex >= 0) {
      topCard = myCards[myIndex];
      myIndex--;
   }
   else {
      topCard = Card(); //default As, fail
   }

   return topCard;
}

//-----size-----
//# of cards left in the deck
int Deck::size() const
{
   return (myIndex + 1);
}
