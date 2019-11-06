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

   switch (myRank)
   {
      case 1:	rank_s = "A";
 	    	break;	
      case 11: 	rank_s = "J";
   	      	break;
      case 12: 	rank_s = "Q";
		break;
      case 13:  rank_s = "K";
		break;
      default:	itoa(myRank, &rank_s, 10);
   		break;
   }
   
   switch (mySuit)
   {
      case Enum::spades:   suit_s = "s";
                   	   break;
      case Enum::hearts:   suit_s = "h";
         	   	   break;
      case Enum::diamonds: suit_s = "d";
           	   	   break;
      case Enum::clubs:    suit_s = "c";
  		   	   break;
   
    return (rank_s + suit_s);        
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





