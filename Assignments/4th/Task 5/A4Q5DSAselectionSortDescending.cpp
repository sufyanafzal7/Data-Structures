#include <iostream>
using namespace std;

int selectionComparisons = 0, selectionSwaps = 0;

void selectionSort(int arr[], int n){
 
 int minIndex = -1;
 
 for(int i=0; i<n-1; i++){
     minIndex = i;
     for(int j=i+1; j<n; j++){
                     ++selectionComparisons; // Count comparisons
         if(arr[j] > arr[minIndex])
         minIndex = j;
         }
         if(minIndex != i){
                     ++selectionSwaps; // Count swaps
         swap( arr[minIndex],arr[i]);}
     }
    
}

int main(){
    
        
    cout << "------------------------" <<endl;
    cout << "     Selection Sort"<<endl;
    cout << "------------------------\n" <<endl;
    
    int arr[7] = {39,38,44,40,43,42,41};
    int n = 7;

    
    cout << "Values Before Descending order: "<< endl<<endl;
    for(int i = 0; i<n; i++)
    cout << arr[i] << " ";
    cout<< endl;
    cout << "No of Camparisons = "<< selectionComparisons << "  ,  No of Swaps = " << selectionSwaps<< endl;
    cout<< endl<<endl;

    selectionSort(arr, n);
    
    cout << "Values in Descending order: "<< endl<<endl;
    for(int i = 0; i<n; i++)
    cout << arr[i] << " ";
    cout<< endl;
    cout << "No of Camparisons = "<< selectionComparisons << "  ,  No of Swaps = " << selectionSwaps<< endl;
    cout<< endl<<endl;

    
    return 0;
}








        

