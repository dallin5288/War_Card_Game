/* File: card.cpp
 * Course: CS215-14x
 * Project: Project 3
 * Purpose: the implementation of member functions for the Card class.
 * Author: (Dallin LIu)
 */
#include <sstream>
#include <iomanip>
#include "card.h"

 // Default constructor marks card as invalid
Card::Card() {
    suit = 'I';
    point = 0;
}

// Alternate constructor
Card::Card(char s, int p)
{
    suit = s;
    point = p;
}

// access the card point value
int Card::getPoint() const
{
    return point;
}

// access the card suit value
char Card::getSuit() const
{
    return suit;
}

// compare with another Card object passed in as parameter: other
// if the object pointed by this (the object your are working on) has higher point than other, return 1;
// if the object pointed by this (the object your are working on) has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other) const
{
    if (this->point < other.point)
        return -1;
    if (this->point > other.point)
        return 1;
    return 0;
}

// Display a description of the Card object to standard output
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again
//   display the point value with the width = 2 characters
void Card::print() const
{
    const int POINTMIN = 2;  // the minimum point value starts at 2
    const int POINTMAX = 14; // the maximum point value is 14
    const int STARTLETTERPOINT = 11;   //starting at point value 11, it represents as a letter
    const int POINTWIDTH = 2;  // display the point value with the width = POINTWIDTH characters
    if (point < POINTMIN || point > POINTMAX)
    {
        cout << "Invalid card value!" << endl;
        return;
    }

    // map the point to card face
    // 11 -->J, 12 -->Q, 13 -->K, 14 --> A
    string face;
    if (point >= STARTLETTERPOINT)
    {
        switch (point)
        {
        case 11:
            face = "J";
            break;
        case 12:
            face = "Q";
            break;
        case 13:
            face = "K";
            break;
        case 14:
            face = "A";
            break;
        default:
            face = "Invalid";
            break;
        }
    }
    else
    {
        // using stringstream to convert integer into string
        stringstream ss;
        ss << point;
        ss >> face;
    }

    // prints suit symbol with card value
    switch (suit)
    {
    case 'S':
        cout << SPADE << setw(POINTWIDTH) << face << SPADE;
        break;
    case 'C':
        cout << CLUB << setw(POINTWIDTH) << face << CLUB;
        break;
    case 'H':
        cout << HEART << setw(POINTWIDTH) << face << HEART;
        break;
    case 'D':
        cout << DIAMOND << setw(POINTWIDTH) << face << DIAMOND;
        break;
    default:
        cout << "Invalid suit!" << endl;
        break;
    }
}