#include <iostream>
using namespace std;

class Stack {

private:
    int top;
    int *stacK;
    int len;

public:
    Stack(int length) {

        len = length;
        stacK = new int[len];
        top = -1;

    }


    ~Stack() {
        cout << "Hi I am a Destructor.";
    }


    bool isFull() {
        return top == len - 1;
    }


    void push(int number) {

        if (isFull()) {
            cout << "Stack overflow condition Broooooooooooo................." << endl;
            return;
        }

        top++;
        stacK[top] = number;

    }


    bool isEmpty() {
        return top==-1;
    }


    void pop() {

        if (isEmpty()) {
            cout << "Stack underflow condition Brooooooooooooo..........." << endl;
            return;
        }

        top--;

    }


    int peak() {

        if (isEmpty()) {
            cout << "Stack is empty Broooooooooo.............." << endl;
            return -1;

        }

        return stacK[top];

    }


    void display() {

        for (int i = 0; i <= top; i++) {
            cout << stacK[i] << " ";
        }
        cout << endl;

    }


    int getLength(){
        return len;
    }


};



void removeSpecificValue(Stack &mainStack, int valueToRemove) {

    Stack temporaryStack(mainStack.getLength());

    while (!mainStack.isEmpty()) {

        int topElementOfStack = mainStack.peak();
        mainStack.pop();

        if (topElementOfStack != valueToRemove) {
            temporaryStack.push(topElementOfStack);
        }

    }

    while (!temporaryStack.isEmpty()) {

        int topElementOfStack = temporaryStack.peak();
        temporaryStack.pop();
        mainStack.push(topElementOfStack);

    }


}




int main() {

    Stack mainStack(5);

    mainStack.push(1);
    mainStack.push(-1);
    mainStack.push(2);
    mainStack.push(-1);
    mainStack.push(3);

    cout << "Original Stack Broooooo:  ";
    mainStack.display();
    removeSpecificValue(mainStack, -1);

    cout << "Stack after removing -1 values Bhai Jan:  ";
    mainStack.display();

    return 0;

}
