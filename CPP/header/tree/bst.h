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

    Node *deleteBst(Node *root, int target)
    {
        if (root == nullptr)
            return nullptr;
        else if (root->data > target)
            root->left = deleteBst(root->left, target);
        else if (root->data < target)
            root->right = deleteBst(root->right, target);
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteBst(root->right, temp->data);
            }
        }
        return root;
    }
    void deleteBst(int target)
    {
        root = deleteBst(root, target);
    }

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

    //     /*
    // bst t;
    // t.insert(50);
    // t.insert(30);
    // t.insert(70);
    // t.insert(20);
    // t.insert(40);
    // t.insert(60);
    // t.insert(80);

    // cout << "After insert : \n";
    // t.traverse();

    // t.search(90);

    // t.deleteBst(30);
    // cout << "After delete : \n";
    // t.traverse();
    //     */
};
#endif