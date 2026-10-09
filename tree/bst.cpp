#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node *root = NULL;

Node *insertNode(Node *p, int value) {
    if (p == NULL) {
         p = new Node;
         p->data = value;
         p->left = NULL;
         p->right = NULL;
    } else if (value < p->data)
         p->left = insertNode(p->left, value);
    else
         p->right = insertNode(p->right, value);
    return p;
}

int searchNode(Node *p, int key) {
    if (p == NULL)
        return 0;
    if (key == p->data)
        return 1;
    if (key < p->data)
        return searchNode(p->left, key);






    return searchNode(p->right, key);
}

Node *deleteNode(Node *p, int key) {
    if (p == NULL)
        return NULL;
    if (key < p->data)
        p->left = deleteNode(p->left, key);
    else if (key > p->data)
        p->right = deleteNode(p->right, key);
    else {
        if (p->left == NULL) {
            Node *temp = p->right;
            delete p;
            return temp;
        }
        if (p->right == NULL) {
            Node *temp = p->left;
            delete p;
            return temp;
        }
        Node *succ = p->right;
        while (succ->left != NULL)
            succ = succ->left;
        p->data = succ->data;
        p->right = deleteNode(p->right, succ->data);
    }
    return p;
}

void inorder(Node *p) {
    if (p == NULL)
        return;
    inorder(p->left);
    cout << p->data << " ";
    inorder(p->right);
}

int main() {
    int choice, value;
    do {
         cout << "\nMenu:\n";
         cout << "1. Insert\n";
         cout << "2. Delete\n";
         cout << "3. Search\n";
         cout << "4. Display (Inorder)\n";
         cout << "5. Quit\n";
         cout << "Enter your choice: ";
         cin >> choice;
         switch (choice) {
         case 1:
             cout << "Enter value to insert: ";
             cin >> value;
             if (searchNode(root, value))
                 cout << value << " already exists. Duplicates are not allowed.\n";
             else {
                 root = insertNode(root, value);
                 cout << "Inserted " << value << endl;
             }
             break;
         case 2:
             cout << "Enter value to delete: ";
             cin >> value;
             if (searchNode(root, value) == 0)
                 cout << value << " not found. Cannot delete.\n";
             else {
                 root = deleteNode(root, value);
                 cout << "Deleted " << value << endl;
             }
             break;
         case 3:
             cout << "Enter value to search: ";






              cin >> value;
              if (searchNode(root, value))
                   cout << value << " is found in the BST.\n";
              else
                   cout << value << " is not found in the BST.\n";
              break;
          case 4:
              if (root == NULL)
                   cout << "Tree is empty.\n";
              else {
                   cout << "Inorder (sorted): ";
                   inorder(root);
                   cout << endl;
              }
              break;
          case 5:
              cout << "Exiting program.\n";
              break;
          default:
              cout << "Invalid choice. Please try again.\n";
          }
      } while (choice != 5);
      return 0;
}
