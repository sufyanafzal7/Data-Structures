#include<iostream>
using namespace std;

class node{
    public:
    node*next;
    int data;
    node(int value){
        data = value;
        next = NULL;
    }
};

class DEQUE{
    public:
    node* front;
    node* back;
    DEQUE(){
        front = NULL;
        back = NULL;
    }

    void push(int value){
        node * n = new node(value);
        if (front==NULL){
            front = n;
            back = n;
            return;
        }
        n->next = front;
        front = n;
    }

    //The Pop() operation will delete the node from the start of the queue and return the value that 
    //was present in it 
    int Pop(){
        //checking if the queue is empty 
        if(front==NULL){
            cout<<"No element in the queue"<<endl;
            return -1;
        }
        node* temp = front;
        if(front==back){
            front=back=NULL;
            delete temp;
            return -1;
        }
        int data = front->data;
        front = front->next;
        delete temp;
        return data;
    }

    //The given inject operation will inject the node at the end of the queue
    void Inject(int value){
        node* n = new node(value);
        //if our queue is empty
        if(front == NULL){
                front = n;
                back = n;
                return;
        }
        back->next = n;
        back = back->next;
    }

    //The Eject() operation will delete the node from the end of the queue and return the value in it
    int Eject(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        //If only one element in the deque
        if (front == back) {
            int data = back->data;
            delete back;
            front = back = NULL;
            return data;
        }

        
        node* temp = front;
        while(temp->next!=back){
            temp = temp->next;
        }
        
         

        int data = temp->next->data;
        node *todelete = back;
        back = temp;
        delete todelete;
        return data;
    }

};

int main(){
     DEQUE dq;
    dq.push(10);
    dq.Inject(20);
    dq.push(5);
    cout << "Pop from front: " << dq.Pop() << endl; 
    cout << "Eject from back: " << dq.Eject() << endl;
    cout << "Pop from front: " << dq.Pop() << endl; 
    cout << "Eject from back: " << dq.Eject() << endl; 
    return 0;
}
