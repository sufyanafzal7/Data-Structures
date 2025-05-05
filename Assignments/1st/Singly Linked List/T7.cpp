#include<iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
};

class Linkedlist{
    private:
        Node *first,*last;
    public:
        Linkedlist(){
            first=NULL;
            last=NULL;
        }

        ~Linkedlist(){

        }

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

        void spit(Linkedlist &evenList, Linkedlist &oddList){
            Node *current=first;
            while(current!=NULL){
                if(current->info%2==0){
                    if(evenList.first==NULL)
                        evenList.first=evenList.last=current;
                    else{
                        evenList.last->next=current;
                        evenList.last=current;
                    }
                }
                else{
                    if(oddList.first==NULL)
                        oddList.first=oddList.last=current;
                    else{
                        oddList.last->next=current;
                        oddList.last=current;
                    }
                }
                current=current->next;
            }
            if(evenList.last!=NULL)
                evenList.last->next=NULL;
            if(oddList.last!=NULL)
                oddList.last->next=NULL;
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
};

int main(){
    Linkedlist l;
    for(int i=0;i<=9;i++){
        l.insertLast();
    }
    cout<<"Oringinal list:"<<endl;
    l.traverse();
    Linkedlist evenList,oddList;
    l.spit(evenList,oddList);
    cout<<"Even list:"<<endl;
    evenList.traverse();
    cout<<"Odd list:"<<endl;
    oddList.traverse();
    return 0;
}