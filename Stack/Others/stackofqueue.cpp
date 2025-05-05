#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }

};
class queue{
    private:
    Node* front;
    Node* rear;
    public:
    queue(){
        front=rear=NULL;
    }

    bool isEmpty(){
        if(front==NULL && rear==NULL){
            return true;
        }
        return false;
    }

    void enque(int data){
        Node *n=new Node(data);
        if(front==NULL){
            front=rear=n;
            return;
        }
        rear->next=n;
        rear=n;
    }

    void deque(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node *temp=front;
        front=front->next;
        delete temp;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Queue is already empty"<<endl;
            return -1;
        }
        return front->data;

    }

};

class Stackofqueue{
    private:
    int top;
    queue *s;
    int length;
    public:
    Stackofqueue(int l){
        length=l;
        s=new queue[length];
        top=-1;
    }
    bool isFull(){
        if(top==length-1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    void pushQueueObject(queue q1){
        if(isFull()){
            cout<<"Stack overflow condition"<<endl;
            return;
        }
        top++;
        s[top]=q1;
    }

    void popQueueObject(){
        if(isEmpty()){
            cout<<"Stack underflow condition"<<endl;
            return;
        }
        top--;
    }

    queue& peekQueueObject(){
        if(isEmpty()){
            cout<<"Stack underflow condition"<<endl;
            static queue q1;
            return q1;
        }
        return s[top];
    }

};




int main(){
    queue q1;
    q1.enque(1);
    q1.enque(2);
    q1.enque(3);
    q1.enque(4);
    q1.enque(5);
    queue q2;
    q2.enque(6);
    q2.enque(7);
    q2.enque(8);
    q2.enque(9);
    Stackofqueue sq1(9);
    sq1.pushQueueObject(q1);
    sq1.pushQueueObject(q2);
    cout<<sq1.peekQueueObject().peek()<<endl;
    
}