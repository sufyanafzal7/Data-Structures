#include <iostream>
using namespace std;

struct Node{
    int info;
    Node* link;
};

class LinkedStack{
    private:
        Node *head;
    public:
        LinkedStack(){
            head=NULL;
        }

        ~LinkedStack(){

        }

        void push(int num){
            Node *n=new Node;
            n->info=num;
            n->link=head;
            head=n;
        }

        bool isEmpty(){
            if(head==NULL){
                return true;
            }
            return false;
        }
        void pop(){
            if(head==NULL){
                cout<<"Stack underflow error."<<endl;
                return;
            }
            Node *temp=head;
            head=head->link;
            cout<<temp->info<<" Poped."<<endl;
            delete temp;
        }

        int getPeak(){
            return head->info;
        }
};

class CircularQueue{
    private:
        int front,rear,l;
        int *q;

    public:

        CircularQueue(int length){
            l = length;
            q = new int[l];
            front=rear=-1;
        }

        ~CircularQueue(){
        }

        bool isEmpty(){
            if(front==-1)
                return true;
            return false;
        }

        bool isFull(){
            if(front==0 && rear==l-1)
                return true;
            else if(rear==front-1)
                return true;
            return false ;
        }

        void enqueue(int val){
            if(isFull()){
                cout<<"Queue is full"<<endl;
                return;
            }
            if(isEmpty()){
                front=rear=0;
            }
            else{
                if(rear==l-1)
                    rear=0;
                else    
                    rear++;
            }
            q[rear]=val;
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return;
            }
            int temp=q[front];
            if(front==rear)
                front=rear=-1;
            else{
                if(front==l-1)
                    front=0;
                else
                    front++;
            }
            cout<<temp<<" Dequeued"<<endl;
        }

        void displayQueue(){
            if(isEmpty()){
                cout<<"Queue doesn't exists!"<<endl;
                return;
            }
            cout<<"Elements in the queue are: ";
            if(front<=rear){
                for(int i=front; i<=rear; i++)
                    cout<<q[i]<<" element exists at "<<i<<" in the queue!"<<endl;
            }
            else{
                for(int i=front; i<=l-1; i++)
                    cout<<q[i]<<" element exists at "<<i<<" in the queue!"<<endl;
                for(int i=0;i<=rear;i++)
                    cout<<q[i]<<" element exists at "<<i<<" in the queue!"<<endl;
            }
        }

        void reverseQueue(){
            LinkedStack s;
            if(isEmpty()){
                cout<<"Queue doesn't exists!"<<endl;
                return;
            }
            while(!isEmpty()){
                s.push(q[front]);
                dequeue();
            }
            while(!s.isEmpty()){
                enqueue(s.getPeak());
                s.pop();
            }
        }
};
int main(){
    CircularQueue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.reverseQueue();
    q.displayQueue();
    return 0;
}