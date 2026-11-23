#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

class bst
{
public:
    Node *root = nullptr;

    Node *insert(Node *root, int value)
    {
        if (root == nullptr)
            return new Node(value);
        if (value < root->data)
            root->left = insert(root->left, value);
        if (value > root->data)
            root->right = insert(root->right, value);
        return root;
    }
    void insert(int value) { root = insert(root, value); }

    bool search(Node *root, int target)
    {
        if (root == nullptr)
            return false;
        if (target == root->data)
            return true;
        if (target < root->data)
            return search(root->left, target);
        if (target > root->data)
            return search(root->right, target);
        return false;
    }
    void search(int target)
    {
        if (search(root, target))
            cout << "\nFound\n";
        else
            cout << "\nNot found\n";
    }

    Node *findMin(Node *root)
    {
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }

    Node *deleteNode(Node *root, int target) {}

    void preOrder(Node *n)
    {
        if (n == nullptr)
            return;
        cout << n->data << " ";
        preOrder(n->left);
        preOrder(n->right);
    }
    void inOrder(Node *n)
    {
        if (n == nullptr)
            return;
        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }

    void traverse()
    {
        cout << "Pre order : ";
        preOrder(root);
        cout << "\nIn order : ";
        inOrder(root);
    }
};

#endif