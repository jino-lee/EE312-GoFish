// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>     // File output
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
//void showWinner(Player &p1, Player &p2);

int main()
{
   ofstream myfile ("gofish_results.txt");
   if (!myfile.is_open()) {
      cout << "Unable to open file" << endl;
      return 0;
   }
   
   Deck d; //create a new deck of cards
   
   myfile << "Shuffling deck..." << endl;
   d.shuffle();
   
   myfile << "Now playing Go Fish..." << endl;
 
   Player Andy("Andy");
   Player Jin("Jin");
   Card card1;
   Card card2;
   Card chosenCard;
   Card removedCard;
   Card drawnCard;
   int chosenCardRank;

   myfile << "First player's name is: " << Andy.getName() << endl;
   myfile << "Second player's name is: " << Jin.getName() << endl;

   // Deal 7 cards to each player
   myfile << "Dealing cards..." << endl;
   for (int i = 0; i < 7; i++) {
      Andy.addCard(d.dealCard());
      Jin.addCard(d.dealCard());
   }
   myfile << "Andy's hand is: " << Andy.showHand() << endl;
   myfile << "Jin's hand is: " << Jin.showHand() << endl;
   
   //turn loop
   while (d.size() >= 0) {
      
      //*** Andy's turn***

      //Andy asks
      chosenCard = Andy.chooseCardFromHand();
      myfile << "Andy: Do you have a " << chosenCard.rankString(chosenCard.getRank()) << "?" << endl;
      while (Jin.rankInHand(chosenCard) == true) {//successful call
         myfile << "Jin: Yes. I have a " << chosenCard.rankString(chosenCard.getRank()) << endl;

         while (Jin.rankInHand(chosenCard) == true) { // keep checking for specified rank of chosen card in opponent's hand
            removedCard = Jin.removeCardFromHand(chosenCard);
            Andy.addCard(removedCard);
            myfile << "Andy takes " << removedCard.toString() << " from Jin." << endl;
            while (Andy.checkHandForBook(card1, card2) == true) {
               Andy.bookCards(card1, card2);
               myfile << "Andy books " << card1.toString() << " and " << card2.toString() << endl;
            }   
         }
         myfile << endl;
         
         chosenCard = Andy.chooseCardFromHand();//Another turn
         myfile << "Andy: Do you have a " << chosenCard.rankString(chosenCard.getRank()) << "?" << endl;
      }
      
      myfile << "Jin: Go Fish." << endl;
      if (d.size() > 0) { // as long as deck is not empty
         drawnCard = d.dealCard();
      }   
      else {
         myfile << "GAME OVER! (Deck is empty)." << endl;
         
         int p1_bs = Andy.getBookSize();
         int p2_bs = Jin.getBookSize();
   
         myfile << Andy.getName() << " ends with " << p1_bs / 2 << " books!" << endl;
         myfile << Jin.getName() << " ends with " << p2_bs / 2 << " books!" << endl;
         myfile  << endl;
  
         if (p1_bs > p2_bs) {
            myfile << Andy.getName() << " wins!" << endl;
         }  
         else if (p1_bs < p2_bs) {
            myfile << Jin.getName() << " wins!" << endl; 
         }   
         else if (p1_bs == p2_bs) {
            myfile << Andy.getName() << " and " << Jin.getName() << " draw!" << endl;   
         }
            
         return 0;
      } 
 
      myfile << "Andy draws a " << drawnCard.toString() << endl;
      Andy.addCard(drawnCard);
      while (Andy.checkHandForBook(card1, card2) == true) {
        Andy.bookCards(card1, card2);
        myfile << "Andy books " << card1.toString() << " and " << card2.toString() << endl;
      } 
      myfile << endl;
   

      myfile << "Game updates after Andy's turn..." << endl;
      myfile << "Andy's hand is: " << Andy.showHand() << endl;
      myfile << "Andy's books are: " << Andy.showBooks() << endl;
      myfile << "Jin's hand is: " << Jin.showHand() << endl;
      myfile << "Jin's books are: " << Jin.showBooks() << endl;
      myfile << endl;


      //***Jin's turn***
      
      //Jin asks
      chosenCard = Jin.chooseCardFromHand();
      myfile << "Jin: Do you have a " << chosenCard.rankString(chosenCard.getRank()) << "?" << endl;
      while (Andy.rankInHand(chosenCard) == true) {
         myfile << "Andy: Yes. I have a " << chosenCard.rankString(chosenCard.getRank()) << endl;

         while (Andy.rankInHand(chosenCard) == true) { // keep checking if Andy's hand has specified rank
            removedCard = Andy.removeCardFromHand(chosenCard);
            Jin.addCard(removedCard);
            myfile << "Jin takes " << removedCard.toString() << " from Andy." << endl;
            while (Jin.checkHandForBook(card1, card2) == true) {
               Jin.bookCards(card1, card2);
               myfile << "Jin books " << card1.toString() << " and " << card2.toString() << endl;
            }
         } 
         myfile << endl;
  
         chosenCard = Jin.chooseCardFromHand();//Another turn
         myfile << "Jin: Do you have a " << chosenCard.rankString(chosenCard.getRank()) << "?" << endl;
      } 
      
      myfile << "Andy: Go Fish." << endl;
      if (d.size() > 0) { // only draw if deck is not empty
         drawnCard = d.dealCard();
      }
      else {
         myfile << "GAME OVER! (Deck is empty)." << endl;
          
         int p1_bs = Andy.getBookSize();
         int p2_bs = Jin.getBookSize();
   
         myfile << Andy.getName() << " ends with " << p1_bs / 2 << " books!" << endl;
         myfile << Jin.getName() << " ends with " << p2_bs / 2 << " books!" << endl;
         myfile  << endl;
  
         if (p1_bs > p2_bs) {
            myfile << Andy.getName() << " wins!" << endl;
         }  
         else if (p1_bs < p2_bs) {
            myfile << Jin.getName() << " wins!" << endl; 
         }
         else if (p1_bs == p2_bs) {
            myfile << Andy.getName() << " and " << Jin.getName() << " draw!" << endl;   
         }
         return 0;
      } 
      
      myfile << "Jin draws a " << drawnCard.toString() << endl;
      Jin.addCard(drawnCard);
      while (Jin.checkHandForBook(card1, card2) == true) {
         Jin.bookCards(card1, card2);
         myfile << "Jin books " << card1.toString() << " and " << card2.toString() << endl;
      }
      myfile << endl;
      

      myfile << "Game updates after Jin's turn..." << endl;
      myfile << "Andy's hand is: " << Andy.showHand() << endl;
      myfile << "Andy's books are: " << Andy.showBooks() << endl;
      myfile << "Jin's hand is: " << Jin.showHand() << endl;
      myfile << "Jin's books are: " << Jin.showBooks() << endl;
      myfile << endl;
      /*
      if (d.size() <= 0) {
         int p1_bs = Andy.getBookSize();
         int p2_bs = Jin.getBookSize();
   
         myfile << Andy.getName() << " ends with " << p1_bs / 2<< " books!" << endl;
         myfile << Jin.getName() << " ends with " << p2_bs / 2<< " books!" << endl;
         myfile  << endl;
  
         if (p1_bs > p2_bs) {
            myfile << Andy.getName() << " wins!" << endl;
         }  
         else if (p1_bs < p2_bs) {
            myfile << Jin.getName() << " wins!" << endl; 
         }
         else if (p1_bs == p2_bs) {
            myfile << Andy.getName() << " and " << Jin.getName() << " draw!" << endl;   
         }
                  
         return 0;
      }
      */
   }
   myfile.close();
   return 0;
}
/*
void showWinner(Player &p1, Player &p2) {
   int p1_bs = Andy.getBookSize();
   int p2_bs = Jin.getBookSize();
   
   myfile << Andy.getName() << " ends with " << p1_bs << " books!" << endl;
   myfile << Jin.getName() << " ends with " << p2_bs << " books!" << endl;
   myfile  << endl;
  
   if (p1_bs > p2_bs) {
      myfile << Andy.getName() << " wins!" << endl;
   }  
   else if (p1_bs < p2_bs) {
      myfile << Jin.getName() << " wins!" << endl; 
   }
   else if (p1_bs == p2_bs) {
      myfile << Andy.getName() << " and " << Jin.getName() << " draw!" << endl;   
   }
}
*/
