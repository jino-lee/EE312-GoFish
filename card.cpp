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

string Card::toString()
{
   string suit_s;
   string rank_s; 
   
   itoa(rank_s, &rank_s, 10);
   
   return        
}

bool Card::sameSuitAs(const Card& c)
{
    return (mySuit == c.mySuit);
}

int Card::getRank()
{
    return myRank;
}

string Card::suitString(Suit s)
{

}

string Card::rankString(int r)
{

}

bool Card::operator == (const Card& rhs)
{
   return (myRank == rhs.myRank && mySuit == rhs.mySuit);
}

bool Card::operator != (const Card& rhs)
{
   return (myRank != rhs.myRank || mySuit != rhs.mySuit);
}





