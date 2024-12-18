#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include <string>
#include "Card.h"
#include <vector>
using namespace std;

TEST_CASE("Test create Deck with two constructors") {
    Deck d1(10);
    CHECK(d1.cards.size() == 10);
    CHECK(d1.cards[0].to_string() == "Joker");
    Deck d2;
    CHECK(d2.cards.size() == 52);
    CHECK(d2.cards[0].to_string() == "2 of Clubs");
    CHECK(d2.cards[51].to_string() == "Ace of Spades");
}

TEST_CASE("Test for comparison of Cards") {
    Card c1(HEARTS, QUEEN);
    Card c2(HEARTS, QUEEN);
    Card c3(SPADES, ACE);
    Card c4(HEARTS, FIVE);
    Card c5(HEARTS, FOUR);
    Card c6(DIAMONDS, FOUR);
    CHECK((c1 == c2) == true);
    CHECK((c1 == c3) == false);
    CHECK((c1 != c3) == true);
    CHECK((c1 > c5) == true);
    CHECK((c1 <= c5) == false);
    CHECK((c6 < c5) == true);
    CHECK((c5 >= c6) == true);
}

TEST_CASE("Test find Card in Deck") {
    Deck d;
    Card c(HEARTS, QUEEN);
    int pos = c.find(d);
    CHECK(d.cards[pos].to_string() == "Queen of Hearts");
    // Create non-existant card to confirm it isn't in the deck
    Card c2(NONE, QUEEN);
    int pos2 = c2.find(d);
    CHECK(pos2 == -1);
}

TEST_CASE("Test swap_cards in Deck") {
    Deck d;
    d.swap_cards(0, 51);
    CHECK(d.cards[0].to_string() == "Ace of Spades");
    CHECK(d.cards[51].to_string() == "2 of Clubs");
}

TEST_CASE("shuffle and sort test") {
    Deck d;
    CHECK(d.cards[51].to_string() == "Ace of Spades");
    CHECK(d.cards[0].to_string() == "2 of Clubs");
    d.shuffle();
    CHECK(d.cards[51].to_string() != "Ace of Spades");
    CHECK(d.cards[0].to_string() != "2 of Clubs");
    d.sort();
    CHECK(d.cards[51].to_string() == "Ace of Spades");
    CHECK(d.cards[0].to_string() == "2 of Clubs");
}

