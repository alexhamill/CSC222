#include <iostream>
#include "Card.h"

int main() {
    Deck d1;
    d1.cards.push_back(Card{"Hearts", 2});
    d1.cards.push_back(Card{"Spades", 3});
    d1.cards.push_back(Card{"Diamonds", 1});
    d1.cards.push_back(Card{"Clubs", 4});

    Deck sortedDeck = d1.merge_sort();

    for (const auto& card : sortedDeck.cards) {
        std::cout << card.suit << " " << card.rank << std::endl;
    }

    return 0;
}