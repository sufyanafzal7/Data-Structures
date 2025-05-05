#include <iostream>
using namespace std;

struct Node{
    int info;
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

        void push(int num){
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
        int getPeak(){
            if (head==NULL)
                return '\0';
            return head->info;
        }
};

int calculate(int num1, int num2, char operation) {
    switch(operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2 != 0)
                return num1 / num2;
            else {
                cout << "Error! Division by zero." << endl;
                return 0;
            }
        default:
            cout << "Invalid operator!" << endl;
            return 0;
    }
}

int evaluatePostFix(string str){
    LinkedStack s;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('|| str[i]=='-' || str[i]=='+' || str[i]=='/' || str[i]=='*' || str[i]==')' || str[i]=='^'){
            int num2=s.getPeak();
            s.pop();
            int num1=s.getPeak();
            s.pop();
            int ans=calculate(num1,num2,str[i]);
            s.push(ans);
        }
        else
            s.push(str[i]-'0');
    }
    return s.getPeak();
}

int main(){
    cout<<evaluatePostFix("92+53-*");
    return 0;
}