#include <iostream>
using namespace std;

class DoubleStack {

private:
    int array[200];
    int topSmallLeft; 
    int topLargeRight;

public:
    DoubleStack() {

        topSmallLeft = -1;     
        topLargeRight = 200;  

    }


    bool isFull() {
        return topSmallLeft + 1 == topLargeRight; 
    }


    void push(int value) {

        if (isFull()) {
            cout << "Stack overflow condition Broooooooo..........." << endl;
            return;
        }
        
        if (value <= 1000)
            array[++topSmallLeft] = value;
        else 
            array[--topLargeRight] = value;

    }


    void displaySmallStack() {

        cout << "Small-value stack is:  ";
        for (int i = 0; i <= topSmallLeft; i++)
            cout << array[i] << " ";
        cout << endl;

    }


    void displayLargeStack() {

        cout << "Large-value stack is:  ";
        for (int i = 199; i >= topLargeRight; i--)
            cout << array[i] << " ";
        cout << endl;

    }


};



int main() {

    DoubleStack StackMain;

    StackMain.push(70);
    StackMain.push(6900);
    StackMain.push(1000);
    StackMain.push(2000);
    StackMain.push(90);

    StackMain.displaySmallStack();
    StackMain.displayLargeStack();

    return 0;

}
