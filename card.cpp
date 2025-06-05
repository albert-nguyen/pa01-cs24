// card.cpp
// Author: ALbert Nguyen
// Implementation of the classes defined in card.h

#include <iostream>
#include <string>

using namespace std;

#include "card.h"

Card::Card(char x, string y) {
    suit = x;
    rank = y;
}

string Card::toString() const {
    return string(1, suit) + " " + rank;
}

int Card::suitValue() const {
    if (suit == 'c') return 0;
    if (suit == 'd') return 1;
    if (suit == 's') return 2;
    if (suit == 'h') return 3;
    return -1;
}

int Card::rankValue() const {
    if (rank == "a") return 1;
    if (rank == "2") return 2;
    if (rank == "3") return 3;
    if (rank == "4") return 4;
    if (rank == "5") return 5;
    if (rank == "6") return 6;
    if (rank == "7") return 7;
    if (rank == "8") return 8;
    if (rank == "9") return 9;
    if (rank == "10") return 10;
    if (rank == "j") return 11;
    if (rank == "q") return 12;
    if (rank == "k") return 13;
    return -1;
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && rank == other.rank;
}

bool Card::operator<(const Card& other) const {
    if (suitValue() == other.suitValue()) {
        return rankValue() < other.rankValue();
    }
    return suitValue() < other.suitValue();
}

bool Card::operator>(const Card& other) const {
    if (suitValue() == other.suitValue()) {
        return rankValue() > other.rankValue();
    }
    return suitValue() > other.suitValue();
}

void Card::printCard() {
    cout << suit << " " << rank << endl;
}





