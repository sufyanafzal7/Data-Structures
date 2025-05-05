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
            if (head==NULL)
                return '\0';
            return head->info;
        }
};

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

string infixToPostfix(string str){
    LinkedStack s;
    string pExp;
    for(int i=0;i<str.length();i++){
        if(str[i]!='('&& str[i]!='-' && str[i]!='+' && str[i]!='/' && str[i]!='*' && str[i]!=')' && str[i]!='^')
            pExp+=str[i];
        else if(str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            while(s.getPeak()!='('){
                pExp+=s.getPeak();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && precedence(s.getPeak()) >= precedence(str[i])){
                pExp += s.getPeak();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    return pExp;
}

int main(){
    cout<<infixToPostfix("(7*8+2/3-1)");
    return 0;
}