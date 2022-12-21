#ifndef PROGRAM4_DECK_H
#define PROGRAM4_DECK_H

#include <random>
#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    Card dealCard();
    void addCard(Card);
    void shuffle();

private:
    std::vector<Card> cards;
    int value;
};


#endif