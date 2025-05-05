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

    void inOrderAscCheck(node *r)
    {
        if (r == NULL)
            return;

        inOrderAscCheck(r->left);
        arr[index++] = r->data;
        inOrderAscCheck(r->right);
    }

    bool checkAsc()
    {
        for (int i = 0; i < index - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
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

    void isBST()
    {
        inOrderAscCheck(getRoot());
        if (checkAsc())
            cout << "It is indeed a BST" << endl;
        else
            cout << "It is not a BST" << endl;
        index = 0;
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

    void inOrder(node *r)
    {
        if (r == NULL)
            return;

        inOrder(r->left);
        cout << r->data << " ";
        inOrder(r->right);
    }
};

int main()
{
    Tree t1;
    t1.insert(43);
    t1.insert(63);
    t1.insert(2322);
    t1.insert(573);
    t1.insert(2);
    t1.insert(34);
    t1.insert(334);
    t1.insert(3564);
    t1.insert(341);
    t1.isBST();
    t1.inOrder(t1.getRoot());
}
