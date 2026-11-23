#ifndef TREE_H
#define TREE_H
#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *left, *right;
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

class tree
{
public:
    tree()
    {
        Node *root = new Node('a');
        root->left = new Node('b');
        root->left->left = new Node('d');
        root->left->right = new Node('e');
        root->left->left->left = new Node('g');
        root->left->left->right = new Node('h');
        root->left->right->right = new Node('i');
        root->right = new Node('c');
        root->right->left = new Node('f');
        root->right->left->right = new Node('j');

        cout << "Pre order : ";
        preOrder(root);
        cout << endl;

        cout << "Post order : ";
        postOrder(root);
        cout << endl;

        cout << "In order : ";
        inOrder(root);
        cout << endl;
    }

    void preOrder(Node *n)
    {
        if (n == nullptr)
            return;
        cout << n->data << " ";
        preOrder(n->left);
        preOrder(n->right);
    }

    void postOrder(Node *n)
    {
        if (n == nullptr)
            return;
        postOrder(n->left);
        postOrder(n->right);
        cout << n->data << " ";
    }

    void inOrder(Node *n)
    {
        if (n == nullptr)
            return;
        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }

    /*
    Use these in main.cpp
    tree t;
    */
};

#endif