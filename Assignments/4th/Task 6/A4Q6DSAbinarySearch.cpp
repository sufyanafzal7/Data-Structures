#include <iostream>
using namespace std;
bool check = false;

void binarySearch(int arr[], int key, int size){
 
int LB = 0;
int UB = size - 1;
int mid;

while(LB <= UB){
    mid = ceil((LB+UB)/2);
    
    if( key == arr[mid]){
        cout << "Element Found at:  "<< mid<<"th Index" << endl;
        check = true;
        return;
        }
        if(key < arr[mid])
        UB = mid -1;
        else
        LB = mid+1;
    }
    
}

int main(){
    
        
    cout << "------------------------" <<endl;
    cout << "     Binary Search"<<endl;
    cout << "------------------------\n" <<endl;
    
    const int n = 100;
    int arr[n];
    
    for(int i =0; i<n; i++)
    arr[i] = i+1;



    binarySearch(arr, 26,n);
    

    cout<< endl;
    
    if(check == false)
    cout << "Sorry Element is not found.";

    
    return 0;
}








        

