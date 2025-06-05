// Feb 14: This file should implement the game using the std::set container class
// Do not include card_list.h in this file

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  set<Card> alice;
  set<Card> bob;

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    if (line.length() < 3) continue;
      char suit = line[0];
      string rank = line.substr(2);
      alice.insert(Card(suit, rank));
    }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    if (line.length() < 3) continue;
      char suit = line[0];
      string rank = line.substr(2);
      bob.insert(Card(suit, rank));
    }
  cardFile2.close();
  
//playGame

  bool matched = true;
    while (matched) {
        matched = false;
        for (auto it = alice.begin(); it != alice.end(); ++it) {
          set<Card>::iterator bobIt = bob.find(*it);
            if (bobIt != bob.end()) {
                std::cout << "Alice picked matching card " << it->toString() << endl;
                bob.erase(*it);
                alice.erase(*it);
                matched = true;
                break;
            }
        }
        for (auto it = bob.rbegin(); it != bob.rend(); ++it) {
          set<Card>::iterator aliceIt = alice.find(*it);
            if (aliceIt != alice.end()) {
                std::cout << "Bob picked matching card " << it->toString() << endl;
                alice.erase(*it);
                bob.erase(*it);
                matched = true;
                break;
            }
        }
    }
    std::cout << endl << "Alice's cards:" << endl;
    for (auto it = alice.begin(); it != alice.end(); ++it) {
      Card c = *it;
      c.printCard();
    }
    std::cout << endl << "Bob's cards:" << endl;
    for (auto it = bob.begin(); it != bob.end(); ++it) {
      Card c = *it;
      c.printCard();
    }
  
  return 0;
}




