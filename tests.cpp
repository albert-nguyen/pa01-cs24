#include <iostream>
#include "card_list.h"

using namespace std;

int main() {
    // Create a BST named cardDeck
    CardList cardDeck;

    // Testing insert() function
    cout << "Testing insert() function:" << endl;
    Card diam8(2, 8);
    cardDeck.insert(diam8);
    Card diam1(2, 1);
    cardDeck.insert(diam1);
    Card spade13(3, 13);
    cardDeck.insert(spade13);
    Card spade12(3, 12);
    cardDeck.insert(spade12);
    Card heart10(4, 10);
    cardDeck.insert(heart10);
    Card club11(1, 11);
    cardDeck.insert(club11);
    Card diam5(2, 5);
    cardDeck.insert(diam5);
    Card diam1_dup(2, 1);
    cardDeck.insert(diam1);
    cout << endl;

    // Display cardDeck after inserting cards
    cout << "cardDeck after insertion in order: " << endl;
    cardDeck.inorder();
    cout << endl;

    //Testing find() function
    cout << "Testing find() function:" << endl;
    cout << "Finding card (s, k) "; (cardDeck.find(Card(3, 13)) ? cout << "Found\n" : cout << "Not found\n");
    cout << "Finding card (d, 6) "; (cardDeck.find(Card(2, 6)) ? cout << "Found\n" : cout << "Not found\n");
    cout << "Finding card (h, 10) "; (cardDeck.find(heart10) ? cout << "Found\n" : cout << "Not found\n");
    cout << "Finding card (c, 10) "; (cardDeck.find(Card(1, 10)) ? cout << "Found\n" : cout << "Not found\n");
    cout << "Finding card (c, j) "; (cardDeck.find(club11) ? cout << "Found\n" : cout << "Not found\n");

    // Testing getPredecessor() function
    cout << "Testing getPredecessor() function:" << endl;
    cout << "Predecessor of card (d, 8) "; 
    Card pred1 = cardDeck.getPredecessor(diam8);
    if (pred1.get_Number() == 0) cout << "No predecessor\n";
    else cout << pred1.get_suit() << " " << pred1.get_Number() << endl;
    cout << "Predecessor of card (s, k) "; 
    Card pred2 = cardDeck.getPredecessor(spade13);
    if (pred2.get_Number() == 0) cout << "No predecessor\n";
    else cout << pred2.get_suit() << " " << pred2.get_Number() << endl;
    cout << "Predecessor of card (c, j) "; 
    Card pred3 = cardDeck.getPredecessor(club11);
    if (pred3.get_Number() == 0) cout << "No predecessor\n";
    else cout << pred3.get_suit() << " " << pred3.get_Number() << endl;
    cout << "Predecessor of card (h, 10) "; 
    Card pred4 = cardDeck.getPredecessor(heart10);
    if (pred4.get_Number() == 0) cout << "No predecessor\n";
    else cout << pred4.get_suit() << " " << pred4.get_Number() << endl;
    cout << "Predecessor of card (h, a) "; 
    Card pred5 = cardDeck.getPredecessor(Card(4,1));
    if (pred5.get_Number() == 0) cout << "No predecessor\n";
    else cout << pred5.get_suit() << " " << pred5.get_Number() << endl;

    // Testing getSuccessor() function
    cout << "Testing getSuccessor() function:" << endl;
    cout << "Successor of card (s, k) "; 
    Card succ1 = cardDeck.getSuccessor(spade13);
    if (succ1.get_Number() == 0) cout << "No successor\n";
    else cout << succ1.get_suit() << " " << succ1.get_Number() << endl;
    cout << "Successor of card (d, 5) "; 
    Card succ2 = cardDeck.getSuccessor(diam5);
    if (succ2.get_Number() == 0) cout << "No successor\n";
    else cout << succ2.get_suit() << " " << succ2.get_Number() << endl;
    cout << "Successor of card (h, 10) "; 
    Card succ3 = cardDeck.getSuccessor(heart10);
    if (succ3.get_Number() == 0) cout << "No successor\n";
    else cout << succ3.get_suit() << " " << succ3.get_Number() << endl;
    cout << "Successor of card (c, j) "; 
    Card succ4 = cardDeck.getSuccessor(club11);
    if (succ4.get_Number() == 0) cout << "No successor\n";
    else cout << succ4.get_suit() << " " << succ4.get_Number() << endl;
    cout << "Successor of card (d, j) "; 
    Card succ5 = cardDeck.getSuccessor(Card(2,11));
    if (succ5.get_Number() == 0) cout << "No successor\n";
    else cout << succ5.get_suit() << " " << succ5.get_Number() << endl;

    // Testing remove() function
    cout << "Testing remove() function:" << endl;
    cout << endl;
    cout << "Removing card (s, k) "<< endl; 
    cardDeck.remove(spade13);
    cout << "cardDeck after removal: ";
    cardDeck.inorder();
    cout << endl;
    cout << "Removing card (c, j) "<< endl; 
    cardDeck.remove(club11);
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
    cout << "Removing card (d, 5) " << endl; 
    cardDeck.remove(Card(4, 5));
    cout << "cardDeck after removal: " << endl;
    cardDeck.inorder();
    cout << endl;

    return 0;
}