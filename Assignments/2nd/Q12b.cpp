#include <iostream>
#include <queue>
using namespace std;

struct StackNode {
    queue<int> q;
    StackNode* next;
};

class StackOfQueues {
private:
    StackNode* top;

public:
    StackOfQueues() {
        top = NULL;
    }
    
    ~StackOfQueues() {
    }

    void push(queue<int> newQueue) {
        StackNode* temp = new StackNode();
        temp->q = newQueue;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (top == NULL) {
            cout << "No queues to pop." << endl;
            return;
        }
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    void displayTopQueue() {
        if (top == NULL) {
            cout << "No queues in the stack." << endl;
            return;
        }

        queue<int> tempQueue = top->q;
        cout << "Contents of the top queue: ";
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
};

int main() {
    StackOfQueues stackOfQueues;
    for (int i = 1; i <= 3; i++) {
        queue<int> newQueue;
        for (int j = 1; j <= 3; j++) {
            newQueue.push(j * i);
        }
        stackOfQueues.push(newQueue);
        cout << "Pushed Queue " << i << " with contents: ";
        stackOfQueues.displayTopQueue();
    }
    for (int i = 1; i <= 3; i++) {
        cout << "Popping Queue " << i << ":" << endl;
        stackOfQueues.displayTopQueue();
        stackOfQueues.pop();
    }

    return 0;
}
