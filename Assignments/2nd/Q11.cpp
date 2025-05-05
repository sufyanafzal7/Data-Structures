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

        void push(int number){

            Node *n=new Node;
            n->info=number;
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
                cout<<"Stack underflow error, Bhai chahta kiya hai tuuuuuuuu."<<endl;
                return;
            }

            Node *temporaray=head;
            head=head->link;
            cout<<temporaray->info<<" Poped."<<endl;
            delete temporaray;
        }

        int getPeak(){
            return head->info;
        }


};



class CircularQueue{

    private:
        int front,rear,len;
        int *que;

    public:

        CircularQueue(int length){
            len = length;
            que = new int[len];
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

            if(front==0 && rear==len-1)
                return true;
            else 
            if(rear==front-1)
                return true;
            return false ;

        }

        void enQueue(int val){

            if(isFull()){
                cout<<"Queue is full, Ja Bhai ja.........."<<endl;
                return;
            }

            if(isEmpty()){
                front=rear=0;
            }
            else{
                if(rear==len-1)
                    rear=0;
                else    
                    rear++;
            }
            que[rear]=val;
        }

        void deQueue(){

            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return;
            }

            int temporary=que[front];

            if(front==rear)
                front=rear=-1;
            else{
                if(front==len-1)
                    front=0;
                else
                    front++;
            }
            cout<<temporary<<" Dequeued"<<endl;
        }

        void displayQueue(){

            if(isEmpty()){
                cout<<"Queue doesn't exists! Kuch daaley to nikaaley ga na Bhaiiiii........."<<endl;
                return;
            }
            cout<<"Bhai Elements in the queue are:  ";
            if(front<=rear){
                for(int i=front; i<=rear; i++)
                    cout<<que[i]<<" Element exists at "<<i<<" in the queue!"<<endl;
            }
            else{
                for(int i=front; i<=len-1; i++)
                    cout<<que[i]<<" Element exists at "<<i<<" in the queue!"<<endl;
                for(int i=0;i<=rear;i++)
                    cout<<que[i]<<" Element exists at "<<i<<" in the queue!"<<endl;
            }
        }

        void reverseQueue(){
            LinkedStack simpName;
            if(isEmpty()){
                cout<<"Queue doesn't exists!"<<endl;
                return;
            }
            while(!isEmpty()){
                simpName.push(que[front]);
                deQueue();
            }
            while(!simpName.isEmpty()){
                enQueue(simpName.getPeak());
                simpName.pop();
            }
        }
};



int main(){
    CircularQueue qu(3);
    qu.enQueue(1);
    qu.enQueue(2);
    qu.enQueue(3);
    qu.reverseQueue();
    qu.displayQueue();
    return 0;
}