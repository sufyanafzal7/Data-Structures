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

        void push(char number){

            Node *n=new Node;
            n->info=number;
            n->link=head;
            head=n;

        }

        void pop(){

            if(head==NULL){
                cout<<"Stack underflow error Bhaaaiiiii Kia kr rha tu."<<endl;
                return;
            }

            Node *temporary=head;
            head=head->link;
            cout<<temporary->info<<" Popped."<<endl;
            delete temporary;

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

int precedence(char character) {

    if (character == '+' || character == '-')
        return 1;
    if (character == '*' || character == '/')
        return 2;
    if (character == '^')
        return 3;

    return 0;

}

string infixToPostfix(string  expression){

    LinkedStack stacK;
    string postFixExp;

    for(int i=0;i< expression.length();i++){
        if( expression[i]!='('&&  expression[i]!='-' &&  expression[i]!='+' &&  expression[i]!='/' &&  expression[i]!='*' &&  expression[i]!=')' &&  expression[i]!='^')
            postFixExp+= stacK[i];
        else 
        if( expression[i]=='('){
            stacK.push( expression[i]);
        }
        else 
        if( expression[i]==')'){

            while(stacK.getPeak()!='('){
                postFixExp+=stacK.getPeak();
                stacK.pop();
            }

            stacK.pop();

        }
        else
        {
            while(!stacK.empty() && precedence(s.getPeak()) > precedence( expression[i])){
                postFixExp += stacK.getPeak();
                stacK.pop();
            }

            stacK.push( expression[i]);

        }

    }


    while(!stacK.empty()){
        postFixExp += stacK.getPeak();
        stacK.pop();
    }
    return postFixExp;


}


string infixToPrefix(string striNG){

    string reverseStriNG="";

    for(int i=striNG.length()-1;i>=0;i--){

        if(striNG[i]=='(')
            reverseStriNG+=')';
        else 
        if(striNG[i]==')')
            reverseStriNG+='(';
        else
            reverseStriNG+=striNG[i];
    }

    string postfix=infixToPostfix(reverseStriNG);
    string prefix="";

    for(int i=postfix.length()-1;i>=0;i--){
        prefix+=postfix[i];
    }
    return prefix;

}



int main(){

    cout<<infixToPostfix("Z/(X-C)*U+S")<<endl;
    cout<<infixToPrefix("S^B*I-Y+T/F/(A+G)");

    return 0;

}