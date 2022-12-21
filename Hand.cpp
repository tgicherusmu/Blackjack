//
// Created by Erik Gabrielsen on 10/23/22.
//

#include "Hand.h"
#include "iostream"
using namespace std;

Hand::Hand() {

}

int Hand::getScore() {
    // TODO: Implement Get Score
    int score = 0;
    int i = 0;
    int ace = 0;
    for (i = 0; i < cards.size(); i++) {
        //initialize total
        //add value of all cards in hand within loop
        score += cards.at(i).getScore();
        if (cards.at(i).getRankString() == "Ace") {
            ace++;
        }
    }
    while (score > 21 && ace > 0) {
        score = score - 10;
        ace--;
    }
        return score;
    }
//rule for aces, if score is greater than 21 10 must be subtracted


void Hand::addCard(Card c) {
    // TODO: Implement Add Card
    cards.push_back(c);
}

void Hand::clearHand(){
    cards.clear();
}

void Hand::printHand() {
    int i = 0;
    for (i = 0; i < cards.size(); i++) {
        cout << cards.at(i).getRankString() << " of " << cards.at(i).getSuitString()<< endl;
    }
}