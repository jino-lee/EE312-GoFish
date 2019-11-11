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
   cout << endl << "Now testing Player class methods..." << endl;
   Player Andy("Andy");
   Player Jin("Jin");
   Card card1;
   Card card2;
   Card chosenCard;
   Card removedCard;
   Card drawnCard;
   int chosenCardRank;
   cout << "First player's name is: " << Andy.getName() << endl;
   cout << "Second player's name is: " << Jin.getName() << endl;

   // Deal 7 cards to each player
   cout << "Dealing cards..." << endl;
   for (int i = 0; i < 7; i++) {
      Andy.addCard(d.dealCard());
      Jin.addCard(d.dealCard());
   }
   cout << "Andy's hand is: " << Andy.showHand() << endl;
   cout << "Jin's hand is: " << Jin.showHand() << endl;

   // checkHandForBook() for any pairs after dealing
   while (Andy.checkHandForBook(card1, card2) == true) {
      Andy.bookCards(card1, card2);
      cout << "Andy books " << card1.toString() << " and " << card2.toString() << endl;
   }
   while (Jin.checkHandForBook(card1, card2) == true) {
      Jin.bookCards(card1, card2);
      cout << "Jin books " << card1.toString() << " and " << card2.toString() << endl;
   }
   cout << endl;


   // Andy's 1st turn...
   cout << "Andy: Do you have a " << Andy.chooseCardFromHand().rankString(Andy.chooseCardFromHand().getRank()) << "?" << endl;
   chosenCard = Andy.chooseCardFromHand();
   if (Jin.rankInHand(chosenCard) == true) {
      cout << "Jin: Yes. I have a " << chosenCard.rankString(chosenCard.getRank()) << endl;

      while (Jin.rankInHand(chosenCard) == true) { // keep checking for specified rank of chosen card in opponent's hand
         removedCard = Jin.removeCardFromHand(chosenCard);
         Andy.addCard(removedCard);
         cout << "Andy takes " << removedCard.toString() << " from Jin." << endl;
         while (Andy.checkHandForBook(card1, card2) == true) {
            Andy.bookCards(card1, card2);
            cout << "Andy books " << card1.toString() << " and " << card2.toString() << endl;
         }
      }
      cout << endl;
   }
   else {
      cout << "Jin: Go Fish." << endl;
      if (d.size() > 0) { // as long as deck is not empty
         drawnCard = d.dealCard();
      }
      else {
         cout << "GAME OVER! (Deck is empty)." << endl;
      }
      cout << "Andy draws a " << drawnCard.toString() << endl;
      Andy.addCard(drawnCard);
      while (Andy.checkHandForBook(card1, card2) == true) {
            Andy.bookCards(card1, card2);
            cout << "Andy books " << card1.toString() << " and " << card2.toString() << endl;
      }
      cout << endl;
   }

   cout << "Game updates after Andy's turn..." << endl;
   cout << "Andy's hand is: " << Andy.showHand() << endl;
   cout << "Andy's books are: " << Andy.showBooks() << endl;
   cout << "Jin's hand is: " << Jin.showHand() << endl;
   cout << "Jin's books are: " << Jin.showBooks() << endl;
   cout << endl;


// Jin's first turn
   chosenCard = Jin.chooseCardFromHand();
   cout << "Jin: Do you have a " << chosenCard.rankString(chosenCard.getRank()) << "?" << endl;
   if (Andy.rankInHand(chosenCard) == true) {
      cout << "Andy: Yes. I have a " << chosenCard.rankString(chosenCard.getRank()) << endl;

      while (Andy.rankInHand(chosenCard) == true) { // keep checking if Andy's hand has specified rank
         removedCard = Andy.removeCardFromHand(chosenCard);
         Jin.addCard(removedCard);
         cout << "Jin takes " << removedCard.toString() << " from Andy." << endl;
         while (Jin.checkHandForBook(card1, card2) == true) {
            Jin.bookCards(card1, card2);
            cout << "Jin books " << card1.toString() << " and " << card2.toString() << endl;
         }
      }
      cout << endl;
   }
   else {
      cout << "Andy: Go Fish." << endl;
      if (d.size() > 0) { // only draw if deck is not empty
         drawnCard = d.dealCard();
      }
      else {
         cout << "GAME OVER! (Deck is empty)." << endl;
      }
      
      cout << "Jin draws a " << drawnCard.toString() << endl;
      Jin.addCard(drawnCard);
      while (Jin.checkHandForBook(card1, card2) == true) {
            Jin.bookCards(card1, card2);
            cout << "Jin books " << card1.toString() << " and " << card2.toString() << endl;
      }
      cout << endl;
   }

   cout << "Game updates after Jin's turn..." << endl;
   cout << "Andy's hand is: " << Andy.showHand() << endl;
   cout << "Andy's books are: " << Andy.showBooks() << endl;
   cout << "Jin's hand is: " << Jin.showHand() << endl;
   cout << "Jin's books are: " << Jin.showBooks() << endl;
   cout << endl;

   return 0;
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
