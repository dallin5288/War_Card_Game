/*
 * Course: CS215-014
 * Project: Project 3
 * Purpose: Demonstrate a card game of "War" between two players
 *
 * 
 * Author: Dallin Liu
 */

#include <iostream>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <string>

int main()
{
    // Avoid magic numbers
    const int HANDS = 26;    // each player holds 52/2 = 26 cards to begin the game

    // Create a bool gameover and set it to false (condition for while loop)
    bool gameover = false; 

    Deck gameDeck;
    gameDeck.createDeck();
    gameDeck.shuffleDeck();

    vector<Card> cards_for_Player1; // player 1's cards in hand
    vector<Card> cards_for_Player2; // player 2's cards in hand
    vector<Card> pile;      // represents the pile of cards on the table

    // Deals cards to players
    for (int i = 0; i < HANDS; i++)
    {
        cards_for_Player1.push_back(gameDeck.deal_a_card());
        cards_for_Player2.push_back(gameDeck.deal_a_card());
    }

    // Create objects of Player class: player1 and player2
    Player player1(cards_for_Player1);
    Player player2(cards_for_Player2);

    // Loop until gameover is True
    while (!gameover)
    {
        // Display which each card players play
        cout << "Player 1 plays: ";
        Card card1 = player1.play_a_card();
        card1.print();
        cout << endl;

        cout << "Player 2 plays: ";
        Card card2 = player2.play_a_card();
        card2.print();
        cout << endl;

        // Dislpay how many card are in the pile
        pile.push_back(card1);
        pile.push_back(card2);
        cout << "----------------------------------------------" << endl << endl;;
        cout << "There are " << pile.size() << " cards on the pile!" << endl << endl;
        cout << "----------------------------------------------" << endl;


        // Player1 wins the round
        if (card1.getPoint() > card2.getPoint())
        {

            player1.addCards(pile);
            pile.clear();


            cout << "Player 1 wins...get all cards from the current round!" << endl;
        }

        // Player2 wins the round
        else if (card2.getPoint() > card1.getPoint())
        {
            player2.addCards(pile);
            pile.clear();

            cout << "Player 2 wins...get all cards from the current round!" << endl;
        }

        // Otherwise if there is tie consider the conditions
        else
        {
            cout << "It is a tie...for this round!" << endl;
            cout << "Each player drops three cards (face down) on the pile, then" << endl;
            cout << "play one more card (face up)" << endl;

            // When number of cards is less than 3 game is over
            if (player1.getNumCards() < 3 && player2.getNumCards() < 3)
            {

                if (player1.getNumCards() < player2.getNumCards())  // player1 has less cards than player 2 then player 2 wins
                {
                    cout << "Game is over!" << endl;
                    cout << "Player 2 wins the game!" << endl;

                    gameover = true;    // game is True thus the game is over
                }

                else if (player2.getNumCards() > player1.getNumCards()) // player2 has less cards than player 1 then player 1 wins
                {

                    cout << "Game is over!" << endl;
                    cout << "Player 1 wins the game!" << endl;

                    gameover = true;   
                }
                else if (player1.getNumCards() == player2.getNumCards())    // if number of card in hand or equal than tie game
                {
                    cout << "It is a tie game!" << endl;

                    gameover = true;
                }
            }

            // Drop three cards and play the game
            else
            {
                vector<Card> temp = player1.dropCards();
                for (int i = 0; i < temp.size(); i++)
                {
                    pile.push_back(temp[i]);
                }
                temp = player2.dropCards();
                for (int i = 0; i < temp.size(); i++)
                {
                    pile.push_back(temp[i]);
                }

                cout << "----------------------------------------------" << endl << endl;;
                cout << "There are " << pile.size() << " cards on the pile!" << endl << endl;
                cout << "----------------------------------------------" << endl;
            }
        }

        cout << "Player1 has " << player1.getNumCards() << " cards in hand!" << endl;
        cout << "Player2 has " << player2.getNumCards() << " cards in hand!" << endl << endl;

        // Player 1 is out of cards but player 2 still has cards then player 2 wins
        if (player1.getNumCards() == 0 && player2.getNumCards() > 0)
        {
            cout << "Game is over!" << endl;
            cout << "Player 2 wins the game!" << endl;

            gameover = true;    // gameover is true thus game is over
        }

        // Player 2 is out of cards but player 2 still has cards then player 1 wins
        else if (player2.getNumCards() == 0 && player1.getNumCards() > 0)
        {

            cout << "Game is over!" << endl;
            cout << "Player 1 wins the game!" << endl;

            gameover = true;
        }


        // Prompt to quit the game or continue
        if (!gameover)
        {
            string quit;

            // Enter N or n to quit
            cout << "Do you want to continue...for the next round ? (N or n to" << endl;
            cout << "quit) ";
            getline(cin, quit);

            // If the input is n or N then the game is over display how many cards are left
            if (quit == "n" || quit == "N")
            {
                cout << "You choose to quit the game!" << endl;
                cout << "Player1 has " << player1.getNumCards() << " cards left!" << endl;
                cout << "Player2 has " << player2.getNumCards() << " cards left!" << endl;

                gameover = true;
            }
        }
    }
    return 0;
}