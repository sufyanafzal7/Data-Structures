#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front, rear;
    int L;

public:
    bool isFull()
    {
        return (rear + 1) % L == front;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    Queue(int l)
    {
        front = rear = -1;
        L = l;
        arr = new int[L];
    }

    void enQueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full." << endl;
            return;
        }
        if (isEmpty())
        {
            rear = front = 0;
            arr[rear] = x;
        }
        else
        {
            rear = (rear + 1) % L;
            arr[rear] = x;
        }
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        if (rear == front)
        {
            rear = front = -1;
            return;
        }
        front = (front + 1) % L;
    }

    int peakfront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }
};

class PriorityQueue
{
private:
    Queue original;

public:
    PriorityQueue() : original(10) {}
    void enQ(int x)
    {
        Queue temp(10);

        while (!original.isEmpty() && x > original.peakfront())
        {
            temp.enQueue(original.peakfront());
            original.deQueue();
        }
        temp.enQueue(x);
        while (!original.isEmpty())
        {
            temp.enQueue(original.peakfront());
            original.deQueue();
        }
        swap(original, temp);
    }

    void deQ()
    {
        cout << "Dequeued: " << original.peakfront() << endl;
        original.deQueue();
    }

    void traversal()
    {
        Queue temp(10);
        temp = original;
        while (!temp.isEmpty())
        {
            cout << temp.peakfront() << " ";
            temp.deQueue();
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue q1;
    q1.enQ(554);
    q1.enQ(43);
    q1.enQ(32);
    q1.enQ(31);
    q1.enQ(301);
    q1.enQ(319);
    q1.enQ(931);
    q1.enQ(100);
    q1.enQ(4);
    q1.enQ(554);
    q1.deQ();
    q1.deQ();
    q1.deQ();
    q1.enQ(1);
    q1.deQ();
    q1.deQ();
    q1.traversal();
}