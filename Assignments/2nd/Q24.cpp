#include <iostream>
using namespace std;

struct Order {
    int orderID;
    int age;
};

class PizzaOrderQueue {
    private:
        Order *orders;
        int front, rear, max;

    public:
        PizzaOrderQueue(int size) {
            max = size;
            orders = new Order[max];
            front = rear = -1;
        }

        ~PizzaOrderQueue() {
            delete[] orders;
        }

        void enqueue(int orderID, int age) {
            if (rear == max - 1) {
                cout << "Order queue is full. No more orders can be accepted." << endl;
                return;
            }
            Order newOrder = { orderID, age };
            if (front == -1) {
                front = 0;
                rear = 0;
                orders[rear] = newOrder;
            }
            else {
                int i;
                for (i = rear; i >= front; i--) {
                    if (age>orders[i].age)
                        orders[i + 1] = orders[i];
                    else
                        break;
                }
                orders[i + 1] = newOrder;
                rear++;
            }

            cout << "Order " << orderID << " placed successfully." << endl;
        }

        void dequeue() {
            if (front == -1) {
                cout << "No orders to serve." << endl;
                return;
            }

            cout << "Order " << orders[front].orderID << " (Age " << orders[front].age << ") is being served." << endl;

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
                cout << "[" << orders[i].orderID << ", Age: " << orders[i].age << "] ";
            cout << endl;
        }
};

int main() {
    int M = 5;
    PizzaOrderQueue queue(M);

    queue.enqueue(101, 30);  
    queue.enqueue(102, 45);  
    queue.enqueue(103, 25);  
    queue.displayQueue();

    queue.dequeue();
    queue.displayQueue();

    queue.enqueue(104, 50);  
    queue.enqueue(105, 30);  
    queue.enqueue(106, 40);  
    queue.displayQueue();

    return 0;
}
