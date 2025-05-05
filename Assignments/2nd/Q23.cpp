#include <iostream>
using namespace std;

class PizzaOrderQueue {
    private:
        int *orders;
        int front, rear, max;

    public:
        PizzaOrderQueue(int size) {
            max = size;
            orders = new int[max];
            front = rear = -1;
        }

        ~PizzaOrderQueue() {
        }

        void enqueue(int orderID) {
            if (rear == max - 1) {
                cout << "Order queue is full. No more orders can be accepted." << endl;
                return;
            }
            if (front == -1)
                front = 0;
            rear++;
            orders[rear] = orderID;
            cout << "Order " << orderID << " placed successfully." << endl;
        }

        void dequeue() {
            if (front == -1) {
                cout << "No orders to serve." << endl;
                return;
            }
            cout << "Order " << orders[front] << " is being served." << endl;
            if (front == rear)
                front = rear = -1;
            else 
                front++;
        }

        void displayQueue() {
            if (front == -1) {
                cout << "No pending orders." << endl;
                return;
            }
            cout << "Pending orders: ";
            for (int i = front; i <= rear; i++)
                cout << orders[i] << " ";
            cout << endl;
        }
};

int main() {
    int M = 5;
    PizzaOrderQueue queue(M);

    queue.enqueue(101);
    queue.enqueue(102);
    queue.enqueue(103);
    queue.displayQueue();

    queue.dequeue();
    queue.displayQueue();

    queue.enqueue(104);
    queue.enqueue(105);
    queue.enqueue(106); 
    queue.displayQueue();

    return 0;
}
