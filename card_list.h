// card_list.h
// Author: Albert Nguyen
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include "card.h"

#include <iostream>

using namespace std;

class CardList {
public:
CardList();
~CardList();
bool insert(const Card& card);
bool find(const Card& card) const;
Card getSuccessor(const Card& card) const;
Card getPredecessor(const Card& card) const;
bool remove(const Card& card);
void compareCardList(const CardList &other)const;
void inorder() const;

private:
struct Node {
Card card;
Node *left, *right, *parent;
Node(const Card& c) : card(c), left(0), right(0), parent(0) { }
};
Node* root;
// Node* getNodeFor(const Card& card, Node* n) const;
void clear(Node *n);
bool insert(const Card& card, Node *n);
Node* getNodeFor(const Card& card, Node* n) const;
Node* getPredecessorNode(const Card& card) const;
Node* getSuccessorNode(const Card& card) const;
void inorder(Node* n) const;


};

#endif





