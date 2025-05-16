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
  set <Card> AliceCards;
  set <Card> BobCards;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    char suit = line[0];
    char number = line[2];
    Card card;
    card.set_suit(suit);
    card.set_Number(number);
    AliceCards.insert(card);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    char suit = line[0];
    char number = line[2];
    Card card;
    card.set_suit(suit);
    card.set_Number(number);
    BobCards.insert(card);

  }
  cardFile2.close();
  
  bool AliceTurn = true;
  
  while(true)
  {
    bool foundMatch = false;
    if (AliceTurn)
    {
      for(const auto& card1 : AliceCards)
      {
        for (const auto& card2 : BobCards)
        {
          if(card1.compare_Cards(card2))
          {
            if(card1.get_Number() == 1 ||card1.get_Number() == 11 || card1.get_Number() == 12 ||card1.get_Number() == 13)
            {
              char number = ' ';
              if (card1.get_Number() == 1){number= 'a';}
              else if (card1.get_Number() == 11){number= 'j';}
              else if (card1.get_Number() == 12){number= 'q';}
              else if (card1.get_Number() == 13){number= 'k';}
              cout << "Alice picked matching card " << card1.get_Suit() << " " << number << endl;
              AliceCards.erase(card1);
              BobCards.erase(card2);
              foundMatch = true;
              break;

            }else{
            cout << "Alice picked matching card " << card1.get_Suit() << " " << card1.get_Number() << endl;
            AliceCards.erase(card1);
            BobCards.erase(card2);
            foundMatch = true;
            break;
            }
          }
        }
        if (foundMatch) break;
      }
    }else
    {
      for(auto card1_i = BobCards.rbegin(); card1_i != BobCards.rend(); ++card1_i)
      {
        const auto& card1 = *card1_i;
        for (const auto& card2 : AliceCards)
        {
          if(card1.compare_Cards(card2))
          {
            if(card1.get_Number() == 1 ||card1.get_Number() == 11 || card1.get_Number() == 12 ||card1.get_Number() == 13)
            {
              char number = ' ';
              if (card1.get_Number() == 1){number= 'a';}
              else if (card1.get_Number() == 11){number= 'j';}
              else if (card1.get_Number() == 12){number= 'q';}
              else if (card1.get_Number() == 13){number= 'k';}
              cout << "Bob picked matching card " << card1.get_Suit() << " " << number << endl;
              BobCards.erase(card1);
              AliceCards.erase(card2);
              foundMatch = true;
              break;
            }
            else{
              cout << "Bob picked matching card " << card1.get_Suit() << " " << card1.get_Number() << endl;
              BobCards.erase(card1);
              AliceCards.erase(card2);
              foundMatch = true;
              break;
            }
          }
        }
        if (foundMatch) break;
      }

    }
    if (!foundMatch) break;
    AliceTurn = !AliceTurn;
  }
  cout << endl;

  cout << "Alice's cards:" << endl;
  for (const auto& card1 : AliceCards)
  {
    if(card1.get_Number() == 1 ||card1.get_Number() == 11 || card1.get_Number() == 12 ||card1.get_Number() == 13)
    {
      char number = ' ';
      if (card1.get_Number() == 1){number= 'a';}
      else if (card1.get_Number() == 11){number= 'j';}
      else if (card1.get_Number() == 12){number= 'q';}
      else if (card1.get_Number() == 13){number= 'k';}
      cout << card1.get_Suit() << " " << number << endl;
    }else
    {
      cout << card1.get_Suit() << " " << card1.get_Number() << endl;
    }
  }
  cout << endl;

  cout << "Bob's cards:" << endl;
  for (const auto& card1 : BobCards)
  {
    if(card1.get_Number() == 1 ||card1.get_Number() == 11 || card1.get_Number() == 12 ||card1.get_Number() == 13)
    {
      char number = ' ';
      if (card1.get_Number() == 1){number= 'a';}
      else if (card1.get_Number() == 11){number= 'j';}
      else if (card1.get_Number() == 12){number= 'q';}
      else if (card1.get_Number() == 13){number= 'k';}
      cout << card1.get_Suit() << " " << number << endl;
    }else
    {
      cout << card1.get_Suit() << " " << card1.get_Number() << endl;
    }
  }

  
  return 0;
}





