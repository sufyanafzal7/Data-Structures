#include <iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
};

Node *first=NULL;
Node *last=NULL;

void insertLast(){
    Node *n=new Node;
    cout<<"Enter input:";
    cin>>n->info;
    n->next=NULL;
    if(first==NULL)
        first=last=n;
    else{
        last->next=n;
        last=n;
    }
}

void traverse(){
    if(first==NULL){
        cout<<"Linked list Not exist."<<endl;
        return;
    }
    Node *current=first;
    cout<<"Linked List"<<endl;
    while(current!=NULL){
        cout<<current->info<<"\t";
        current=current->next; 
    }
    cout<<endl;
}

Node* search(int key){
    if(first==NULL){
        cout<<"Linked list does not exist."<<endl;
        return NULL;
    }
    Node *current=first;
    while(current!=NULL){
        if(current->info==key)
            return current;
        current=current->next;
    }
    return NULL;
}

void swap(int info1,int info2){
    Node *firstAddress=search(info1);
    Node *secondAddress=search(info2);
    if(first==NULL){
        cout<<"Linked lsit not exist."<<endl;
        return;
    }
    if(firstAddress==NULL || secondAddress==NULL){
        cout<<"Such info not exist."<<endl;
        return;
    }
    Node *current=first;
    Node *prevOfFirst=NULL;
    while(current!=firstAddress){
        prevOfFirst=current;
        current=current->next;
    }
    current=first;
    Node *prevOfSecond=NULL;
    while(current!=secondAddress){
        prevOfSecond=current;
        current=current->next;
    }
    prevOfFirst->next=secondAddress;
    prevOfSecond->next=firstAddress;
    Node *temp=secondAddress->next;
    secondAddress->next=firstAddress->next;
    firstAddress->next=temp;
}

int main(){
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    int info1,info2;
    cout<<"Enter first info u want to swap:";
    cin>>info1;
    cout<<"Enter second info u want to swap:";
    cin>>info2;
    traverse();
    swap(info1,info2);
    cout<<"After Swap."<<endl;
    traverse();
    return 0;
}