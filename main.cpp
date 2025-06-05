// Feb 14: This file should implement the game using a custom implementation of a BST (that is based on your implementation from lab02)
//Do not include set in this file

#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"

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

  BST alice;
  BST bob;
  
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
  
  playGame(alice, bob);
  
  return 0;
}