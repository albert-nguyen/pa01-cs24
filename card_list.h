// card_list.h
// Author: Albert Nguyen
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"
#include <iostream>
#include <string>

class BST {
private:
    struct Node {
        Card data;
        Node* left;
        Node* right;
        Node* parent;

        Node(Card card) : data(card), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root;
    int size;

    void clear(Node* node);
    void printInOrder(Node* node) const;
    void printReverseOrder(Node* node) const;
    Node* insert(Node* node, Card card, Node* parent);
    Node* find(Node* node, Card card) const;
    Node* remove(Node* node, Card card);
    Node* getMin(Node* node) const;
    Node* getMax(Node* node) const;
    Node* getSuccessor(Node* node) const;
    Node* getPredecessor(Node* node) const;

public:
    BST();
    ~BST();

    void insert(Card card);
    void remove(Card card);
    bool contains(Card card) const;
    int count() const;
    void printDeck(bool reverse) const;
    void printDeck() const;        
    bool empty() const;

    Node* getNodeFor(Card c, Node* node) const;
    const Card* getSuccessorNode(Card card) const;
    const Card* getPredecessorNode(Card card) const;

    class Iterator {
    private:
        Node* current;
        const BST* tree;

    public:
        Iterator(Node* node = nullptr, const BST* bst = nullptr);

        const Card& operator*() const;
        const Card* operator->() const;
        Iterator& operator++();
        Iterator& operator--();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin() const;
    Iterator end() const;
    Iterator rbegin() const;
    Iterator rend() const;

    friend void playGame(BST& alice, BST& bob);
};

#endif






