#include <iostream>
using namespace std;

class Stack{
    private:
        int top;
        int *s;
        int l;
    public:
        Stack(int length){
            l=length;
            s=new int[l];
            top=-1;
        }

        Stack (){

        }

        ~Stack (){

        }

        bool isFull(){
            if(top==l-1)
                return true;
            return false;
        }

        void push(int num){
            if(isFull()){
                cout<<"stack overflow comdition:"<<endl;
                return;
            }
            top++;
            s[top]=num;
        }

        bool isEmpty(){
            if(top==-1)
                return true;
            return false;
        }

        void pop(){
            if(isEmpty()){
                cout<<"Stack underflow condition"<<endl;
                return;
            }
            top--;
        }

        int peak(){
            if(isEmpty()){
                cout<<"stack is empty."<<endl;
                return -1;
            }
            return s[top];
        }
};

void checkPallindrome(string str){
    Stack s1(str.length());
    int mid=str.length()/2;
    for(int i=0;i<mid;i++)
        s1.push(str[i]);
    if(str.length()%2!=0)
        mid++;
    bool checker=true;
    for(int i=mid;i<str.length();i++){
        if(s1.peak()==str[i])
            s1.pop();
        else{
            cout<<"The given String is not a Pallindrome";
            checker=false;
            break;
        }
    }
    if(checker)
        cout<<"The string is a pallindrome."<<endl;
}

int main(){
    string str;
    cout<<"Enter a String:";
    cin>>str;
    checkPallindrome(str);
}