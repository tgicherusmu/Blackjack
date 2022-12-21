//
// Created by Erik Gabrielsen on 10/23/22.
//

#include "Blackjack.h"
#include <fstream>
#include <ostream>

using namespace std;

Blackjack::Blackjack() {
    
}

void Blackjack::play() {
    // TODO: Implement play (Play the game of blackjack)
    // HINT: I would break this up into other functions to make life easier. Maybe comment out the logic FIRST then implement each piece!
    ifstream balance;
    balance.open("../balance.txt"); //open file
    int currentBalance;
    balance >> currentBalance;
    balance.close();

    std::cout << "Welcome to Blackjack! Let's Play!\n" << std::endl;
    std::cout << "Loading bank balance...\n" << std::endl;
    int handNumber = 0;

    while(true) {
        handNumber++;
        //cards.clearHand();
        std::cout << "----Hand " << handNumber << "----" << std::endl;
        std::cout << "Your balance is $" << currentBalance << std::endl;
        int playerBet;
        std::cout << "Place your bet $" << std::endl;
        cin >> playerBet;
        while(playerBet>currentBalance){
            cout<<"Invalid bet" <<endl;
            cout<<"Place your bet again" <<endl;
            cin>>playerBet;
        }
        std::cout << "Dealing cards..." << std::endl;
        cout << endl;
        deck = Deck();
        deck.shuffle();
        dealer.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
        player.addCard(deck.dealCard());
        player.addCard(deck.dealCard());
        //dealer and players receive cards
        cout << "Dealers Hand:" << endl;
        dealer.printHand();
        cout << endl;
        cout << "Dealer's Hand Value: " << dealer.getScore() << endl;
        cout<< endl;
        //dealer.clearHand();
        //player.clearHand();
        cout << "Players Hand:" << endl;
        player.printHand();
        cout << "Hand Value: " << player.getScore();
        //while it is h
        cout << endl;
        char input;
        cout << "Enter 's' to stay or 'h' to hit: h" << endl;
        cin >> input;
        bool busted = false;
        if (!busted) {
            while (input == 'h') {
                // player.addCard(deck.dealCard());
                cout << "New Cards: ";
                cout << endl;
                Card newCard = deck.dealCard();
                player.addCard(newCard);
                cout << newCard.getRankString() << " of " << newCard.getSuitString() << endl;
                cout << "Your Hand Value: " << player.getScore() << endl;
                if (player.getScore() > 21) {
                    busted = true;
                    cout << "You busted!" << endl;
                    cout << "You lost $" << playerBet << endl;
                    currentBalance -= playerBet;
                    break;
                }
                cout << "Enter 's' to stay or 'h' to hit: h" << endl;
                cin >> input;
            }
        }
            if (!busted) {
                while (dealer.getScore() < 17) {
                    cout << "Dealer Hits..." << endl;
                    cout << endl;
                    cout << "New Cards: " << endl;
                    Card newCard = deck.dealCard();
                    dealer.addCard(newCard);
                    //dealer.addCard(newCard);
                    cout << newCard.getRankString() << " of " << newCard.getSuitString() << endl;
                    cout<< endl;
                    cout << "Dealer's Hand Value: " << dealer.getScore() << endl;
                    if (dealer.getScore() > 21) {
                        busted = true;
                        cout << "Dealer busted!" << endl;
                        cout << "You won $" << playerBet << endl;
                        currentBalance += playerBet;
                        //cout << "Enter 'c` to continue or `q` to quit: q" << endl;
                        //cin >>input;
                        //if(input == 'q'){
                           // break;
                    }
                    //cout << "Enter 's' to stay or 'h' to hit: h" << endl;
                    //have dealer automatically hit
                    cin >> input;
                }
            }
            if (!busted) {
                if (player.getScore() > dealer.getScore()) {
                    cout << "You won " << playerBet << endl;
                    currentBalance += playerBet;
                } else if (player.getScore() < dealer.getScore()) {
                    cout << "You lost $" << playerBet << endl;
                    currentBalance -= playerBet;
                } else {
                    cout << "You tied" << endl;
                }
            }
            ofstream newBalance;
            newBalance.open("../balance.txt"); //open file
            newBalance << currentBalance;
            newBalance.close();
            cout << "Enter 'c` to continue or `q` to quit: q" << endl;
            cin >>input;
            if(input == 'q'){
                break;
            }
        dealer.clearHand();
        player.clearHand();
        }
    }


    // invalid bet if it is over


    //break this to function: player turn, dealer turn
    //clear when player busts



