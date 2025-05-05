#include <iostream>
#include <queue>
using namespace std;

struct node
{
    node *left;
    node *right;
    int data;
};

class Tree
{
private:
    node *root;
    int count;
    int arr[];

public:
    Tree()
    {
        root = NULL;
        count = 0;
        int arr[50];
    };
    void insert(int val)
    {
        node *n = new node;
        n->right = NULL;
        n->left = NULL;
        n->data = val;
        if (root == NULL)
        {
            root = n;
            return;
        }
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *current = q.front();
            q.pop();

            if (current->left == NULL)
            {
                current->left = n;
                return;
            }
            else
                q.push(current->left);

            if (current->right == NULL)
            {
                current->right = n;
                return;
            }
            else
                q.push(current->right);
        }
    }

    void inOrder(node *r)
    {
        if (r == NULL)
            return;
        inOrder(r->left);
        cout << r->data << " ";
        inOrder(r->right);
    }

    void preOrder(node *r)
    {
        if (r == NULL)
            return;
        cout << r->data << " ";
        preOrder(r->left);
        preOrder(r->right);
    }

    void postOrder(node *r)
    {
        if (r == NULL)
            return;
        postOrder(r->left);
        postOrder(r->right);
        cout << r->data << " ";
    }

    node *get_root()
    {
        return root;
    }

    void check(node *r)
    {
        if (r == NULL)
            return;
        check(r->left);
        arr[count++] = r->data;
        check(r->right);
    }

    bool isAsc()
    {
        for (int i = 1; i < count; ++i)
        {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }

    bool isBST()
    {
        check(root);
        count = 0;
        return isAsc();
    }
};

int main()
{
    Tree t1;
    t1.insert(43);
    t1.insert(23);
    t1.insert(66);
    t1.insert(11);
    t1.insert(31);
    t1.insert(54);
    t1.insert(77);
    t1.insert(7);
    t1.insert(6);
    cout << "\nIn-Order: \n";
    t1.inOrder(t1.get_root());
    cout << "\npre-Order: \n";
    t1.preOrder(t1.get_root());
    cout << "\npost-Order: \n";
    t1.postOrder(t1.get_root());

    if (t1.isBST())
        cout << "BST";
    else
        cout << "\nNOT";
}
