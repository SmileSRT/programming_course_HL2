#include "BinaryTree.h"

#include <iostream>

Node::Node(int value){
    data = value;
    left = nullptr;
    right = nullptr;
}


BinaryTree::BinaryTree(){
    root = nullptr;
}

void BinaryTree::insert(int value){
    if (root == nullptr) {
        root = std::make_unique<Node>(value);
        return;
    }

    Node* currentNode = root.get();
    while (true) {
        if (value < currentNode->data) {
            if (currentNode->left == nullptr) {
                currentNode->left = std::make_unique<Node>(value);
                return;
            }
            currentNode = currentNode->left.get();
        } else {
            if (currentNode->right == nullptr) {
                currentNode->right = std::make_unique<Node>(value);
                return;
            }
            currentNode = currentNode->right.get();
        }
    }
}