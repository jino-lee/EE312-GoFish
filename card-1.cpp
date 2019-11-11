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

//return string version (e.g. Ac)
string Card::toString() const
{
   return rankString(myRank) + suitString(mySuit);
}

//true if suit same as c
bool Card::sameSuitAs(const Card& c) const
{
    return (mySuit == c.mySuit);
}

//returns rank
int Card::getRank() const
{
    return myRank;
}

//returns suit ("s", "h", "d", c")
string Card::suitString(Suit s) const
{
   string suit_s;

   switch (s) 
   {
      case spades: suit_s = "s";
                   break;
      case hearts: suit_s = "h";
                   break;
      case diamonds: suit_s = "d";
                     break;
      case  clubs: suit_s = "c"; 
                   break;
   }
   return suit_s;
}

//returns rank ("A", "2", ... , "K")
string Card::rankString(int r) const
{
   string rank_s; 
    
   switch (r)
   {
      case 1: rank_s = "A"; break;
      case 2: rank_s = "2"; break;
      case 3: rank_s = "3"; break;
      case 4: rank_s = "4"; break;
      case 5: rank_s = "5"; break;
      case 6: rank_s = "6"; break;
      case 7: rank_s = "7"; break;
      case 8: rank_s = "8"; break;
      case 9: rank_s = "9"; break;
      case 10: rank_s = "10"; break;
      case 11: rank_s = "J"; break;
      case 12: rank_s = "Q"; break;
      case 13: rank_s = "K"; break;
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

ostream& operator << (ostream& out, const Card& c)
{
   out << c.toString();
   return out;   
}



