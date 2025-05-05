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
            head = NULL;
        }

        ~LinkedStack(){

        }

        void push(int number){

            Node *n=new Node;
            n->info=number;
            n->link=head;
            head=n;

        }

        void pop(){

            if(head == NULL){
                cout<<"Stack underflow error Brooooooooooo........"<<endl;
                return;
            }

            Node *temp=head;
            head=head->link;
            cout<<temp->info<<" Popped."<<endl;
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



int calculate(int number1, int number2, char operation) {

    switch(operation) {

        case '+':
            return number1 + number2;
        case '-':
            return number1 - number2;
        case '*':
            return number1 * number2;
        case '/':
            if(number2 != 0)
                return number1 / number2;
            else {
                cout << "Error! Division by zero, Kiya kr rha hai Bhai." << endl;
                return 0;
            }
        default:
            cout << "Invalid operator! Kiya Chahta Hai Bhaai........." << endl;
            return 0;

    }

}



int evaluatePreFix(string striNG){

    LinkedStack staCK;

    for(int i=striNG.length();i>=0;i--){

        if(striNG[i]=='('|| striNG[i]=='-' || striNG[i]=='+' || striNG[i]=='/' || striNG[i]=='*' || striNG[i]==')' || striNG[i]=='^'){

            int num2=staCK.getPeak();
            staCK.pop();
            int num1=staCK.getPeak();
            staCK.pop();
            int ans=calculate(num1,num2,striNG[i]);
            staCK.push(ans);

        }
        else
            staCK.push(striNG[i]-'0');
    }
    return staCK.getPeak();
}



int main(){

    cout<<evaluatePreFix("+6*29");

    return 0;
}