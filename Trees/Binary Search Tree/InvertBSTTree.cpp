#include <iostream>
using namespace std;

struct node
{
    node *right;
    node *left;
    int data;
};

int sumNodes = 0;
int sumLeaf = 0;

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
            root = n;
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

    void inOrder(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        inOrder(r->left);
        cout << r->data << " ";
        sumNodes += r->data;
        if (r->left == NULL && r->right == NULL)
            sumLeaf += r->data;
        inOrder(r->right);
    }

    node *search(node *r, int key)
    {
        if (r == NULL)
            return NULL;
        if (r->data == key)
            return r;
        else if (r->data > key)
            return search(r->left, key);
        else
            return search(r->right, key);
    }

    node *get_root()
    {
        return root;
    }

    void serachMax(node *r)
    {
        if (r == NULL)
            return;
        while (r->right != NULL)
            r = r->right;
        cout << "\nMAX: " << r->data << endl;
    }

    void serachMin(node *r)
    {
        if (r == NULL)
            return;
        while (r->left != NULL)
            r = r->left;
        cout << "\nMIN: " << r->data << endl;
    }

    void invertTree(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        swap(r->right, r->left);
        invertTree(r->right);
        invertTree(r->left);
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

    cout << "Before: " << endl;
    t1.inOrder(t1.get_root());
    t1.invertTree(t1.get_root());
    cout << "\nAfter: " << endl;
    t1.inOrder(t1.get_root());
}
