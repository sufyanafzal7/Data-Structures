#include <iostream>
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
    int *arr;
    int index;

    static void inOrderStructure(node *r, string &x)
    {
        if (r == NULL)
            return;

        inOrderStructure(r->left, x);
        x += "1";
        inOrderStructure(r->right, x);
        x += "0";
    }

public:
    Tree()
    {
        root = NULL;
        arr = new int[50];
        index = 0;
    };

    void insert(int x)
    {
        node *n = new node;
        n->data = x;
        n->left = NULL;
        n->right = NULL;
        if (root == NULL)
        {
            root = n;
            return;
        }
        node *current = root;
        node *parent = NULL;
        while (current != NULL)
        {
            parent = current;
            if (x > current->data)
                current = current->right;
            else if (x < current->data)
                current = current->left;
        }
        if (x > parent->data)
            parent->right = n;
        else if (x < parent->data)
            parent->left = n;
    }

    node *getRoot()
    {
        return root;
    }

    node *findMin(node *r)
    {
        while (r->left != NULL)
            r = r->left;
        return r;
    }

    static void isSameStructure(node *x, node *y)
    {
        string a, b = "";
        inOrderStructure(x, a);
        inOrderStructure(y, b);
        if (a == b)
            cout << "Structures are same" << endl;
        else
            cout << "Not same" << endl;
    }
};

int main()
{
    Tree t1;
    t1.insert(43);
    t1.insert(63);
    t1.insert(2322);
    t1.insert(573);
    Tree t2;
    t2.insert(15);
    t2.insert(6);
    t2.insert(10);
    t2.insert(8);
    Tree::isSameStructure(t1.getRoot(), t2.getRoot());
}
