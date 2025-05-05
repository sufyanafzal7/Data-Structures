#include <iostream>
using namespace std;

int sum = 0;
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

    void inOrder(node *r)
    {
        if (r == NULL)
            return;

        inOrder(r->left);
        cout << r->data << " ";
        inOrder(r->right);
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

    void remove(int x)
    {
        root = remove(root, x);
    }

    node *remove(node *r, int x)
    {
        if (r == NULL)
            return NULL;

        if (x > r->data)
            r->right = remove(r->right, x);
        else if (x < r->data)
            r->left = remove(r->left, x);
        else
        {
            if (r->left == NULL && r->right == NULL)
            {
                delete r;
                return NULL;
            }
            if (r->left == NULL)
            {
                node *temp = r->right;
                delete r;
                return temp;
            }
            if (r->right == NULL)
            {
                node *temp = r->left;
                delete r;
                return temp;
            }
            node *temp = findMin(r->right);
            r->data = temp->data;
            r->right = remove(r->right, temp->data);
        }
        return r;
    }

    node *findMax(node *r)
    {
        while (r->left != NULL)
            r = r->left;
        return r;
    }

    node *del(node *r, int x)
    {
        if (r == NULL)
            return r;

        if (x > r->data)
            r->right = del(r->right, x);
        else if (x < r->data)
            r->left = del(r->left, x);
        else
        {
            if (r->left == NULL && r->right == NULL)
            {
                delete r;
                return NULL;
            }
            if (r->left == NULL)
            {
                node *temp = r->right;
                delete r;
                return temp;
            }
            if (r->right == NULL)
            {
                node *temp = r->left;
                delete r;
                return temp;
            }
            node *temp = findMax(r->left);
            r->data = temp->data;
            r->left = del(r->left, temp->data);
        }
        return r;
    }

    void del(int x)
    {
        root = del(root, x);
    }
};

int main()
{
    Tree t1;
    t1.insert(43);
    t1.insert(63);
    t1.insert(23);
    t1.insert(34);
    t1.del(23);
    t1.del(63);
    t1.inOrder(t1.getRoot());
}
