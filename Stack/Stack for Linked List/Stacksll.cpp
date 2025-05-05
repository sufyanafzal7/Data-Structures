#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

};

class Stack{
    private:
    Node *head;
    public:
    Stack(){
        head=NULL;
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }

    void push(int d){
        Node *n=new Node;
        n->data=d;
        if(head==NULL){
            n->next=NULL;
            head=n;
            return;
        }
        n->next=head;
        head=n;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack underflow condition "<<endl;
            return ;
        }
        Node *temp=head;
        head=head->next;
        delete temp;
    }

    Stack revStack(){
        Stack s2;
        while(!isEmpty()){
            s2.push(peek());
            pop();       
        }
        return s2;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Stack underflow condition";
            return -1;
        }
        return head->data;
    }



        
        

};

int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout<<s1.peek()<<endl;
    cout<<"-----------"<<endl;
    Stack s2=s1.revStack();
    cout<<s2.peek()<<endl;
    

    
    

    
}