#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node *root = NULL;

Node *newNode(int value) {
    Node *p = new Node;
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(int value) {
    Node *p = newNode(value);
    if (root == NULL) {
        root = p;
        return;
    }
    Node *q[100];
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front < rear) {
        Node *cur = q[front++];
        if (cur->left == NULL) {
            cur->left = p;
            return;
        }
        q[rear++] = cur->left;
        if (cur->right == NULL) {
            cur->right = p;
            return;






        }
        q[rear++] = cur->right;
    }
}

void levelOrder() {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }
    Node *q[100];
    int front = 0, rear = 0;
    q[rear++] = root;
    cout << "Level-order: ";
    while (front < rear) {
        Node *cur = q[front++];
        cout << cur->data << " ";
        if (cur->left != NULL)
            q[rear++] = cur->left;
        if (cur->right != NULL)
            q[rear++] = cur->right;
    }
    cout << endl;
}

int countNodes(Node *p) {
    if (p == NULL)
        return 0;
    return 1 + countNodes(p->left) + countNodes(p->right);
}

int height(Node *p) {
    if (p == NULL)
        return 0;
    int lh = height(p->left);
    int rh = height(p->right);
    if (lh > rh)
        return lh + 1;
    return rh + 1;
}

int search(Node *p, int key) {
    if (p == NULL)
        return 0;
    if (p->data == key)
        return 1;
    return search(p->left, key) || search(p->right, key);
}

int main() {
    int choice, value;
    do {
         cout << "\nMenu:\n";
         cout << "1. Insert\n";
         cout << "2. Display (Level-order)\n";
         cout << "3. Count nodes\n";
         cout << "4. Height of tree\n";
         cout << "5. Search\n";
         cout << "6. Quit\n";
         cout << "Enter your choice: ";
         cin >> choice;
         switch (choice) {
         case 1:
             cout << "Enter value to insert: ";
             cin >> value;
             insert(value);
             cout << "Inserted " << value << endl;
             break;
         case 2:
             levelOrder();
             break;
         case 3:
             cout << "Number of nodes = " << countNodes(root) << endl;
             break;
         case 4:






              cout << "Height of tree = " << height(root) << endl;
              break;
          case 5:
              cout << "Enter value to search: ";
              cin >> value;
              if (search(root, value))
                   cout << value << " is found in the tree.\n";
              else
                   cout << value << " is not found in the tree.\n";
              break;
          case 6:
              cout << "Exiting program.\n";
              break;
          default:
              cout << "Invalid choice. Please try again.\n";
          }
      } while (choice != 6);
      return 0;
}
