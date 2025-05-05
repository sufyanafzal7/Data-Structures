#include <iostream>
using namespace std;

int mergeComparisons = 0, mergeSwaps = 0;

void merge(int *arr, int start, int end){
    int mid = (start+end)/2;
    
    int len1 = mid-start+1;
    int len2 = end-mid;
    
    int *firstArr = new int[len1];
    int *secondArr = new int[len2];
    
    // copy values
    int mainArrayIndex = start;
    for(int i = 0; i<len1; i++){
        firstArr[i] = arr[mainArrayIndex++];}
    
    // copy 2nd values
    mainArrayIndex = mid+1;
    for(int i = 0; i<len2; i++){
        secondArr[i] = arr[mainArrayIndex++];}
        
    // Merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;
    
    while(index1<len1 && index2<len2){
                ++mergeComparisons; // Count comparisons
        if(firstArr[index1] < secondArr[index2])
        arr[mainArrayIndex++] = firstArr[index1++];
        else
        arr[mainArrayIndex++] = secondArr[index2++];
        
        }
    
    while(index1<len1){
                ++mergeSwaps; // Count swaps
        arr[mainArrayIndex++] = firstArr[index1++];}
        
    while(index2<len2){
                ++mergeSwaps; // Count swaps
        arr[mainArrayIndex++] = secondArr[index2++];}
        
        delete[] firstArr;
        delete[] secondArr;
        
}

void mergeSort(int *arr, int start, int end){
    
    // base cASE
    if(start>=end) return;
    
    int mid = (start+end)/2;
    
    // left part sorting
    mergeSort(arr, start, mid);
    
    // right part sorting
    mergeSort(arr, mid+1, end);
    
    // merge
    merge(arr, start, end);
    
    }

int main(){
    
        
    cout << "------------------------" <<endl;
    cout << "       Merge Sort"<<endl;
    cout << "------------------------\n" <<endl;
    
    int arr[7] = {39,38,44,40,43,42,41};
    int n = 7;

    
    cout << "Values Before Ascending order: "<< endl;
    for(int i = 0; i<n; i++)
    cout << arr[i] << " ";
    cout<< endl;
    
    cout << "Number of Comparisons: " << mergeComparisons;
    cout << "  ,  Number of Swaps: " << mergeSwaps << endl;
    cout<< endl;
    cout<< endl;

    
    int start = 0; int end = n-1;
    mergeSort(arr, start, end);
    
    cout << "Values in Ascending order: "<< endl;
    for(int i = 0; i<n; i++)
    cout << arr[i] << " ";
    cout<< endl;

    cout << "Number of Comparisons: " << mergeComparisons;
    cout << "  ,  Number of Swaps: " << mergeSwaps << endl;
    
    return 0;
}








        

