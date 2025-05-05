#include <iostream>
using namespace std;

int bubbleComparisons = 0, bubbleSwaps = 0;

void bubbleSort(int arr[], int n){
 
 for(int i=0; i < (n-1); i++){
  
  for(int j = 0; j < (n-1-i); j++){
      ++bubbleComparisons;
  if(arr[j] > arr[j+1]){
      ++bubbleSwaps;
      swap( arr[j],arr[j+1] );
      }}}}


int main(){
    
    cout << "------------------------" <<endl;
    cout << "      Bubble Sort"<<endl;
    cout << "------------------------\n" <<endl;
    
    int arr[7] = {39,38,44,40,43,42,41};
    int n = 7;

    
    cout << "Values Before Ascending order: "<< endl<<endl;
    for(int i = 0; i<n; i++)
    cout << arr[i] << " ";
    cout<< endl;
    cout << "No of Camparisons = "<< bubbleComparisons << "  ,  No of Swaps = " << bubbleSwaps<< endl;
    cout<< endl<<endl;

    bubbleSort(arr, n);
    
    cout << "Values in Ascending order: "<< endl<<endl;
    for(int i = 0; i<n; i++)
    cout << arr[i] << " ";
    cout<< endl;
    cout << "No of Camparisons = "<< bubbleComparisons << "  ,  No of Swaps = " << bubbleSwaps<< endl;
    cout<< endl<<endl;

    
    return 0;
}








        

