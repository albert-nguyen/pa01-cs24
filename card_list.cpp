// card_list.cpp
// Author: Albert Nguyen
// Implementation of the classes defined in card_list.h

#include "card_list.h"

using namespace std;

CardList::CardList() {
root = nullptr;
}

CardList::~CardList() {
clear(root);
}

void CardList::clear(Node *n) {
if (n != nullptr) {
if (n->left != nullptr) {
clear(n->left);
}
if (n->right != nullptr) {
clear(n->right);
}
delete n;
}
}

bool CardList::insert(const Card& card) {
if (root == nullptr) {
root = new Node(card);
return true;
}
else {
return insert(card, root);
}
}


bool CardList::insert(const Card& card, Node *n) {
if (card.get_Number() == n->card.get_Number() && card.get_suit() == n->card.get_suit()) {
return false;
}
else if (card < n->card) {
if (n->left != nullptr) {
return insert(card, n->left);
}
else {
n->left = new Node(card);
n->left->parent = n;
return true;
}
}
else {
if (n->right != nullptr) {
return insert(card, n->right);
}
else {
n->right = new Node(card);
n->right->parent = n;
return true;
}
}
}

CardList::Node* CardList::getNodeFor(const Card& card, Node* n) const {
if (n == nullptr) {
return nullptr;
}
if (card.get_Number() == n->card.get_Number() && card.get_suit() == n->card.get_suit()) {
return n;
}
else if (card < n->card) {
return getNodeFor(card, n->left);
}
else {
return getNodeFor(card, n->right);
}
}

bool CardList::find(const Card& card) const {
if (getNodeFor(card, root)) {
return true;
}
else {
return false;
}
}

CardList::Node* CardList::getPredecessorNode(const Card& card) const {
Node* n = getNodeFor(card, root);
Node* curr = nullptr;
if (n == nullptr) {
return nullptr;
}
else if (n->left != nullptr) {
n = n->left;
while (n->right != nullptr) {
n = n->right;
}
curr = n;
}
else {
while (n->parent != nullptr) {
if (n->parent->card < card) {
curr = n->parent;
break;
}
else {
n = n->parent;
}
}
}
return curr;
}

Card CardList::getPredecessor(const Card& card) const {
Card temp;
Node* predecessor = getPredecessorNode(card);
if (predecessor) {
temp = predecessor->card;
}
else {
return temp;
}
return temp;
}

CardList::Node* CardList::getSuccessorNode(const Card& card) const {
Node* n = getNodeFor(card, root);
Node* curr = nullptr;
if (n == nullptr) {
return nullptr;
}
else if (n->right != nullptr) {
n = n->right;
while (n->left != nullptr) {
n = n->left;
}
curr = n;
}
else {
while (n->parent != nullptr) {
if (n->parent->card.get_suit() > card.get_suit() || (n->parent->card.get_suit() == card.get_suit() && n->parent->card.get_Number() > card.get_Number())) {
curr = n->parent;
break;
}
else {
n = n->parent;
}
}
}
return curr;
}

Card CardList::getSuccessor(const Card& card) const {
Card temp;
Node* successor = getSuccessorNode(card);
if (successor != nullptr) {
temp = successor->card;
}
return temp;
}




bool CardList::remove(const Card& card){
Node* n = getNodeFor(card, root);
if(!n) return false;
if(!getNodeFor(card, root)) {
return false;
}

Node* temp = n->parent;
if (n->left == nullptr && n->right == nullptr) {
if (n == root) {
root = nullptr;
}
else {
if (temp->left == n) {
temp->left = nullptr;
}
else {
temp->right = nullptr;
}
}


}
else if (n->right == nullptr && n->left != nullptr) {
    if (n == root) {
    root = n->left;
    }
    else {
        if(temp->left == n) {
            temp->left = n->left;
        }
        else {
            temp->right = n->left;
        }
    }
    n->left->parent = temp;
    delete n;
}
else if (n->left == nullptr && n->right != nullptr) {
if (n == root) {
root = n->right;
}
else {
if (temp->left == n) {
temp->left = n->right;
}
else {
temp->right = n->right;
}
}
n->right->parent = temp;
delete n;
}
else {
// Node* successor = getSuccessorNode(card);
// n->card = successor->card;
// remove(successor->card);

    Card s = getSuccessor(card);
    remove(s);
    n->card = s;
// if (successor->parent->left == successor) {
//         successor->parent->left = nullptr;
//     } else {
//         successor->parent->right = nullptr;
//     }
//     delete successor;
}

return true;
}




void CardList::compareCardList(const CardList &other)const
{

}
void CardList::inorder() const
{
    inorder(root);
}
void CardList::inorder(Node* n) const
{
    if (n != nullptr)
    {
        if (n->left != nullptr)
        {
            inorder(n->left);
        }
        if(n->card.get_Number() == 1||n->card.get_Number() == 11||n->card.get_Number() == 12||n->card.get_Number() == 13){
        char number = ' ';
        if (n->card.get_Number() == 1){number= 'a';}
        else if (n->card.get_Number() == 11){number= 'j';}
        else if (n->card.get_Number() == 12){number= 'q';}
        else if (n->card.get_Number() == 13){number= 'k';}
        char j = n->card.get_suit();
        cout << j << " " << number << endl;
        }else
        {
            int i = n->card.get_Number();
            char j = n->card.get_suit();
            cout << j << " " << i << endl;
        }
        if (n-> right != nullptr)
        {
            inorder(n->right);
        }

    }
    else 
    {
        return;
    }
}