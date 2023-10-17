#pragma once

#include <memory>


struct Node {
    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int value);
};


class BinaryTree {
    std::unique_ptr<Node> root;

public:
    BinaryTree();

    void insert(int value);
};