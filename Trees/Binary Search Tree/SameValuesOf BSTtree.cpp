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

    void inOrder(node *r, string &x)
    {
        if (r == NULL)
        {
            return;
        }
        inOrder(r->left, x);
        string w = to_string(r->data);
        x = x + (w + " ");
        inOrder(r->right, x);
    }

    node *get_root()
    {
        return root;
    }
};

int main()
{
    Tree t1;
    t1.inertBST(2);
    t1.inertBST(111);
    t1.inertBST(109);
    t1.inertBST(84);
    t1.inertBST(45);
    Tree t2;
    t2.inertBST(109);
    t2.inertBST(84);
    t2.inertBST(111);
    t2.inertBST(45);
    t2.inertBST(2);
    string tree1 = "";
    t1.inOrder(t1.get_root(), tree1);
    cout << "\n";
    string tree2 = "";
    t2.inOrder(t2.get_root(), tree2);
    cout << "\nTree 1: " << tree1 << endl;
    cout << "Tree 2: " << tree2 << endl;
    if (tree1 == tree2)
        cout << "\nAll values are same in the tree" << endl;
    else
        cout << "All values are not same in the tree." << endl;
}
