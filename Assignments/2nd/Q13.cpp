#include <iostream>
using namespace std;

class DoubleQueue {
    private:
        int front_right, rear_right, front_left, rear_left, l;
        int *q;

    public:
        DoubleQueue(int length) {
            l = length;
            q = new int[l];
            front_right = rear_right = l; 
            front_left = rear_left = -1;  
        }

        ~DoubleQueue() {
            delete[] q;
        }

        bool isEmptyRight() {
            return (front_right == l && rear_right == l);
        }

        bool isEmptyLeft() {
            return (front_left == -1 && rear_left == -1);
        }

        bool isEmpty() {
            return (isEmptyLeft() && isEmptyRight());
        }

        bool isFull() {
            return (rear_left + 1 == rear_right);
        }

        void enqueueRight(int val) {
            if (isFull()) {
                cout << "Queue is full" << endl;
                return;
            }
            if (isEmptyRight()) {
                front_right = rear_right = l - 1;
            } else {
                rear_right--;
            }
            q[rear_right] = val;
        }

        void enqueueLeft(int val) {
            if (isFull()) {
                cout << "Queue is full" << endl;
                return;
            }
            if (isEmptyLeft()) {
                front_left = rear_left = 0;
            } else {
                rear_left++;
            }
            q[rear_left] = val;
        }

        void dequeueLeft() {
            if (isEmptyLeft()) {
                cout << "Queue is empty" << endl;
                return;
            }
            int temp = q[front_left];
            if (front_left == rear_left) {
                front_left = rear_left = -1; 
            } else {
                front_left++;
            }
            cout << temp << " dequeued from left" << endl;
        }

        void dequeueRight() {
            if (isEmptyRight()) {
                cout << "Queue is empty" << endl;
                return;
            }
            int temp = q[front_right];
            if (front_right == rear_right) {
                front_right = rear_right = l;
            } else {
                front_right++;
            }
            cout << temp << " dequeued from right" << endl;
        }

        void displayQueue() {
            if (isEmpty()) {
                cout << "Queue doesn't exist!" << endl;
                return;
            }
            cout << "Left Queue: ";
            for (int i = front_left; i <= rear_left; i++) {
                cout << q[i] << " ";
            }
            cout << "\nRight Queue: ";
            for (int i = front_right; i >= rear_right; i--) {
                cout << q[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    DoubleQueue dq(10);
    dq.enqueueLeft(1);
    dq.enqueueRight(2);
    dq.enqueueLeft(3);
    dq.enqueueRight(4);
    dq.enqueueLeft(5);
    dq.enqueueLeft(6);
    dq.enqueueLeft(7);

    dq.displayQueue();

    dq.dequeueLeft();
    dq.dequeueRight();
    dq.displayQueue();

    return 0;
}
