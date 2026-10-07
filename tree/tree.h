#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;


template <class T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T value)
    {
        data = value;
        left = right = NULL;
    }
};


template <class T>
class Tree
{
private:
    Node<T> *root;

   
    Node<T>* insert(Node<T>* node, T value)
    {
        if (node == NULL)
            return new Node<T>(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

  
    void inorder(Node<T>* node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    bool search(Node<T>* node, T key)
    {
        if (node == NULL)
            return false;

        if (node->data == key)
            return true;

        if (key < node->data)
            return search(node->left, key);

        return search(node->right, key);
    }

public:
    Tree()
    {
        root = NULL;
    }

    void insert(T value)
    {
        root = insert(root, value);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }

    bool search(T key)
    {
        return search(root, key);
    }

    friend ostream& operator<<(ostream &out, Tree<T> &t)
    {
        t.display();
        return out;
    }
};

#endif