/* Memeber function definitions for Card class
 * Created by Jin Lee & Andy Wu
 * EE 312
 * 11/5/2019
*/

#include "card.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//Default constructor
//Ace of spades
Card::Card()
{
   myRank = 1;
   mySuit = Card::spades;
}

//Constructor with rank and suit
Card::Card(int rank, Suit s)
{
   myRank = rank;
   mySuit = s;
}

string Card::toString() const
{
   string card_s;     
   return "toString";
}

bool Card::sameSuitAs(const Card& c) const
{
    return (mySuit == c.mySuit);
}

int Card::getRank() const
{
    return myRank;
}

string Card::suitString(Suit s) const
{
   string suit_s;

   switch (s) 
   {
      case suit(0): suit_s = "s";
           break;
      case hearts(1); suit_s = "h";
           break;
      case diamond(2) suit_s = "d";
           break;
      case  clubs(3): suit_s = "c"; 
           break;
   }
   return suit_s;
}

string Card::rankString(int r) const
{
   string rank_s; 
    
   switch (r)
   {
      case 1: rank_s = "A";
              break;
      case 11: rank_s = "J";
               break;
      case 12: rank_s = "Q";
    	       break;
      case 13: rank_s = "K";
               break;
      default: rank_s = std::to_string(r);
   }
    
   return rank_s;  
}

bool Card::operator == (const Card& rhs) const
{
   return (myRank == rhs.myRank && mySuit == rhs.mySuit);
}

bool Card::operator != (const Card& rhs) const
{
   return (myRank != rhs.myRank || mySuit != rhs.mySuit);
}

ostream& operator << (ostream& out, const Card& c) {
   return out;
}



