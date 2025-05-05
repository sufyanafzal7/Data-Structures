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

void removeDuplicates(){
    if(first==NULL){
        cout<<"Linked List not exist:"<<endl;
        return;
    }
    if(first==last)
        return;
    Node *current=first;
    while(current!=NULL){
        Node *prev=current;
        Node *currentOfInnerLoop=current->next;
        while(currentOfInnerLoop!=NULL){
            if(currentOfInnerLoop->info==current->info){
                prev->next=currentOfInnerLoop->next;
                Node *temp=currentOfInnerLoop;
                currentOfInnerLoop=currentOfInnerLoop->next;
                delete temp;
            }
            else{
                prev=currentOfInnerLoop;
                currentOfInnerLoop=currentOfInnerLoop->next;
            }
        }
        current=current->next;
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

int  main(){
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    traverse();
    removeDuplicates();
    traverse();
    return 0;
}
