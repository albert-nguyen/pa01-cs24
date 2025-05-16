#include <iostream>
#include "card_list.h"

using namespace std;

int main() {
    // Create a BST named cardDeck
    CardList cardDeck;

    // Testing insert() function
    cout << "Testing insert() function:" << endl;
    Card diam7(2, 7);
    cardDeck.insert(diam7);
    Card diam2(2, 2);
    cardDeck.insert(diam2);
    Card spade11(3, 11);
    cardDeck.insert(spade11);
    Card spade12(3, 12);
    cardDeck.insert(spade12);
    Card heart10(4, 10);
    cardDeck.insert(heart10);
    Card club12(1, 12);
    cardDeck.insert(club12);
    Card diam8(2, 8);
    cardDeck.insert(diam8);
    Card diam1_dup(2, 2);
    cardDeck.insert(diam2);
    cout << endl;

    // Display cardDeck after inserting cards
    cout << "cardDeck after insertion in order: " << endl;
    cardDeck.inorder();
    cout << endl;

    //Testing find() function
    cout << "Testing find() function:" << endl;
    cout << "Finding card (s, q) "; (cardDeck.find(Card(3, 12)) ? cout << "Found\n" : cout << "Not found\n");
    cout << "Finding card (d, 6) "; (cardDeck.find(Card(2, 6)) ? cout << "Found\n" : cout << "Not found\n");
    cout << "Finding card (h, 10) "; (cardDeck.find(heart10) ? cout << "Found\n" : cout << "Not found\n");
    cout << "Finding card (c, 10) "; (cardDeck.find(Card(1, 10)) ? cout << "Found\n" : cout << "Not found\n");
    cout << "Finding card (c, q) "; (cardDeck.find(club12) ? cout << "Found\n" : cout << "Not found\n");

    // Testing getPredecessor() function
    cout << "Testing getPredecessor() function:" << endl;
    cout << "Predecessor of card (d, 7) "; 
    Card pred1 = cardDeck.getPredecessor(diam7);
    if (pred1.get_Number() == 0) cout << "No predecessor\n";
    else cout << pred1.get_Suit() << " " << pred1.get_Number() << endl;
    cout << "Predecessor of card (s, q) "; 
    Card pred2 = cardDeck.getPredecessor(spade12);
    if (pred2.get_Number() == 0) cout << "No predecessor\n";
    else cout << pred2.get_Suit() << " " << pred2.get_Number() << endl;
    cout << "Predecessor of card (c, j) "; 
    Card pred3 = cardDeck.getPredecessor(club12);
    if (pred3.get_Number() == 0) cout << "No predecessor\n";
    else cout << pred3.get_Suit() << " " << pred3.get_Number() << endl;
    cout << "Predecessor of card (h, 10) "; 
    Card pred4 = cardDeck.getPredecessor(heart10);
    if (pred4.get_Number() == 0) cout << "No predecessor\n";
    else cout << pred4.get_Suit() << " " << pred4.get_Number() << endl;
    cout << "Predecessor of card (h, a) "; 
    Card pred5 = cardDeck.getPredecessor(Card(4,1));
    if (pred5.get_Number() == 0) cout << "No predecessor\n";
    else cout << pred5.get_Suit() << " " << pred5.get_Number() << endl;

    // Testing getSuccessor() function
    cout << "Testing getSuccessor() function:" << endl;
    cout << "Successor of card (s, q) "; 
    Card succ1 = cardDeck.getSuccessor(spade12);
    if (succ1.get_Number() == 0) cout << "No successor\n";
    else cout << succ1.get_Suit() << " " << succ1.get_Number() << endl;
    cout << "Successor of card (d, 8) "; 
    Card succ2 = cardDeck.getSuccessor(diam8);
    if (succ2.get_Number() == 0) cout << "No successor\n";
    else cout << succ2.get_Suit() << " " << succ2.get_Number() << endl;
    cout << "Successor of card (h, 10) "; 
    Card succ3 = cardDeck.getSuccessor(heart10);
    if (succ3.get_Number() == 0) cout << "No successor\n";
    else cout << succ3.get_Suit() << " " << succ3.get_Number() << endl;
    cout << "Successor of card (c, q) "; 
    Card succ4 = cardDeck.getSuccessor(club12);
    if (succ4.get_Number() == 0) cout << "No successor\n";
    else cout << succ4.get_Suit() << " " << succ4.get_Number() << endl;
    cout << "Successor of card (d, j) "; 
    Card succ5 = cardDeck.getSuccessor(Card(2,11));
    if (succ5.get_Number() == 0) cout << "No successor\n";
    else cout << succ5.get_Suit() << " " << succ5.get_Number() << endl;

    // Testing remove() function
    cout << "Testing remove() function:" << endl;
    cout << endl;
    cout << "Removing card (s, q) "<< endl; 
    cardDeck.remove(spade12);
    cout << "cardDeck after removal: ";
    cardDeck.inorder();
    cout << endl;
    cout << "Removing card (c, j) "<< endl; 
    cardDeck.remove(club12);
    cout << "cardDeck after removal: "<< endl;
    cardDeck.inorder();
    cout << endl;
    cout << "Removing card (c, 4) "<<endl; 
    cardDeck.remove(Card(1, 4));
    cout << "cardDeck after removal: " << endl;
    cardDeck.inorder();
    cout << endl;
    cout << "Removing card (h, 10) " << endl; 
    cardDeck.remove(Card(4, 10));
    cout << "cardDeck after removal: "<< endl;
    cardDeck.inorder();
    cout << endl;
    cout << "Removing card (d, 7) " << endl; 
    cardDeck.remove(Card(2, 7));
    cout << "cardDeck after removal: " << endl;
    cardDeck.inorder();
    cout << endl;

    return 0;
}





