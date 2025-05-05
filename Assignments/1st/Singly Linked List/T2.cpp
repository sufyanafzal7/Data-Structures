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

void reverseTraverse(Node *current){
    if(current==NULL){
        cout<<"Linked List"<<endl;
        return;
    }
    reverseTraverse(current->next);
    cout<<current->info<<"\t";
    if(current==first)
        cout<<endl;
}

int main(){
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    reverseTraverse(first);
    return 0;
}