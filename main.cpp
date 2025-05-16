// Feb 14: This file should implement the game using a custom implementation of a BST (that is based on your implementation from lab02)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

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
    CardList AliceCards;
    CardList BobCards;

    //These have to be the new class type.

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    char suit = line[0];
    char number = line[2];
    Card card;
    card.set_suit(suit);
    card.set_Number(number);
    AliceCards.insert(card);

    //AliceCards must be the new BST class
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    char suit = line[0];
    char number = line[2];
    Card card;
    card.set_suit(suit);
    card.set_Number(number);
    BobCards.insert(card);

    //This must be the new BST

  }
  cardFile2.close();

  // Card* temp = AliceCards->root->card;
  
  // while(temp)
  // {}
  bool AliceTurn = true;
  bool foundMatch = false;

  while(!foundMatch){
    if (AliceTurn) {
        for (int suit = 1; suit <= 4 && !foundMatch; ++suit) 
        {
          for (int i = 1; i <= 13 && !foundMatch; ++i) 
          {
            Card currentCard(suit, i);
            if (AliceCards.find(currentCard)) 
            {
              for (int bobSuit = 1; bobSuit <= 4; ++bobSuit) 
              {
                for (int j = 1; j <= 13; ++j) 
                {
                  Card bobCurrentCard(bobSuit, j);
                  if (BobCards.find(bobCurrentCard) && currentCard.compare_Cards(bobCurrentCard)) 
                  {
                    if (currentCard.get_Number() == 1 || currentCard.get_Number() == 11 ||currentCard.get_Number() == 12 ||currentCard.get_Number() == 13)
                    {
                      char number = ' ';
                      if (currentCard.get_Number() == 1){number= 'a';}
                      else if (currentCard.get_Number() == 11){number= 'j';}
                      else if (currentCard.get_Number() == 12){number= 'q';}
                      else if (currentCard.get_Number() == 13){number= 'k';}
                      cout << "Alice picked matching card " << currentCard.get_Suit() << " " << number << endl;
                      AliceCards.remove(currentCard);
                      BobCards.remove(bobCurrentCard);
                      foundMatch = true;
                      break;
                    } else
                    {
                      cout << "Alice picked matching card " << currentCard.get_Suit() << " " << currentCard.get_Number() << endl;
                      AliceCards.remove(currentCard);
                      BobCards.remove(bobCurrentCard);
                      foundMatch = true;
                      break;
                    }
                  }
                }
                if (foundMatch) break;
                
              }
            }
          }
        }
    } else 
    {
      for (int bobSuit = 4; bobSuit >= 1 && !foundMatch; --bobSuit) 
      {
        for (int j = 13; j >= 1 && !foundMatch; --j) 
        {
          Card bobCurrentCard(bobSuit, j);
          if (BobCards.find(bobCurrentCard))
          {
            for (int suit = 4; suit >= 1; --suit) 
            {
              for (int i = 13; i >= 1; --i) 
              {
                Card currentCard(suit, i);
                if (AliceCards.find(currentCard) && bobCurrentCard.compare_Cards(currentCard)) 
                  {
                    if(bobCurrentCard.get_Number() == 1 || bobCurrentCard.get_Number() == 11 ||bobCurrentCard.get_Number() == 12 ||bobCurrentCard.get_Number() == 13)
                    {
                      char number = ' ';
                      if (bobCurrentCard.get_Number() == 1){number= 'a';}
                      else if (bobCurrentCard.get_Number() == 11){number= 'j';}
                      else if (bobCurrentCard.get_Number() == 12){number= 'q';}
                      else if (bobCurrentCard.get_Number() == 13){number= 'k';}
                      cout << "Bob picked matching card " << currentCard.get_Suit() << " " << number << endl;
                      BobCards.remove(bobCurrentCard);
                      AliceCards.remove(currentCard);
                      foundMatch = true;
                      break;
                    }else
                    {
                      cout << "Bob picked matching card " << bobCurrentCard.get_Suit() << " " << bobCurrentCard.get_Number() << endl;
                      BobCards.remove(bobCurrentCard);
                      //  cout <<currentCard.get_Suit() << " " <<currentCard.get_Number() << endl;
                       AliceCards.remove(currentCard);
                      foundMatch = true;
                      break;
                    }
                  }
              }
              if (foundMatch) break;
            }
          }
        }
      }
    }
    AliceTurn = !AliceTurn;
    foundMatch = !foundMatch;
  }
  
  cout << endl;
  

  cout << "Alice's cards:" << endl;

  AliceCards.inorder();
  
  cout << endl;

  cout << "Bob's cards:" << endl;

  BobCards.inorder();
  return 0;
}












