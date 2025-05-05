#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    Node* next;
    Node(string k) : key(k), next(NULL) {}
};

const int BUCKETS = 13;
Node* hashTable[BUCKETS] = {NULL};

int getLetterCode(char ch) {
    if (ch == 'A' || ch == 'B' || ch == 'C') return 1;
    if (ch == 'D' || ch == 'E' || ch == 'F') return 2;
    if (ch == 'G' || ch == 'H' || ch == 'I') return 3;
    if (ch == 'J' || ch == 'K' || ch == 'L') return 4;
    if (ch == 'M' || ch == 'N' || ch == 'O') return 5;
    if (ch == 'P' || ch == 'Q' || ch == 'R') return 6;
    if (ch == 'S' || ch == 'T' || ch == 'U') return 7;
    if (ch == 'V' || ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z') return 8;
    return 0;
}

int hashFunction(const string& key) {
    int code1 = getLetterCode(key[0]);
    int code2 = getLetterCode(key[1]);
    return (code1 + code2) % BUCKETS;
}

void insertKey(const string& key) {
    int index = hashFunction(key);
    Node* newNode = new Node(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode; 
    } else {
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayHashTable() {
    for (int i = 0; i < BUCKETS; ++i) {
        cout << "Bucket " << i << ": ";
        Node* temp = hashTable[i];
        if (temp == NULL) {
            cout << "Empty";
        } else {
            while (temp != NULL) {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL";
        }
        cout << endl;
    }
}

int main() {
    string keys[] = {"ISB", "LHR", "KHI", "MUX", "MUR", "PESH", "QUE", "FSB", "BWP", "SGD", "RWP"};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; ++i) {
        insertKey(keys[i]);
    }

    cout << "Hash Table with Chaining:\n";
    displayHashTable();

    return 0;
}
