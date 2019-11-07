/* Memeber function definitions for Card class
 * Created by Jin Lee & Andy Wu
 * EE 312
 * 11/5/2019
*/

#include "card.h"
#include <iostream>
#include <stdlib.h>

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
    return "suitString";
}

string Card::rankString(int r) const
{
    return "rankString";  
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



