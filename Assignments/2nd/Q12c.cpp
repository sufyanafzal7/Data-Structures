#include <iostream>
#include <queue>
using namespace std;

struct QueueNode {
    queue<int> q;
    QueueNode* next;
};

class QueueOfQueues {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    QueueOfQueues() {
        front = rear = NULL;
    }

    ~QueueOfQueues() {
    }

    void enqueue(queue<int> newQueue) {
        QueueNode* temp = new QueueNode();
        temp->q = newQueue;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "No queues to dequeue." << endl;
            return;
        }

        QueueNode* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    void displayFrontQueue() {
        if (front == NULL) {
            cout << "No queues in the main queue." << endl;
            return;
        }

        queue<int> tempQueue = front->q;
        cout << "Contents of the front queue: ";
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueOfQueues queueOfQueues;
    for (int i = 1; i <= 3; i++) {
        queue<int> newQueue;
        for (int j = 1; j <= 3; j++)
            newQueue.push(j * i); 
        queueOfQueues.enqueue(newQueue);
    }

    for (int i = 1; i <= 3; i++) {
        cout << "Dequeuing Queue " << i << ":" << endl;
        queueOfQueues.displayFrontQueue();
        queueOfQueues.dequeue();
    }

    return 0;
}
