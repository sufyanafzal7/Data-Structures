#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    node *right;
    node *left;
    int data;
};

class Tree
{
private:
    node *root;

public:
    Tree()
    {
        root = NULL;
    };
    void inertBST(int x)
    {
        node *n = new node;
        n->right = NULL;
        n->left = NULL;
        n->data = x;
        if (root == NULL)
        {
            root = n;
        }
        else
        {
            node *parent = NULL;
            node *current = root;
            while (current != NULL)
            {
                parent = current;
                if (x > current->data)
                    current = current->right;
                else
                    current = current->left;
            }
            if (x > parent->data)
                parent->right = n;
            else
                parent->left = n;
        }
    }

    void inOrder(node *r, string &s)
    {
        if (r == NULL)
        {
            return;
        }
        inOrder(r->left, s);
        s += "0";
        cout << r->data << " ";
        inOrder(r->right, s);
        s += "1";
    }

    node *get_root()
    {
        return root;
    }
};

int main()
{
    Tree t1;
    t1.inertBST(43);
    t1.inertBST(23);
    t1.inertBST(66);
    t1.inertBST(11);
    t1.inertBST(31);
    t1.inertBST(54);
    t1.inertBST(77);
    t1.inertBST(7);
    t1.inertBST(6);
    string tree1 = "";
    t1.inOrder(t1.get_root(), tree1);
    cout << "\nTree: " << tree1 << endl;
    Tree t2;
    t2.inertBST(53);
    t2.inertBST(43);
    t2.inertBST(99);
    t2.inertBST(32);
    t2.inertBST(50);
    t2.inertBST(70);
    t2.inertBST(102);
    t2.inertBST(11);
    t2.inertBST(4);
    string tree2 = "";
    t2.inOrder(t2.get_root(), tree2);
    cout << "\nTree: " << tree2 << endl;
    if (strcasecmp(tree1.c_str(), tree2.c_str()) == 0)
        cout << "Structures are Equal" << endl;
    else
        cout << "Structures are not equal" << endl;
}
