#include <doctest.h>
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
using namespace std;

Card::Card() {
    suit = 0; rank = 0;
}

Card::Card(int s, int r) {
    suit = s; rank = r;
}

string Card::to_string() const{
    vector<string> suit_strings = {"None", "Clubs", "Diamonds",
                                   "Hearts", "Spades"};
    vector<string> rank_strings = {"Joker", "ace" , "2", "3", "4", "5", "6", "7",
                                   "8", "9", "10", "Jack", "Queen", "King"};

    if (rank == 0) return rank_strings[rank];
    return rank_strings[rank] + " of " + suit_strings[suit];
}

bool Card::operator==(const Card& c2) const{
    return (rank == c2.rank && suit == c2.suit);
}

bool Card::operator>(const Card& c2) const{
    if (suit > c2.suit) return true;
    if (suit < c2.suit) return false;
    if (rank > c2.rank) return true;
    if (rank < c2.rank) return false;
    return false;
}

bool Card::operator<(const Card& c2) const{
    return !(this->operator>(c2) || this->operator==(c2));
}
bool Card::operator>=(const Card& c2) const{
    return !(this->operator<(c2));
}
bool Card::operator<=(const Card& c2) const{
    return !(this->operator>(c2));
}
vector<Card> deckbuild(){
        vector<Card> deck(52 ace_of_spades);
        int i = 0;
        for (int suit = 0; suit <= 3; suit++) {
            for (int rank = 1; rank <= 13; rank++) {
                deck[i].suit = suit;
                deck[i].rank = rank;
                i++;
            }
        }
    }
void print_deck(const vector<Card>& deck){
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i].to_string() << endl;
    }
}