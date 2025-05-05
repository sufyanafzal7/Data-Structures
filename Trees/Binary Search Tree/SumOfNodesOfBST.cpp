#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* root = nullptr;

void insertNode(int value) {
    Node* newNode = new Node;
    newNode->key = value;
    newNode->left = newNode->right = nullptr;

    if (root == nullptr) {
        root = newNode;
        return;
    }
             
    Node *parent=nullptr;
    Node *current=root;

    while(current!=nullptr){
        parent=current;
        if(value<current->key)
            current=current->left;
        else
            current=current->right;
    }
    if(value<parent->key)
        parent->left=newNode;
    else
        parent->right=newNode;
}

int sum = 0;

void inOrderTraversal(Node* root) {
    if(root==nullptr)
        return;
  sum = sum + root->key;
    inOrderTraversal(root->left);
    cout << root->key << " ";
    inOrderTraversal(root->right);
}



int main() {
    insertNode(3);
    insertNode(2);
    insertNode(1);
    insertNode(4);
    insertNode(5);

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout<<"\n\n Sum = "<<sum;
    return 0;
}