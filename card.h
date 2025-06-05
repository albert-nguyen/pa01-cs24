// card.h
// Author: Albert Nguyen
// All class declarations related to defining a single card go here


#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
    public:
        char suit;
        string rank;
    
        Card(char suit, string rank);
    
        string toString() const;
    
        bool operator<(const Card& other) const;
        bool operator==(const Card& other) const;
        bool operator>(const Card& other) const;

        void printCard();
    
    private:
        int suitValue() const;
        int rankValue() const;
};

#endif





