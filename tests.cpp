#include "card_list.h"
#include <iostream>
#include <string>

using namespace std;

void testInsertAndContains() {
    BST myTree;
    Card card1('c', "4");
    myTree.insert(card1);

    cout << "Test insert and contains:" << endl;
    if (myTree.contains(card1)) {
        cout << "  PASS: myTree contains card C4" << endl;
    }
    else {
        cout << "  FAIL: myTree does not contain card C4" << endl;
    }
}

void testSuccessorAndPredecessor() {
    BST myTree;
    Card card1('h', "2");
    Card card2('h', "4");
    Card card3('h', "7");
    myTree.insert(card1);
    myTree.insert(card2);
    myTree.insert(card3);

    const Card* successor = myTree.getSuccessorNode(card1);
    const Card* predecessor = myTree.getPredecessorNode(card3);

    cout << "Successor of " << card1.toString() << " is ";
    if (successor != nullptr) {
        cout << successor->toString() << endl;
    } else {
        cout << "nullptr" << endl;
    }

    cout << "Predecessor of " << card3.toString() << " is ";
    if (predecessor != nullptr) {
        cout << predecessor->toString() << endl;
    } else {
        cout << "nullptr" << endl;
    }
}

void testRemove() {
    BST myTree;
    Card card1('h', "5");
    myTree.insert(card1);
    myTree.remove(card1);

    cout << "Test remove:" << endl;
    if (!myTree.contains(card1)) {
        cout << "  PASS: Card H5 removed from myTree" << endl;
    }
    else {
        cout << "  FAIL: Card H5 still in myTree" << endl;
    }
}

void testCount() {
    BST myTree;
    Card card1('d', "8");
    Card card2('h', "9");
    myTree.insert(card1);
    myTree.insert(card2);

    cout << "Test count:" << endl;
    if (myTree.count() == 2) {
        cout << "  PASS: myTree size is 2" << endl;
    }
    else {
        cout << "  FAIL: myTree size is not 2" << endl;
    }
}

void testPrintDeck() {
    BST myTree;
    myTree.insert(Card('h', "2"));
    myTree.insert(Card('h', "3"));

    cout << "Test printDeck (in order):" << endl;
    myTree.printDeck();

    cout << "Test printDeck (reverse):" << endl;;
    myTree.printDeck(true);
}

void testIterator() {
    BST myTree;
    Card card1('c', "3");
    Card card2('c', "2");
    Card card3('c', "9");
    myTree.insert(card1);
    myTree.insert(card2);
    myTree.insert(card3);

    cout << "Test iterator in-order:" << endl;
    for (BST::Iterator it = myTree.begin(); it != myTree.end(); ++it) {
        cout << "  " << it->toString() << endl;
    }

    cout << "Test iterator reverse order:" << endl;
    for (BST::Iterator it = myTree.rbegin(); it != myTree.rend(); --it) {
        cout << "  " << it->toString() << endl;
    }
}

void testPlayGame() {
    BST alice, bob;
    alice.insert(Card('h', "3"));
    alice.insert(Card('s', "10"));
    alice.insert(Card('c', "a"));
    alice.insert(Card('c', "3"));
    alice.insert(Card('s', "5"));
    alice.insert(Card('h', "10"));
    alice.insert(Card('d', "a"));
    bob.insert(Card('c', "2"));
    bob.insert(Card('d', "a"));
    bob.insert(Card('h', "3"));
    bob.insert(Card('c', "3"));
    bob.insert(Card('d', "j"));
    bob.insert(Card('s', "10"));
    bob.insert(Card('h', "a"));

    cout << "Test playGame with match:" << endl;
    playGame(alice, bob);
}

void printMenu() {
    cout << "\n--- BST Test Menu ---\n";
    cout << "1. Test insert and contains\n";
    cout << "2. Test successor and predecessor\n";
    cout << "3. Test remove\n";
    cout << "4. Test count\n";
    cout << "5. Test printDeck\n";
    cout << "6. Test iterator\n";
    cout << "7. Test playGame\n";
    cout << "8. Run all tests\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void testAll(){
    testInsertAndContains();
    testSuccessorAndPredecessor();
    testRemove();
    testCount();
    testPrintDeck();
    testIterator();
    testPlayGame();

}

int main() {
    int choice;
    string input;

    do {
        printMenu();
        getline(cin, input);

        try {
            choice = stoi(input);
        } catch (...) {
            choice = -1; 
        }

        switch (choice) {
            case 1:
                testInsertAndContains();
                break;
            case 2:
                testSuccessorAndPredecessor();
                break;
            case 3:
                testRemove();
                break;
            case 4:
                testCount();
                break;
            case 5:
                testPrintDeck();
                break;
            case 6:
                testIterator();
                break;
            case 7:
                testPlayGame();
                break;
            case 8:
                testAll();
                break;
            case 0:
                cout << "Exiting tests. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid input. Please enter a number from 0 to 8.\n";
        }

    } while (choice != 0);

    return 0;
}













