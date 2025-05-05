#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

class Tree {
private:
    Node* root;
    string TreeString;

public:
    Tree() {
        root = nullptr;
        TreeString = "";
    }

    Node* getRoot() {
        return root;
    }

    void insertNode(int value) {
        Node* newNode = new Node;
        newNode->key = value;
        newNode->left = newNode->right = nullptr;

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* parent = nullptr;
        Node* current = root;

        while (current != nullptr) {
            parent = current;
            if (value < current->key)
                current = current->left;
            else
                current = current->right;
        }

        if (value < parent->key)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    
    
    
    
    
    
    

    void inOrderTraversal(Node* root) {
        if (root == nullptr)
            return;

        inOrderTraversal(root->left); 
            cout << root->key << " ";

        TreeString += "0";

        inOrderTraversal(root->right); 
        TreeString += "1";
    }
    
    
    
    
    
    
    
    
    
    
    

    // Clear the traversal result (in case we want to reuse this tree for another traversal)
    void clearTraversal() {
        TreeString = "";
    }

    // Getter for TreeString (to access it outside the class)
    string getTraversalResult() const {
        return TreeString;
    }
};

int main() {
    // Create the first tree and insert nodes
    Tree t1;
    t1.insertNode(3);
    t1.insertNode(2);
    t1.insertNode(1);
    t1.insertNode(4);
    t1.insertNode(5);

    // Perform in-order traversal and print the result
    cout << "In-order traversal of t1: ";
    t1.inOrderTraversal(t1.getRoot());
    cout << "\nStructure of t1: " << t1.getTraversalResult() << endl;
    
    // Create the second tree and insert nodes
    Tree t2;
    t2.insertNode(3);
    t2.insertNode(2);
    t2.insertNode(1);
    t2.insertNode(4);
    t2.insertNode(5);

    // Perform in-order traversal and print the result
    cout << "In-order traversal of t2: ";
    t2.inOrderTraversal(t2.getRoot());
    cout << "\nStructure of t2: " << t2.getTraversalResult() << endl;

    // Compare the in-order traversal results of both trees
    if (t1.getTraversalResult() == t2.getTraversalResult()) {
        cout << "Same Structure." << endl;
    } else {
        cout << "Not Same Structure" << endl;
    }

    return 0;
}