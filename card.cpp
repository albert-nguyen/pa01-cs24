// card.cpp
// Author: Albert Nguyen
// Implementation of the classes defined in card.h
#include "card.h"

void Card::set_Number(char number)
{
    //Sets card number by converting it into an int
    if (number == 'a') {this->number=1;}
    else if(number == '2'){this->number=2;}
    else if(number == '3'){this->number=3;}
    else if(number == '4'){this->number=4;}
    else if(number == '5'){this->number=5;}
    else if(number == '6'){this->number=6;}
    else if(number == '7'){this->number=7;}
    else if(number == '8'){this->number=8;}
    else if(number == '9'){this->number=9;}
    else if(number == 'j'){this->number=11;}
    else if(number == 'q'){this->number=12;}
    else if(number == 'k'){this->number=13;}
    else {this->number = 10;}

}

void Card::set_suit(char suit)
{
    //Sets card suit
    if (suit == 'c') {this->suit=1;}
    else if(suit == 'd'){this->suit=2;}
    else if(suit == 's'){this->suit=3;}
    else if(suit == 'h'){this->suit=4;}

}

bool Card::compare_Cards(const Card& Card) const
{
    if (this->suit == Card.suit)
    {
        if (this->number == Card.number)
        {
            return true;
        }
    }
    return false;
}

bool Card::operator<(const Card& other) const
{
    if(suit != other.suit)
    {
        return suit < other.suit;
    }
        return number < other.number;
}

int Card::get_Number() const
{
    return this->number;
}
char Card::get_Suit() const
{
    if (this->suit==1) return 'c';
    else if (this->suit==2) return 'd';
    else if (this->suit==3) return 's';
    else if (this->suit==4) return 'h';
    return '\n';
}
Card::Card()
{
    suit = 0;
    number = 0;
}
Card::Card(int i , int j)
{
    suit = i;
    number = j;
}