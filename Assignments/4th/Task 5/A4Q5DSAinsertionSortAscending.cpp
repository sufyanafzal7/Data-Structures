#include <iostream>
using namespace std;

int insertionComparisons = 0, insertionSwaps = 0;

void insertionSort(int arr[], int n){
 
 int temp;
 
 for(int i=1; i<n; i++){
     temp = arr[i];
     int j = i-1;
     while(j>=0 && arr[j]>temp){
                     ++insertionComparisons; // Count comparisons
         arr[j+1] = arr[j];
         j--;
                     ++insertionSwaps; // Count swaps
         }
                 ++insertionComparisons; // Count the last comparison when while fails
         arr[++j] = temp;
     }
    
}

int main(){
    
        
    cout << "------------------------" <<endl;
    cout << "     Insertion Sort"<<endl;
    cout << "------------------------\n" <<endl;
    
    int arr[7] = {39,38,44,40,43,42,41};
    int n = 7;

    
    cout << "Values Before Ascending order: "<< endl<<endl;
    for(int i = 0; i<n; i++)
    cout << arr[i] << " ";
    cout<< endl;
    cout << "No of Camparisons = "<< insertionComparisons << "  ,  No of Swaps = " << insertionSwaps<< endl;
    cout<< endl<<endl;

    insertionSort(arr, n);
    
    cout << "Values in Ascending order: "<< endl<<endl;
    for(int i = 0; i<n; i++)
    cout << arr[i] << " ";
    cout<< endl;
    cout << "No of Camparisons = "<< insertionComparisons << "  ,  No of Swaps = " << insertionSwaps<< endl;
    cout<< endl<<endl;

    
    return 0;
}








        

