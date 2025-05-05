#include <iostream>
using namespace std;

struct Node{
    char info;
    Node* link;
};

class LinkedStack{
    private:
        Node *head;
    public:
        LinkedStack(){
            head=NULL;
        }

        ~LinkedStack(){

        }

        void push(char num){
            Node *n=new Node;
            n->info=num;
            n->link=head;
            head=n;
        }

        void pop(){
            if(head==NULL){
                cout<<"Stack underflow error."<<endl;
                return;
            }
            Node *temp=head;
            head=head->link;
            cout<<temp->info<<" Poped."<<endl;
            delete temp;
        }

        bool empty(){
            if(head==NULL)
                return true;
            return false;
        }
        char getPeak(){
            return head->info;
        }
};

bool checkBalance(string str){
    LinkedStack s;
    for(int i=0;i<str.length();i++){
        if(isdigit(str[i])|| str[i]==' ')
            continue;
        if(str[i]=='('|| str[i]=='['||str[i]=='{'){
            s.push(str[i]);
            continue;
        }
        if(s.empty()){
            if(!isdigit(str[i])|| str[i]!=' ')
                return false;
            if(i==str.length()-1)
                return true;
            continue;
        }
        char top=s.getPeak()=='('?')':s.getPeak()=='{'?'}':']';
        if(str[i]==top)
            s.pop();
        else
            return false;
    }
    return s.empty();
}

int main(){
    cout<<checkBalance("[()]");
    return 0;
}