#include <iostream>
using namespace std;

class queue{
    private:
    int rear;
    int front;
    int *s;
    int length;
    public:
    queue(int l){
        length=l;
        s=new int[length];
        rear=front=-1;
    }

    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(rear==length-1){
            return true;
        }
        return false;
    }

    void enque(int data){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(isEmpty()){
            front=rear=0;
        }
        else{
            rear++;
        }
        s[rear]=data;

    }
    void deque(){
        if(isEmpty() || front>rear){
            cout<<"NO elements in queue"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(isEmpty() || front>rear){
            cout<<"Queue is already empty"<<endl;
            return -1;
        }
        return s[front];
    }
};

int main(){
    queue q1(4);
    q1.enque(1);
    q1.enque(2);
    q1.enque(3);
    q1.enque(4);
    cout<<q1.peek()<<endl;
    q1.deque();
    cout<<q1.peek()<<endl;
    q1.deque();
    cout<<q1.peek()<<endl;
    q1.deque();
    cout<<q1.peek()<<endl;
    q1.deque();

}