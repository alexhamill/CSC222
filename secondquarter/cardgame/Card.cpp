#include <doctest.h>
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

Card::Card() {
    suit = 0; rank = 0;
}

Card::Card(int s, int r) {
    suit = s; rank = r;
}
string Card::to_string() const
{
    vector<string> suit_strings = {"None", "Clubs", "Diamonds",
                                   "Hearts", "Spades"};
    vector<string> rank_strings = {"Joker", "ace" , "2", "3", "4", "5", "6", "7",
                                   "8", "9", "10", "Jack", "Queen", "King"};

    if (rank == 0) return rank_strings[rank];
    return rank_strings[rank] + " of " + suit_strings[suit];
}
bool Card::operator==(const Card& c2) const
{
    return (rank == c2.rank && suit == c2.suit);
}
