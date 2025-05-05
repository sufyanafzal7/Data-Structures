#include <iostream>
#include <string>
using namespace std;

#define TABLE_SIZE 26
struct Node {
    string info;
    Node* next;
};

class LinkedList {
private:
    Node* first;
    Node* last;
public:
    LinkedList() {
        first = NULL;
        last = NULL;
    }

    ~LinkedList() {
        
    }

    void insertLast(string book) {
        Node* n = new Node;
        n->info = book;
        n->next = NULL;

        if (first == NULL)
            first = last = n;
        else {
            last->next = n;
            last = n;
        }
    }

    void traverse() {
        if (first == NULL) {
            cout << "No books found in this compartment." << endl;
            return;
        }
        Node* current = first;
        while (current != NULL) {
            cout << current->info << "\t";
            current = current->next;
        }
        cout << endl;
    }

    bool search(string book) {
        Node* current = first;
        while (current != NULL) {
            if (current->info == book) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int hashFunction(string book) {
    return toupper(book[0])%TABLE_SIZE;
}

class Bookshelf {
    private:
        LinkedList table[TABLE_SIZE];

    public:
        void insert(string book) {
            int index = hashFunction(book);
            table[index].insertLast(book);
            cout << "Book \"" << book << "\" inserted into compartment " << index << endl;
        }

        void search(string book) {
            int index = hashFunction(book);
            if (table[index].search(book)) {
                cout << "Book \"" << book << "\" is found in compartment " << index << endl;
            } 
            else {
                cout << "Book \"" << book << "\" not found." << endl;
            }
        }
        void display() {
            cout << "\nBooks in shelf compartments are:\n";
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout << "Compartment " << i << ": ";
                table[i].traverse();
            }
        }
};

int main() {
    Bookshelf shelf;
    int option;
    string book;

    while (true) {
        cout << "\n1. Insert a book  2. Display all books  3. Search for a book  4. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the book name: ";
                cin>>ws;
                getline(cin, book);
                shelf.insert(book);
                break;
            case 2:
                shelf.display();
                break;
            case 3:
                cout << "Enter the book name to search: ";
                cin>>ws;
                getline(cin, book);
                shelf.search(book);
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}