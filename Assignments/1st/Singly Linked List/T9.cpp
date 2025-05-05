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

int countNode(){
    Node *current=first;
    int count=0;
    while(current !=NULL){
        count=count+1;
        current=current->next;
    }
    return count;
}

void reverse1stAnd2ndHalf(){
    Node *prev=NULL;
    Node *current=first;
    Node *next;
    int limit=countNode()/2;

    for(int i=1;i<=limit;i++){
        next=current->next;

        current->next=prev;

        prev=current;
        current=next;
    }
    first->next=last;
    first=prev;
    prev=NULL;

    while(current!=NULL){
        next=current->next;

        current->next=prev;

        prev=current;
        current=next;
    }
    last=prev;
}

void reversePair(){
    Node *current=first;
    Node *prev=NULL;
    Node *next;
    Node *temp;
    while (current!=NULL && current->next!=NULL){
        next=(current->next)->next;
        temp=current->next;
        current->next=next;
        temp->next=current;
        if(prev==NULL)
            first=temp;
        else    
            prev->next=temp;
        prev=current;
        current=next;
    }
    if(current==NULL)
        last=prev;
}

int main(){
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    reverse1stAnd2ndHalf();
    traverse();
    reversePair();
    traverse();
    return 0;
}