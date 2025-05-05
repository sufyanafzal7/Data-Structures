#include <iostream>
using namespace std;

class circularqueue{
    private:
    int length;
    int *s;
    int front;
    int rear;
    int count;
    public:
    circularqueue(int l){
        length=l;
        s=new int[length];
        front=rear=-1;
        count=0;
    }
    bool isFull(){
        if(count==length){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(count==0){
            return true;
        }
        return false;
    }
    void enque(int d){
        if(isFull()){
            cout<<"Queue is already full"<<endl;
            return;
        }
        if(front==-1){
            front=rear=0;
        }
        else{
            rear=(rear+1)%length;
        }
        s[rear]=d;
        count++;

    }
    void deque(){
        if(isEmpty()){
            cout<<"Queue is already empty"<<endl;
            return;
        }
        if(front==rear){
            front=rear=-1;
            return;
        }
        else{
            front=(front+1)%length;
        }
        count--;
    }
    int peek(){
        if(isEmpty()){
            cout<<"No elements to peek"<<endl;
            return -1;
        }
        return s[front];
    }

    void getsorted(circularqueue &q, circularqueue&q2){
        for(int i=0;i<10;i++){
            if(i+1%2==0){
                q2.enque(peek());
            }
            else{
                q.enque(peek());
            }
            deque();
        }
    }

    void display(){
        int i=front;
        while(true){
            cout<<s[i]<<" ";
            if(i==rear){
                break;
            }
            i=(i+1)%length;
        }
        cout<<endl;
    }

};

int main(){
    circularqueue q1(10);
    q1.enque(3);
    q1.enque(5);
    q1.enque(6);
    q1.enque(7);
    q1.enque(2);
    q1.enque(1);
    q1.enque(9);
    q1.enque(8);
    q1.enque(12);
    q1.enque(10);
    cout<<"----------"<<endl;
    circularqueue odd(5);
    circularqueue even(5);
    q1.getsorted(odd,even);
    cout<<"======"<<endl;
    odd.display();
    cout<<endl;
    even.display();
    


}
