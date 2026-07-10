#include "tree.h"

Tree::Tree()
{
    root=NULL;
}

Node* Tree::insert(Node *root,int value)
{
    if(root==NULL)
    {
        root=new Node;
        root->data=value;
        root->left=root->right=NULL;
        return root;
    }

    if(value<root->data)
        root->left=insert(root->left,value);
    else
        root->right=insert(root->right,value);

    return root;
}

void Tree::insert(int value)
{
    root=insert(root,value);
}

Node* Tree::search(Node *root,int key)
{
    if(root==NULL || root->data==key)
        return root;

    if(key<root->data)
        return search(root->left,key);

    return search(root->right,key);
}

void Tree::search(int key)
{
    if(search(root,key))
        cout<<"Element Found\n";
    else
        cout<<"Element Not Found\n";
}

void Tree::inorder(Node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void Tree::preorder(Node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void Tree::postorder(Node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void Tree::inorder()
{
    cout<<"\nInorder : ";
    inorder(root);
}

void Tree::preorder()
{
    cout<<"\nPreorder : ";
    preorder(root);
}

void Tree::postorder()
{
    cout<<"\nPostorder : ";
    postorder(root);
}

Node* Tree::minValue(Node *node)
{
    while(node->left!=NULL)
        node=node->left;

    return node;
}

Node* Tree::deleteNode(Node *root,int key)
{
    if(root==NULL)
        return root;

    if(key<root->data)
        root->left=deleteNode(root->left,key);

    else if(key>root->data)
        root->right=deleteNode(root->right,key);

    else
    {
        if(root->left==NULL)
        {
            Node *temp=root->right;
            delete root;
            return temp;
        }

        else if(root->right==NULL)
        {
            Node *temp=root->left;
            delete root;
            return temp;
        }

        Node *temp=minValue(root->right);

        root->data=temp->data;

        root->right=deleteNode(root->right,temp->data);
    }

    return root;
}

void Tree::deleteNode(int key)
{
    root=deleteNode(root,key);
}