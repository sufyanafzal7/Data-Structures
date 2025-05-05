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

void inOrderTraversal(Node* root) {
    if(root==nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->key << " ";
    inOrderTraversal(root->right);
}
// Helper function to find the minimum value node in a tree
Node* findMin(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from a BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    // Search for the node to delete
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
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
    cout<<"Deleting 3\n";
    deleteNode(root,3);
    cout<<"After Deleting 3\n";
     cout << "In-order traversal: ";
    inOrderTraversal(root);
    return 0;
}