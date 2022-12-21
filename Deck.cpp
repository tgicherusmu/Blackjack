//
// Created by Erik Gabrielsen on 10/23/22.
//

#include "Deck.h"
#include <vector>

Deck::Deck() {
    for(int i =0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            Card temp(i, j);
            cards.push_back(temp);
        }
    }
}

void Deck::shuffle() {
    // TODO: Implement shuffle
    //rand() * 52;
    value = 0;
    for(int i = 0; i < 500; i++) {
        int randNum1 = (rand() % (52));
        int randNum2 = (rand() % (52));// 52 swaps
        Card tempCard = cards[randNum1];
        cards[randNum1] = cards[randNum2];
        cards[randNum2] = tempCard;
        //swap top with random, loop -=51

    }
}

Card Deck::dealCard() {
    // TODO: Implement Deal Card
    Card tempCard = cards.back();
    cards.pop_back();
    return tempCard;
}

void Deck::addCard(Card newCard) {
    // TODO: Impmlement Add Card
    cards.push_back(newCard);
}