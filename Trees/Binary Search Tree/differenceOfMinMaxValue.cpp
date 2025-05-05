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

    node *get_root()
    {
        return root;
    }

    void inOrder(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        inOrder(r->left);
        cout << r->data << " ";
        inOrder(r->right);
    }

    void differenceMinMax(node *r)
    {
        node *maxR = r->right;
        node *minR = r->left;
        while (maxR->right != NULL)
            maxR = maxR->right;
        while (minR->left != NULL)
            minR = minR->left;
        cout << "\nDifference = " << maxR->data - minR->data << endl;
    }
};

int main()
{
    Tree t1;
    t1.inertBST(43);
    t1.inertBST(1);
    t1.inertBST(23);
    t1.inertBST(66);
    t1.inertBST(11);
    t1.inertBST(31);
    t1.inertBST(54);
    t1.inertBST(77);
    t1.inertBST(100);
    t1.inertBST(7);
    t1.inertBST(6);
    t1.inOrder(t1.get_root());
    t1.differenceMinMax(t1.get_root());
}