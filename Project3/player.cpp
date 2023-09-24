/* File: player.cpp
 * Course: CS215-14x
 * Project: Project 3
 * Purpose: the implementation of member functions for the player class.
 *
 *
 * Author: Dallin Liu
 */

#include <iostream>
#include <vector>
#include <list>
#include "player.h"

 // Default constructor
Player::Player()
    : numCards(0)
{
    // Empty constructor - no cards in the player's hand
}

// Alternative constructor
Player::Player(vector<Card> ini_cards)
    : numCards(ini_cards.size()), cards(ini_cards.begin(), ini_cards.end())
{
    // Constructor that sets the initial cards for the player
}

// Returns the number of cards the player currently holds
int Player::getNumCards() const
{
    return numCards;
}

// Player plays one card from the front of cards at hand
Card Player::play_a_card()
{
    Card playedCard = cards.front();
    cards.pop_front();
    numCards--;
    return playedCard;
}

// When the player wins the round, this function will be called.
// Player adds winning cards to the end of the cards at hand.
void Player::addCards(vector<Card> winningCards)
{
    for (const auto& card : winningCards)
    {
        cards.push_back(card);
    }
    numCards += winningCards.size();
}

vector<Card> Player::dropCards()
{
    vector<Card> droppedCards;

    // If the player has less than 3 cards, return an empty vector
    if (numCards < 3) {
        cout << "\nNot enough cards to drop!\n";
        return droppedCards;
    }

    // Drop the first 3 cards from the front of the player's hand and add them to the droppedCards vector
    for (int i = 0; i < 3; i++)
    {
        droppedCards.push_back(cards.front());
        play_a_card();
    }
    return droppedCards;
}

void Player::print() const
{
    for (const auto& card : cards)
    {
        card.print(); // use Card's print() function
        cout << " ";
    }
    cout << endl;
}
