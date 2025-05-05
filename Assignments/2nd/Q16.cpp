#include <iostream>
using namespace std;

struct Node {
    int data;     
    Node* next; 
};

class CircularQueue {
    private:
        Node* tail;

    public:
        CircularQueue(){
            tail=NULL;
        }

        ~CircularQueue() {
        }

        void add(int value) {
            Node* newNode = new Node;
            newNode->data=value;
            if (tail == NULL) { 
                tail = newNode;
                tail->next = tail;
            }
            else {
                newNode->next = tail->next;
                tail->next = newNode; 
                tail = newNode;
            }
            cout << value << " added to the queue." << endl;
        }

        void remove() {
            if (tail == NULL) {
                cout << "Queue is empty!" << endl;
                return;
            }

            Node* front = tail->next;
            if (front == tail) { 
                delete tail; 
                tail = NULL;
            } 
            else {
                tail->next = front->next; 
                delete front;
            }
            cout << "Removed from the queue." << endl;
        }

        void display() {
            if (tail == NULL) {
                cout << "Queue is empty!" << endl;
                return;
            }

            Node* current = tail->next; 
            cout << "Elements in the queue: ";
            do {
                cout << current->data << " ";
                current = current->next; 
            } while (current != tail->next);
            cout << endl;
        }
};

int main() {
    CircularQueue q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.display(); 
    q.remove(); 
    q.display(); 
    q.remove();  
    q.remove(); 
    q.remove();
    return 0;
}
