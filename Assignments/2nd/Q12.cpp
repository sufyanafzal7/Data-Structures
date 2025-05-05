#include <iostream>
#include <stack>
using namespace std;


struct QueueNode {
    stack<int> stACk;
    QueueNode* next;
};

class QueueOfStacks {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    QueueOfStacks(){
        front=rear=NULL;
    }
    ~QueueOfStacks(){
    }
    void enQueue(stack<int> newStack) {
        QueueNode* temporary = new QueueNode();
        temporary->stACk = newStack;
        temporary->next = NULL;
        if(front==NULL){
            front=rear=temporary;
        }
        rear->next=temporary;
        rear = temporary;
    }

    void deQueue() {
        if (front==NULL) 
            return; 
        QueueNode* temp = front;
        if(front==rear){
            front=rear=NULL;
        }
        front = front->next;
        delete temp;
    }

    void displayFrontStack() {
        if (front == NULL) {
            cout << "No stacks in the queue." << endl;
            return;
        }

        stack<int> tempStack = front->stACk;
        cout << "Contents of the front stack: ";
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueOfStacks queueOfStacks;
    for (int i = 1; i <= 3; i++) {
        stack<int> newStack;
        for (int j = 1; j <= 3; j++) {
            newStack.push(j * i); 
        }
        queueOfStacks.enQueue(newStack);
    }

    for (int i = 1; i <= 3; i++) {
        cout << "Dequeueing Stack " << i << ":" << endl;
        queueOfStacks.displayFrontStack();
        queueOfStacks.deQueue();
    }

    return 0;
}
