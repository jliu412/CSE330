#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

class BinarySearchTree
{
private:
    struct Node
    {
        int key;
        string data;
        Node *left;
        Node *right;
        Node *parent;
    };

public:
    Node *root;
    BinarySearchTree() { root = nullptr; }
    bool isEmpty() const { return root == nullptr; }
    void insertNode(int, string);
    Node *searchNode(Node *, int, string);
    void preorderTraversal(Node *);
    void inorderTraversal(Node *);
    void postorderTraversal(Node *);
    Node *findMax(Node *);
    void removeMax(Node *);
    Node *successor(Node *);
    void deleteNode(Node *);
};

void BST();

#endif