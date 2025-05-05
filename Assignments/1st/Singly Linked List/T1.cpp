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

void reverse(){
    Node *prev=NULL;
    Node *current=first;
    Node *next;

    while(current!=NULL){
        next=current->next;

        current->next=prev;

        prev=current;
        current=next;
    }
    Node *temp=first;
    first=last;
    last=temp;
}

void displayReverse(){
    reverse();
    traverse();
    reverse();
}

int main(){
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    cout<<"original List:"<<endl;
    traverse();
    cout<<"Reversed list:"<<endl;
    displayReverse();
    return 0;
}