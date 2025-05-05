#include <iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
    Node *prev;
};

Node *first=NULL;
Node *last=NULL;

void insertLast(){
    Node *n=new Node;
    cout<<"Enter input:";
    cin>>n->info;
    n->next=NULL;
    n->prev=NULL;
    if(first==NULL)
        first=last=n;
    else{
        n->prev=last;
        last->next=n;
        last=n;
    }
}

void swapNodes(Node *node1, Node *node2){
    if(node1==node2)
        return;

    if(node1==first) 
        first=node2;
    if(node2==last) 
        last=node1;

    if (node1->next!=NULL) 
        node1->next->prev=node2;
    if (node2->next != NULL) 
        node2->next->prev=node1;

    if (node1->prev != NULL) 
        node1->prev->next=node2;
    if (node2->prev != NULL) 
        node2->prev->next=node1;

    Node *tempNext=node1->next;
    Node *tempPrev=node1->prev;

    node1->next=node2->next;
    node1->prev=node2->prev;

    node2->next=tempNext;
    node2->prev=tempPrev;
}

void swapAlternate(){
    if (first == NULL || first->next == NULL){
        cout << "Linked list does not have enough nodes to swap." << endl;
        return;
    }

    Node *currentStart=first->next;
    Node *currentEnd=last->prev;

    while(currentStart!=currentEnd && currentStart->prev!=currentEnd){
        swapNodes(currentStart, currentEnd);

        currentStart=currentStart->next;
        if (currentStart!=NULL)
            currentStart=currentStart->next;

        currentEnd=currentEnd->prev;
        if (currentEnd!=NULL)
            currentEnd=currentEnd->prev;
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

int main(){
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    swapAlternate();
    traverse();
    return 0;
}