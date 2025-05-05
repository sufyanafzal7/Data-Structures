#include <iostream>
#include <string>
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

bool detectLoop(){
    Node *slow=first;
    Node *fast=first;
    int i=0;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=(fast->next)->next;
        if(fast==slow)
            return true;
    }
    return false;
}

int main(){
    insertLast();
    insertLast();
    Node *temp=last;
    insertLast();
    insertLast();
    insertLast();
    last->next=temp;
    string a=detectLoop()?"Yes":"No";
    cout<<"Loop Exist?"<<a<<endl;
    return 0;
}