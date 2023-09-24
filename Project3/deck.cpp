/* File: deck.cpp
 * Course: CS215-00x
 * Project: Project 3
 * Purpose: the implementation of member functions for the Deck class.
 *
 */

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "deck.h"

 // create a standard 52-card deck
void Deck::createDeck()
{
    deck.clear();
    for (int val = CARD_START; val < CARD_START + POINTS; val++)
    {
        // create each point value for each of FOUR suits, total cards = 13 * 4 = 52 
        Card newSpadeCard('S', val);
        Card newClubCard('C', val);
        Card newHeartCard('H', val);
        Card newDiamondCard('D', val);
        deck.push_back(newSpadeCard);
        deck.push_back(newClubCard);
        deck.push_back(newHeartCard);
        deck.push_back(newDiamondCard);
    }
}

// shuffle the cards in 52-card deck
void Deck::shuffleDeck()
{
    srand(time(0));
    random_shuffle(deck.begin(), deck.end());
}

// return a card from the tail of the deck
Card Deck::deal_a_card()
{
    if (deck.size() == 0)
    {
        cout << "The deck is empty now!" << endl;
        Card invalidCard;
        return invalidCard;
    }
    else
    {
        Card result = deck.back();
        deck.pop_back();
        return result;
    }
}
