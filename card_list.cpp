// card_list.cpp
// Author: Albert Nguyen
// Implementation of the classes defined in card_list.h


#include "card_list.h"
#include <iostream>
#include <string>

using namespace std;

BST::BST() {
    root = nullptr;
    size = 0;
}

BST::~BST() {
    clear(root);
}

void BST::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

void BST::insert(Card card) {
    root = insert(root, card, nullptr);
}

BST::Node* BST::insert(Node* node, Card card, Node* parent) {
    if (node == nullptr) {
        size++;
        Node* newNode = new Node(card);
        newNode->parent = parent;
        return newNode;
    }
    if (card < node->data)
        node->left = insert(node->left, card, node);
    else if (card > node->data)
        node->right = insert(node->right, card, node);
    return node;
}

void BST::remove(Card card) {
    root = remove(root, card);
}

BST::Node* BST::remove(Node* node, Card card) {
    if (node == nullptr) {
        return nullptr;
    }
    if (card < node->data) {
        node->left = remove(node->left, card);
    }
    else if (card > node->data) {
        node->right = remove(node->right, card);
    }
    else {
        size--;
        if (!node->left) {
            Node* rightChild = node->right;
            delete node;
            return rightChild;
        }
        else if (!node->right) {
            Node* leftChild = node->left;
            delete node;
            return leftChild;
        }
        else {
            Node* succ = getMin(node->right);
            node->data = succ->data;
            node->right = remove(node->right, succ->data);
        }
    }
    return node;
}

bool BST::contains(Card card) const {
    Node* result = find(root, card);
    return result != nullptr;
}

BST::Node* BST::find(Node* node, Card card) const {
    if (node == nullptr) {
        return nullptr;
    }
    if (card == node->data) {
        return node;
    }
    if (card < node->data) {
        return find(node->left, card);
    }
    return find(node->right, card);
}

int BST::count() const {
    return size;
}

void BST::printDeck() const {
    printInOrder(root);
}

void BST::printDeck(bool reverse) const {
    if (reverse) {
        printReverseOrder(root);
    } else {
        printInOrder(root);
    }
}

void BST::printInOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    printInOrder(node->left);
    node->data.printCard();
    printInOrder(node->right);
}

void BST::printReverseOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    printReverseOrder(node->right);
    std::cout << node->data.toString() << endl;
    printReverseOrder(node->left);
}

const Card* BST::getSuccessorNode(Card card) const {
    Node* node = find(root, card);
    if (!node) return nullptr;
    Node* successor = getSuccessor(node);
    if (successor) {
        return &(successor->data);
    } else {
        return nullptr;
    }
}

const Card* BST::getPredecessorNode(Card card) const {
    Node* node = find(root, card);
    if (!node) return nullptr;
    Node* predecessor = getPredecessor(node);
    if (predecessor) {
        return &(predecessor->data);
    } else {
        return nullptr;
    }
}

BST::Node* BST::getMin(Node* node) const {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

BST::Node* BST::getMax(Node* node) const {
    while (node && node->right) {
        node = node->right;
    }
    return node;
}

BST::Node* BST::getSuccessor(Node* node) const {
    if (!node) {
        return nullptr;
    }

    if (node->right) {
        return getMin(node->right);
    }
    Node* p = node->parent;
    while (p && node == p->right) {
        node = p;
        p = p->parent;
    }
    return p;
}

BST::Node* BST::getPredecessor(Node* node) const {
    if (!node) {
        return nullptr;
    }

    if (node->left) {
        return getMax(node->left);
    }
    Node* p = node->parent;
    while (p && node == p->left) {
        node = p;
        p = p->parent;
    }
    return p;
}

bool BST::empty() const {
    if (root == nullptr) {
        return true;
    }
    return false;
}

BST::Iterator::Iterator(Node* node, const BST* bst) {
    current = node;
    tree = bst;
}

const Card& BST::Iterator::operator*() const {
    return current->data;
}

const Card* BST::Iterator::operator->() const {
    return &(current->data);
}

BST::Iterator& BST::Iterator::operator++() {
    current = tree->getSuccessor(current);
    return *this;
}

BST::Iterator& BST::Iterator::operator--() {
    current = tree->getPredecessor(current);
    return *this;
}

bool BST::Iterator::operator==(const BST::Iterator& other) const {
    return current == other.current;
}

bool BST::Iterator::operator!=(const BST::Iterator& other) const {
    return current != other.current;
}

BST::Iterator BST::begin() const {
    return Iterator(getMin(root), this);
}

BST::Iterator BST::end() const {
    return Iterator(nullptr, this);
}

BST::Iterator BST::rbegin() const {
    return Iterator(getMax(root), this);
}

BST::Iterator BST::rend() const {
    return Iterator(nullptr, this);
}

//playGame

void playGame(BST& alice, BST& bob){
    while (!alice.empty() && !bob.empty()){
        bool match = false;
        for (auto it = alice.begin(); it != alice.end(); ++it) {
          if(bob.contains(*it)){
            cout << "Alice picked matching card ";
            Card toRemove = *it;
            toRemove.printCard();
            ++it;
            bob.remove(toRemove);
            alice.remove(toRemove);
            match = true;
            break;
          }
          else match = false;
        }
        if (!match) break;
        for (auto it = bob.rbegin(); it != bob.rend(); --it) {
          if(alice.contains(*it)){
            cout << "Bob picked matching card ";
            Card toRemove = *it;
            toRemove.printCard();
            ++it;
            bob.remove(toRemove);
            alice.remove(toRemove);
            match = true;
            break;
          }
          else match = false;
        }
        if (!match) break;
      }
      cout << endl << "Alice's cards:\n";
      alice.printDeck();
    
      cout << endl << "Bob's cards:\n";
      bob.printDeck();
      return;
}