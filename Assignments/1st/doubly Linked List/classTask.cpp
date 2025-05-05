#include <iostream>
#include <string>
using namespace std;

struct Video{
    int id;
    string name;
    string descrip;
    Video *next;
    Video *prev;
};

Video *first=NULL;
Video *last=NULL;

void insertVid(){
    Video *newVid=new Video;
    cout<<"Enter name of vid:";
    cin>>newVid->name;
    cout<<"Enter description:";
    cin>>newVid->descrip;
    newVid->prev=NULL;
    newVid->next=NULL;

    if(first==NULL){
        first=last=newVid;
        newVid->id=1;
        return;
    }

    newVid->id=first->id+1;
    newVid->next=first;
    first->prev=newVid;
    first=newVid;
    last->next=first;
}

void deleteVid(){
    if(first==NULL){
        cout<<"List not exist."<<endl;
        return;
    }
    if(first==last){
        Video *temp=first;
        first=last=NULL;
        delete first;
        return;
    }
    if(first->next==last){
        Video *temp=last;
        last=first;
        first->next=NULL;
        delete last;
        return;
    }
    Video *temp=last;
    last->prev->next=first;
    last=last->prev;
    delete temp;
}

void forwardPlay(){
    if(first==NULL){
        cout<<"List not exist"<<endl;
        return;
    }
    Video *current=first;
    do{
        cout<<"name :"<<current->name<<" id:"<<current->id<<"\t";
        current=current->next;
    }while(current!=first);
    cout<<endl;
}

void reversePlay(){
    if(first==NULL){
        cout<<"List not exist"<<endl;
        return;
    }
    Video *current=last;
    do{
        cout<<"name :"<<current->name<<" id:"<<current->id<<"\t";
        current=current->prev;
    }while(current!=NULL);
    cout<<endl;
}

void loopPlay(){
    if(first==NULL){
        cout<<"List not exist"<<endl;
        return;
    }
    Video *current=first;
    while(true){
        cout<<"name :"<<current->name<<" id:"<<current->id<<"\t";
        current=current->next;
        if(current==first){
            int checker=1;
            cout<<"\nYou want to start  the playlist Again.\nEnter 1 for yes and 2 for No:";
            cin>>checker;
            if(checker==2)
                break;
        }
    }
    cout<<endl;
}

Video* searchById(int id){
    if(first==NULL){
        cout<<"List not exist"<<endl;
        return NULL;
    }
    Video *current=first;
    do{
        current=current->next;
        if(current->id==id)
            return current;
    }while(current!=first);
    return NULL;
}

void specificPlay(){
    int vidId;
    cout<<"Enter id of vid u want to play:";
    cin>>vidId;
    Video* current=searchById(vidId);

    if(current==NULL){
        cout<<"Vid not exist."<<endl;
        return;
    }

    while(true){
        cout<<"name :"<<current->name<<" id:"<<current->id<<"\t";
        current=current->next;
        if(current==first){
            int checker=1;
            cout<<"\nYou want to start  the playlist Again.\nEnter 1 for yes and 2 for No:";
            cin>>checker;
            if(checker==2)
                break;
        }
    }
    cout<<endl;   
}

int main(){
    insertVid();
    insertVid();
    insertVid();
    insertVid();
    insertVid();
    insertVid();
    cout<<"Forward play:"<<endl;
    forwardPlay();
    cout<<"Reverse play:"<<endl;
    reversePlay();
    cout<<"delete"<<endl;
    deleteVid();
    cout<<"Forward play:"<<endl;
    forwardPlay();
    cout<<"Loop play:"<<endl;
    loopPlay();
    cout<<"Specific play:"<<endl;
    specificPlay();
    return 0;
}