#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class queue{
    private:
    Node*front;
    Node*rear;
    public:
    queue(){
        front=NULL;
        rear=NULL;
    }

    bool isEmpty(){
        if(rear==NULL && front ==NULL){
            return true;
        }
        return false;
    }

    void enque(int d){
        Node *n=new Node;
        n->data=d;
        n->next=NULL;
        if(front==NULL){
            front=rear=n;
            return;
        }
        rear->next=n;
        rear=n;

    }

    void deque(){
        if(isEmpty()){
            cout<<"Queue is already empty "<<endl;
            return;
        }
        Node *temp=front;
        front=front->next;
        delete temp;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Stack underflow condition";
            return -1;
        }
        return front->data;
    }

};


int main(){
    queue q1;
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