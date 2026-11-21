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

    void preOrder(Node *root)
    {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node *root)
    {
        if (root == nullptr)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    void inOrder(Node *root)
    {
        if (root == nullptr)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    /*
    Use these in main.cpp
    tree t;
    */
};

#endif