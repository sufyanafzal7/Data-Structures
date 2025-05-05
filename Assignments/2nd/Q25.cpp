#include <iostream>
using namespace std;

class Deque
{
private:
    int *customers;
    int front, rear, maxSize;

public:
    Deque(int size)
    {
        maxSize = size;
        customers = new int[maxSize];
        front = -1;
        rear = -1;
    }

    ~Deque()
    {
    }

    bool isFull()
    {
        return ((front == 0 && rear == maxSize - 1) || (front == rear + 1));
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void addFront(int customerID)
    {
        if (isFull())
        {
            cout << "Queue is full. No space left." << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = maxSize - 1;
        }
        else
        {
            front--;
        }
        customers[front] = customerID;
        cout << "Customer " << customerID << " added at the front of the queue." << endl;
    }

    void addRear(int customerID)
    {
        if (isFull())
        {
            cout << "Queue is full. No space left." << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == maxSize - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        customers[rear] = customerID;
        cout << "Customer " << customerID << " added at the rear of the queue." << endl;
    }

    void serveFront()
    {
        if (isEmpty())
        {
            cout << "No customers to serve at the front." << endl;
            return;
        }

        cout << "Customer " << customers[front] << " is being served from the front." << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == maxSize - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void serveRear()
    {
        if (isEmpty())
        {
            cout << "No customers to serve at the rear." << endl;
            return;
        }

        cout << "Customer " << customers[rear] << " is being served from the rear." << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = maxSize - 1;
        }
        else
        {
            rear--;
        }
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "No pending orders." << endl;
            return;
        }

        cout << "Pending orders: ";
        int i = front;
        while (true)
        {
            cout << customers[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main()
{
    int maxQueueSize = 5;
    Deque queue(maxQueueSize);

    queue.addRear(101);
    queue.addFront(102);
    queue.addRear(103);
    queue.addFront(104);
    queue.displayQueue();

    queue.serveFront();
    queue.displayQueue();

    queue.serveRear();
    queue.displayQueue();

    queue.addFront(105);
    queue.addRear(106);
    queue.displayQueue();

    return 0;
}
