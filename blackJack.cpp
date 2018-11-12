/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

enum Suit {
    Heart,
    Spade,
    Diamond,
    Club
}

class Card {
    public:
    
    int faceValue;
    Suit suit;
    virtual int value() { return faceValue; }
}


class Hand {
    public:
    
    std::vector<Card> cards;
    
    virtual int score() {
        int sum = 0;
        for (Card card : cards) {
            sum += card.faceValue;
        }
        return sum;
    }
}

class Deck {
    public:
    
    std::vector<Card> cards;
    int deckIndex;
    
    void shuffle() {}
    Hand * dealHand() {} // deal from deck
    Card * dealCard() {} 
}


class BlackJackCard : Card {
    int value() {} // return black jack card value or possible values
}

class BlackJackHand : Hand {
    public:
    int score() {
        // get best score for hand
    }
}


class Players {
    string name;
    int id;
    int positionAtTable;
    Hand hand;
    
    bool Hit() {} // Player chooses to hit if AI or user calls
}

int main()
{
    // Game 
    // Loop between players for them to get hand
    
    // Loop between players for actual game 
    // Check winner 
    
    cout<<"Hello World";

    return 0;
}
