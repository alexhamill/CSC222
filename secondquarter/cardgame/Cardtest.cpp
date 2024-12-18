#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include <string>
#include "Card.h"
#include <vector>
using namespace std;

TEST_CASE("Test can create Cards") {
    Card c1;
    CHECK(c1.suit == NONE);
    CHECK(c1.rank == JOKER);
    Card c2(HEARTS, FOUR);
    CHECK(c2.suit == HEARTS);
    //CHECK(c2.rank == SPADES);
}

TEST_CASE("Test can render Cards") {
    Card c3(HEARTS, QUEEN);
    CHECK(c3.to_string() == "Queen of Hearts");
    Card c4(DIAMONDS, TEN);
    CHECK(c4.to_string() == "10 of Diamonds");
    Card c5;
    CHECK(c5.to_string() == "Joker");
}
TEST_CASE("Test == of Cards") {
    Card c1(DIAMONDS, NINE);
    Card c2(DIAMONDS, NINE);
    Card c3(CLUBS, NINE);
    CHECK((c2 == c1) == true);
    CHECK((c3 == c2) == false);
    CHECK((c1 == c3) == false);
}

TEST_CASE("Test comparison of Cards") {
    Card c1(DIAMONDS, NINE);
    Card c2(CLUBS, NINE);
    Card c3(CLUBS, NINE);
    CHECK((c2 < c1) == true);
    CHECK((c3 <= c2) == true);
    CHECK((c1 >= c3) == true);
}

TEST_CASE("build deck"){
    vector <Card> deck;
    deck = build_deck();
    CHECK(deck[32].to_string() == "8 of Hearts");
}


