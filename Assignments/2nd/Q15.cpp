#include <iostream>
using namespace std;

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

    void split(CircularQueue &CQueue1,CircularQueue &CQueue2){       
        int i=0;
        while(!isEmpty()){
            if(i%2==0)
                CQueue1.enqueue(q[front]);
            else
                CQueue2.enqueue(q[front]);
            dequeue();
            i++;
        }
    }

    int size(){
        int totalSize = (rear >= front ? rear - front + 1 : l - front + rear + 1);
        return totalSize;
    }
};

int main(){
    CircularQueue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    CircularQueue q1(q.size()+1/2);
    CircularQueue q2(q.size()/2);
    q.split(q1,q2);
    q1.displayQueue();
    q2.displayQueue();
    return 0;
}