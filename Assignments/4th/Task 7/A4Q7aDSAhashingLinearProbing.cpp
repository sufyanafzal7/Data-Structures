#include <iostream>
#include <string>
using namespace std;

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

int hashFunction(string key) {
    int firstLetterCode = getLetterCode(key[0]);
    int secondLetterCode = getLetterCode(key[1]);
    return (firstLetterCode + secondLetterCode) % 13;
}

void insert(string hashTable[], int tableSize, string key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int attempts = 0;

    while (!hashTable[index].empty() && hashTable[index] != key) {
        index = (index + 1) % tableSize;
        attempts++;
        if (index == originalIndex) {
            cout << "Hash table is full. Cannot insert " << key << endl;
            return;
        }
    }

    hashTable[index] = key;
    cout << "Inserted key: " << key << " at index " << index << " (Attempts: " << attempts << ")" << endl;
}

void displayHashTable(string hashTable[], int tableSize) {
    cout << "\nHash Table:" << endl;
    for (int i = 0; i < tableSize; i++) {
        cout << "Bucket " << i << ": " << (hashTable[i].empty() ? "Empty" : hashTable[i]) << endl;
    }
}

int main() {
    const int tableSize = 13;
    string hashTable[tableSize] = {""}; 

    string keys[] = {"ISB", "LHR", "KHI", "MUX", "MUR", "PESH", "QUE", "FSB", "BWP", "SGD", "RWP"};
    int numberOfKeys = sizeof(keys) / sizeof(keys[0]);

    cout << "Inserting keys into the hash table using linear probing...\n";
    for (int i = 0; i < numberOfKeys; i++) {
        insert(hashTable, tableSize, keys[i]);
    }

    displayHashTable(hashTable, tableSize);

    return 0;
}
