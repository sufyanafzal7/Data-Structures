#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
    Node* prev;
};

class DoublyLinkedStack {
    private:
        Node* head;

    public:
        DoublyLinkedStack() {
            head = NULL;
        }

        ~DoublyLinkedStack() {
        }

        void push(int num) {
            Node* n = new Node;
            n->info = num;
            n->next = head;
            n->prev = NULL;
            if (head != NULL) {
                head->prev = n;
            }
            head = n;
        }

        void pop() {
            if (head == NULL) {
                cout << "Stack underflow error." << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            cout << temp->info << " Popped." << endl;
            delete temp;
        }

        int peak() {
            if (head != NULL) {
                return head->info;
            }
            return -1; 
        }

        bool isEmpty() {
            return head == NULL;
        }
};

void checkPalindrome(string str) {
    DoublyLinkedStack s1;
    int mid = str.length() / 2;
    for (int i = 0; i < mid; i++) {
        s1.push(str[i]);
    }
    if (str.length() % 2 != 0) {
        mid++;
    }
    bool isPalindrome = true;
    for (int i = mid; i < str.length(); i++) {
        if (s1.peak() == str[i])
            s1.pop();
        else {
            cout << "The given string is not a palindrome." << endl;
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "The string is a palindrome." << endl;
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    checkPalindrome(str);
    return 0;
}
