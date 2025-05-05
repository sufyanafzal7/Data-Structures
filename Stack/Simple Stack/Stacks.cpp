#include<iostream>
using namespace std;

class Stack{
    private:
    int top;
    int *s;
    int length;
    public:
    Stack(int l){
        length=l;
        s=new int[length];
        top=-1;
    }

    bool isFull(){
        if(top==length-1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }

    void push(int d){
        if(isFull()){
            cout<<"Stack overflow condition";
            return;
        }
        top++;
        s[top]=d;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack underflow condition"<<endl;
            return;
        }
        int temp=s[top];
        s[top--];
    }

    int peak(){
        if(isEmpty()){
            cout<<"Stack underflow condition";
            return -1;
        }
        return s[top];
    }


};

int main(){
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout<<s1.peak()<<endl;
    s1.pop();
    cout<<s1.peak()<<endl;
    s1.pop();
    cout<<s1.peak()<<endl;
    s1.pop();
    cout<<s1.peak()<<endl;
    s1.pop();
    cout<<s1.peak()<<endl;
    s1.pop();
    cout<<s1.peak()<<endl;
    s1.pop();
    
}