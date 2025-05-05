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

bool checkBalance(string str,char bracket){
    char closeBracket=bracket=='('?')':bracket=='{'?'}':']';
    int closeCount,openCount;
    LinkedStack s;
    for(int i=0;i<str.length();i++){
        if(str[i]==bracket)
            openCount++;
        if(str[i]==closeBracket)
            closeCount++;
    }
    if(openCount==closeCount)
        return true;
    return false;
}

int main(){
    cout<<checkBalance("()",'(');
    return 0;
}