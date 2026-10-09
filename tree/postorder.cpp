#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node *createTree() {
    int value;
    cout << "Enter node value (-1 for no node): ";
    cin >> value;
    if (value == -1)
        return NULL;
    Node *p = new Node;
    p->data = value;
    cout << "Left child of " << value << endl;
    p->left = createTree();
    cout << "Right child of " << value << endl;
    p->right = createTree();
    return p;
}

void postorder(Node *p) {
    if (p == NULL)
        return;






      postorder(p->left);
      postorder(p->right);
      cout << p->data << " ";
}

int main() {
    Node *root;
    cout << "Enter the root node\n";
    root = createTree();
    if (root == NULL)
        cout << "Tree is empty.\n";
    else {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }
    return 0;
}
