#include <doctest.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Card.h"
using namespace std;

Card::Card() {
    suit = NONE; rank = JOKER;
}

Card::Card(Suit s, Rank r) {
    suit = s; rank = r;
}

string Card::to_string() const{
    vector<string> suit_strings = {"None", "Clubs", "Diamonds",
                                   "Hearts", "Spades"};
    vector<string> rank_strings = {"Joker", "" , "2", "3", "4", "5", "6", "7",
                                   "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    if (rank == 0) return rank_strings[rank];
    return rank_strings[rank] + " of " + suit_strings[suit];
}

bool Card::operator==(const Card& c2) const{
    return (rank == c2.rank && suit == c2.suit);
}
bool Card::operator!=(const Card& c2) const{
    return (rank != c2.rank || suit != c2.suit);
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

int Card::find(const Deck& deck) const
{
    for (int i = 0; i < deck.cards.size(); i++) {
        if (deck.cards[i] == (*this)) return i;
    }
    return -1;
}

vector<Card> build_deck()
{
    vector<Card> temp(52);
    
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit+1)) {
        for (Rank rank = TWO; rank <= ACE; rank = Rank(rank+1)) {
            temp[i].suit = suit;
            temp[i].rank = rank;
            i++;
        }
    }
    return temp;
}
void print_deck(const vector<Card>& deck){
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i].to_string() << endl;
    }
}

Deck::Deck(int size)
{
    vector<Card> temp(size);
    cards = temp;
}
Deck::Deck()
{
    vector<Card> temp(52);
    cards = temp;
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit+1)) {
        for (Rank rank = TWO; rank <= ACE; rank = Rank(rank+1)) {
            cards[i].suit = suit;
            cards[i].rank = rank;
            i++;
        }
    }
}

void Deck::print() const
{
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i].to_string() << endl;
    }
}
void Deck::swap_cards(int n, int b) {
    Card temp = cards[n];
    cards[n] = cards[b];
    cards[b] = temp;
}

void Deck::shuffle()
{
    for (int i = 0; i < cards.size(); i++) {
        int rand_card = random_between(0, cards.size() - 1);
        swap_cards(i, rand_card);
    }
}

void Deck::sort(){
    int i = 0;
    while(i<cards.size()){
        if(i!=0){
        if(cards[i]<cards[i-1]){
            swap_cards(i,i-1);
            i=0;
        }
        }
        i++;
    }
}

int random_between(int s, int f){
    return (rand()%(f-s+1))+s;
}

Deck Deck::subdeck(int l, int h) const
{
    //includes both start and stop
    Deck sub(h-l+1);

    for (int i = 0; i < sub.cards.size(); i++) {
        sub.cards[i] = cards[l+i];
    }
    return sub;
}

void Deck::add_card(const Card& c)
{
    cards.push_back(c);
}

Card Deck::remove_card()
{
    Card card = cards[cards.size()-1];
    cards.pop_back();
    return card;
}

void swap_cards(Card &c1, Card &c2){
    Card temp = c1;
    c1 = c2;
    c2 = temp;
}

void Deck::add_cards(Deck d2){
    for(int i=0;i<d2.cards.size();i++){
        cards.push_back(d2.cards[i]);
    }
}

Deck Deck::merge_sort() const
{   
    Deck d2;
    d2.cards = cards;
    // if the deck is 0 or 1 cards, return it
    if (d2.cards.size()<2){return d2;}
    // find the midpoint of the deck
    int midpoint = (d2.cards.size()>>1);
    // divide the deck into two subdecks
    Deck d3 = d2.subdeck(0,midpoint);
    Deck d4 = d2.subdeck(midpoint+1,d2.cards.size()-1);
    d3.merge_sort().add_cards(d4.merge_sort());
    return d3;
    // sort the subdecks using merge_sort
    // merge the two halves and return the result
}