#include <string>
#include <vector>

using namespace std;

    enum Suit {NONE, CLUBS, DIAMONDS, HEARTS, SPADES};
    enum Rank {JOKER, TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

    struct Deck;

struct Card
{
    Rank rank;
    Suit suit;

    Card();
    Card(Suit s, Rank r);
    string to_string() const;
    bool operator==(const Card&) const;
    bool operator!=(const Card&) const;
    bool operator<(const Card&) const;
    bool operator>(const Card&) const;
    bool operator>=(const Card&) const;
    bool operator<=(const Card&) const;
    void print_deck(const vector<Card>&) const;
    int find(const Deck&) const;
};

struct Deck {
    vector<Card> cards;
    Deck(int);
    Deck();
    void print() const;
    void swap_cards(int, int);
    void shuffle();

};

vector<Card> build_deck();