#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
    Node *root;

    Node* insert(Node*,int);
    Node* search(Node*,int);
    Node* deleteNode(Node*,int);

    Node* minValue(Node*);

    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);

public:

    Tree();

    void insert(int);
    void search(int);
    void deleteNode(int);

    void inorder();
    void preorder();
    void postorder();
};

