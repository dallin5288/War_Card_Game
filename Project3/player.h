/* File: player.h
 * Course: CS215-14x
 * Project: Project 3
 * Purpose: the declaration for the player class.
 *
 * Author: Dallin Liu
 *
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <list>
#include "card.h"

using namespace std;

class Player
{
public:
	// default constructor
	Player();

	// alternative constructor
	Player(vector<Card> ini_cards);

	// return how many cards player holds currently
	int getNumCards() const;

	// player plays one card from the front of cards at hand
	Card play_a_card();

	// when the player wins the round, this function will be called
	// player adds winning cards to the end of the cards at hand
	void addCards(vector<Card> winningCards);

	// when there is a tie, this function will be called
	// player drops THREE cards from the front of cards at hand
	vector<Card> dropCards();

	// display cards at player's hand
	void print() const;

	// you are allowed to add other member functions if you want
private:
	int numCards; // how many cards in player's hand
	list<Card> cards; // sequence of cards in player's hand
};
#endif  /* PLAYER_H */