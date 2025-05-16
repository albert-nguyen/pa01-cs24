// card.h
// Author: Albert Nguyen
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card {


 public:
   Card(); 
   Card(int i, int j);
    void set_Number(char number);
    void set_suit(char suit);
    bool compare_Cards (const Card& Card) const;
    bool operator<(const Card& other) const;
    int get_Number() const;
    char get_suit() const;





 private:
    int number;
    int suit;
    





};

#endif