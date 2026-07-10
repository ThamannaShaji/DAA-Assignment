#include "tree.h"

int main()
{
    Tree t;

    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);

    t.inorder();

    t.preorder();

    t.postorder();

    cout<<"\n";

    t.search(40);

    t.deleteNode(30);

    t.inorder();

    return 0;
}