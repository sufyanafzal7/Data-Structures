#include <iostream>
using namespace std;

int sumNodes = 0;

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

    void inOrderSum(node *r)
    {
        if (r == NULL)
            return;
        inOrderSum(r->left);
        sumNodes += r->data;
        inOrderSum(r->right);
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
    t1.inOrderSum(t1.getRoot());
    cout << "Sum = " << sumNodes;
}
