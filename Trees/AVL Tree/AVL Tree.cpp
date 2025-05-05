#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
    int ht; 
};

// Function to calculate height
int height(node *N) {          
    if (N == NULL)
        return 0;
    return N->ht;
}

// Function to calculate Balance Factor (BF)
int BF(node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// RightRight Rotation (Single Left Rotation)
node* RightRight(node *y) {
    node *x = y->right;
    node *T2 = x->left;

    x->left = y;
    y->right = T2;

    y->ht = max(height(y->left), height(y->right)) + 1;
    x->ht = max(height(x->left), height(x->right)) + 1;

    return x;
}

// LeftLeft Rotation (Single Right Rotation)
node* LeftLeft(node *y) {
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->ht = max(height(y->left), height(y->right)) + 1;
    y->ht = max(height(x->left), height(x->right)) + 1;

    return x;
}


// LeftRight Rotation (Double Rotation: Left then Right)
node* LeftRight(node *T) {
    T->left = RightRight(T->left);
    return LeftLeft(T);
}

// RightLeft Rotation (Double Rotation: Right then Left)
node* RightLeft(node *T) {
    T->right = LeftLeft(T->right);
    return RightRight(T);
}

// Function to insert a node into the AVL tree
node* insert(node *T, int x) {
    if (T == NULL) {
        T = new node;
        T->data = x;
        T->left = NULL;
        T->right = NULL;
        T->ht = 1;        
    } else if (x > T->data) { 
        T->right = insert(T->right, x); //////////////////////////////////////
        if (BF(T) == -2) {
            if (x > T->right->data)
                T = RightRight(T);
            else
                T = RightLeft(T);
        }
    } else if (x < T->data) {  //////////////////////////////////////////////// 
        T->left = insert(T->left, x);
        if (BF(T) == 2) {
            if (x < T->left->data)
                T = LeftLeft(T);
            else
                T = LeftRight(T);
        }
    }
    T->ht = max(height(T->left), height(T->right)) + 1;
    return T;
}

// Function for Inorder Traversal
void inorder(node *T) {
    if (T != NULL) {
        inorder(T->left);
        cout << T->data << " ";
        inorder(T->right);
    }
}

int main() {
    node *root = NULL;
    int n, x;
    cout << "Enter number of elements to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter element: ";
        cin >> x;
        root = insert(root, x);
    }
    cout << "Inorder Traversal of the constructed AVL tree is: ";
    inorder(root);
    return 0;
}