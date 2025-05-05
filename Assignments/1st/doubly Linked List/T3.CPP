#include<iostream>
#include<string>
using namespace std;

struct Ride{
    double km;          
    double charges;      
    string riderName;   
    Ride* next; 
    Ride *prev;        
};

struct Car{
    string driverName;  
    string carName;    
    string regNumber;  
    int carType;       
    Ride* rideFirst;  
    Ride* rideLast; 
    Car* next;
    Car* prev;          
};

Car *carFirst = NULL;
Car *carLast = NULL;

void registerCar(string driverName,string carName,string regNumber,int carType){
    Car* newCar=new Car;
    newCar->driverName=driverName;
    newCar->carName=carName;
    newCar->regNumber=regNumber;
    newCar->carType=carType;
    newCar->rideFirst=NULL;
    newCar->rideLast=NULL;
    newCar->next=NULL;
    newCar->prev=NULL;

    if(carFirst==NULL){
        carFirst=carLast=newCar;
        return;
    }
    else{
        newCar->prev=carLast;
        carLast->next=newCar;
        carLast=newCar;
    }
}

void displayCars(){
    Car* currentCar=carFirst;
    cout<<"Cars"<<endl;
    while(currentCar!=NULL){
        cout<< "Driver: "<<currentCar->driverName<<", Car: "<< currentCar->carName<< ", Registration: "<< currentCar->regNumber << ", Type: " << currentCar->carType << endl;
        currentCar = currentCar->next;
    }
    cout<<endl;
}

void displayType2Cars(){
    Car* currentCar=carFirst;
    cout<<"Cars with Type 2"<<endl;
    while (currentCar != NULL) {
        if (currentCar->carType==2)
            cout << "Driver: "<< currentCar->driverName << ", Car: " << currentCar->carName << ", Registration: " << currentCar->regNumber << endl;
        currentCar = currentCar->next;
    }
    cout<<endl;
}

Car* searchCar(string regNumber){
    Car* currentCar=carFirst;
    while (currentCar != NULL){
        if (currentCar->regNumber==regNumber)
            return currentCar;
        currentCar=currentCar->next;
    }
    return NULL;
}

void addRide(string regNumber,double km,double charges,string riderName){
    Car *currentCar=searchCar(regNumber);
    if(currentCar==NULL){
        cout<<"Car not found."<<endl;
        return;
    }
    Ride* newRide=new Ride;
    newRide->km=km;
    newRide->charges=charges;
    newRide->riderName=riderName;
    newRide->next=NULL;

    if (currentCar->rideFirst==NULL){
        currentCar->rideFirst =currentCar->rideLast= newRide;
        return;
    }
    newRide->prev=currentCar->rideLast;
    (currentCar->rideLast)->next=newRide;
    currentCar->rideLast=newRide;
}

void displayRides(string regNumber) {
    Car* currentCar= searchCar(regNumber);
    if(currentCar==NULL){
        cout << "Car with registration number " << regNumber << " not found." << endl;
        return;
    }
    cout<<"Rides of car with reNumber="<<regNumber<<":"<<endl;
    Ride *currentRide=currentCar->rideFirst;
    while(currentRide!=NULL){
        cout << "Rider: " << currentRide->riderName<< ", Km: "<< currentRide->km<< ", Charges: " <<currentRide->charges<< endl;
        currentRide=currentRide->next;
    }
    cout<<endl;
}

void displayEarning(string regNumber){
    Car* currentCar= searchCar(regNumber);
    if(currentCar==NULL){
        cout << "Car with registration number " << regNumber << " not found." << endl;
        return ;
    }
    double earning=0;
    Ride *currentRide=currentCar->rideFirst;
    while(currentRide!=NULL){
        earning+=currentRide->charges;
        currentRide=currentRide->next;
    }
    cout<<"Earning of car with regNO "<<regNumber<< " is "<<earning<<endl<<endl;
}

void displayAllEarning(){
    Car* currentCar=carFirst;
    cout<<"All earnings:"<<endl;
    while(currentCar!=NULL){
        double earning=0;
        Ride *currentRide=currentCar->rideFirst;
        while(currentRide!=NULL){
            earning+=currentRide->charges;
            currentRide=currentRide->next;
        }
        cout<<"regNumber="<<currentCar->regNumber<<"\tEarning="<<earning<<endl;
        currentCar=currentCar->next;
    }
    cout<<endl;
}

int main(){
    registerCar("Aman","ABC","123",1);
    addRide("123",12,3000,"Ahsan");
    addRide("123",2.6,900,"Joun");
    addRide("123",20,6000,"Abdurrehman");

    registerCar("Saim","DEF","456",2);  
    addRide("456",1.5,300,"Ahsan");
    addRide("456",2.6,900,"Joun");
    addRide("456",20,6000,"Abdurrehman");  
    displayCars();
    displayRides("123");
    displayEarning("123");
    displayType2Cars();
    displayAllEarning();
    return 0;
}
