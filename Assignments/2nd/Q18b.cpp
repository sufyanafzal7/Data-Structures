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

        int peak(){
            return head->info;
        }
};

void checkPallindrome(string str){
    LinkedStack s1;
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