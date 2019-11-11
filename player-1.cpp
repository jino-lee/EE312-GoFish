// player.cpp
// Represents a player in the game Go Fish

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
//#include <unordered_map>
#include "card.h"
#include "player.h"

using namespace std;

//default constructor
Player::Player() {
    myName = "";
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    //remove cards from hand and push them into myBook vector
    removeCardFromHand(c1);
    removeCardFromHand(c2);

    myBook.push_back(c1);
    myBook.push_back(c2);
}

// checkHandForBook() will check a players hand for a pair
// If a pair is found, it returns true and populates the two variables with the cards that make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2) {
   // unordered_map<int, int> cardCount; // maps each rank number (1 - 13) to number of cards of that rank
    int cardCount[14]; //indices 0-13 will be used to store card count of that rank
    for (int i = 0; i < 14; i++) {//initialize counts to 0
        cardCount[i] = 0;
    }    

    int matchRank = 0;
    vector<int> matchIndexes; // stores the first 2 indexes of Cards that match with matchRank

    for (int i = 0; i < myHand.size(); i++) { // Update the map values
        cardCount[myHand[i].getRank()]++;
    }

    for (int i = 1; i <= 13; i++) { // check if any count >= 2 in the map and save the rank #
        if (cardCount[i] >= 2) {
            matchRank = i;
        }
    }
    if (matchRank == 0) { // if no cards in the hand are pairs
        return false;
    }

    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == matchRank) {
            matchIndexes.push_back(i);
        }
    }
    c1 = myHand[matchIndexes[0]];
    c2 = myHand[matchIndexes[1]];
    return true;
}

// rankInHand() 
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == c.getRank()) {
            return true;
        }
    }
    // else, same-rank card not found
    return false;
}

Card Player::chooseCardFromHand() const{
    //unordered_map <int, int> cardAmounts;
    int cardAmounts[14];
    for (int i = 0; i < 14; i++) {//init counts to 0
        cardAmounts[i] = 0;
    }    
     
    for (int i = 0; i < myHand.size(); i++) {
        cardAmounts[myHand[i].getRank()]++;
    }
    for (int i = 0; i < myBook.size(); i++) {
        cardAmounts[myBook[i].getRank()]++;
    }

    // Strategy = Prioritize finding a pair first (even if only 1 available card to complete book)
    for (int i = 0; i < myHand.size(); i++) {
        if (cardAmounts[myHand[i].getRank()] == 1) { // 3 remaining cards of that rank = highest probability to get a book pair
            return myHand[i];
        }
    }
    for (int i = 0; i < myHand.size(); i++) {
        if (cardAmounts[myHand[i].getRank()] == 3) { // 1 remaining card of that rank in opponents hand/deck
            return myHand[i];
        }
    }
    return myHand[0]; // else, if no pairs are possible just return first card in the hand
}

// Checks if any cards in the hand are the same exact card as parameter c
// If so, return true
bool Player::cardInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i] == c) {
            return true;
        }
    }
    // else, same-rank card not found
    return false;
}
    
 // Pre-condition: PLAYER'S HAND MUST HAVE A CARD OF SAME RANK AS input Card c (can use rankInHand function to check)
 // REMOVES A CARD FROM PLAYER'S HAND OF THE SAME RANK AS input Card c   
Card Player::removeCardFromHand(Card c) {
    Card temp;
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == c.getRank()) {
            temp = myHand[i];
            myHand.erase(myHand.begin() + i);
            return temp;
        }
    }

    return temp; // to avoid compilation errors, should never hit this return statement
}

string Player::showHand() const {
    string handString;

    if (!myHand.empty()) {
        handString.append(myHand[0].toString());
    }
    for (int i = 1; i < myHand.size(); i++) {
        handString.append(" " + myHand[i].toString());
    }
    // Do i need to null terminate strings in c++???
    return handString;
}


string Player::showBooks() const{
    string booksString;

    if (!myBook.empty()) {
        booksString.append(myBook[0].toString());
    }
    for (int i = 1; i < myBook.size(); i++) {
        booksString.append(" " + myBook[i].toString());
    }
    // Do i need to null terminate strings in c++???
    return booksString;
}


int Player::getHandSize() const {
    return (myHand.size());
}

int Player::getBookSize() const {
    return (myBook.size());
}
