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

    static void checkVal(node *r, string &x)
    {
        if (r == NULL)
            return;
        checkVal(r->left, x);
        x = x + to_string(r->data) + " ";
        checkVal(r->right, x);
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

    static void isSame(node *r1, node *r2)
    {
        string x = "";
        string y = "";
        checkVal(r1, x);
        checkVal(r2, y);
        if (x == y)
            cout << "All values are same in both trees\n"
                 << x << "\n"
                 << y << endl;
        else
            cout << "Not same" << endl;
    }
};

int main()
{
    Tree t1;
    t1.insert(3);
    t1.insert(6);
    t1.insert(9);
    t1.insert(8);
    t1.insert(2);
    Tree t2;
    t2.insert(9);
    t2.insert(8);
    t2.insert(6);
    t2.insert(2);
    t2.insert(3);
    Tree::isSame(t1.getRoot(), t2.getRoot());
}
