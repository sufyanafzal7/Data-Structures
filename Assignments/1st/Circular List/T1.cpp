#include <iostream>
#include <string>
using namespace std;

struct Node{
    int info;
    Node *next;
};

Node *first=NULL;
Node *last=NULL;

void createCircularList(int num){
    if(num<1){
        cout<<"It is impossible to make a zero node circular list."<<endl;
        return;
    }
    Node *n1=new Node;
    n1->info=1;
    n1->next=NULL;
    first=last=n1;
    for(int i=2;i<=num;i++){
        Node *n=new Node;
        n->info=i;
        n->next=first;
        last->next=n;
        last=n;
    }
}

int detectWinner(int N,int M){
    createCircularList(N);
    Node *current=first;
    Node *prev=NULL;
    while(current->next!=current){
        for(int i=1;i<M;i++){
            prev=current;
            current=current->next;
        }
        prev->next=current->next;
        current=current->next;
    }
    int safePosition=current->info;
    delete current;
    return safePosition;
}

int main(){
    int N,M;
    cout<<"Enter number of person:";
    cin>>N;
    cout<<"Enter value of M";
    cin>>M;
    cout<<"The position of winner is:"<<detectWinner(N,M)<<endl;
    return 0;
}