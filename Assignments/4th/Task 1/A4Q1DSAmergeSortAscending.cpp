#include <iostream>
using namespace std;

struct Candidate{
  int employee;
  int experience;
};

void merge(Candidate *arr, int start, int end){
    int mid = (start+end)/2;
    
    int len1 = mid-start+1;
    int len2 = end-mid;
    
    Candidate *firstArr = new Candidate[len1];
    Candidate *secondArr = new Candidate[len2];
    
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
        if(firstArr[index1].experience < secondArr[index2].experience)
        arr[mainArrayIndex++] = firstArr[index1++];
        else
        arr[mainArrayIndex++] = secondArr[index2++];
        
        }
    
    while(index1<len1){
        arr[mainArrayIndex++] = firstArr[index1++];}
        
    while(index2<len2){
        arr[mainArrayIndex++] = secondArr[index2++];}
        
        delete[] firstArr;
        delete[] secondArr;
        
}

void mergeSort(Candidate *arr, int start, int end){
    
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
    const int n = 100;
    Candidate c[n];
    
    for(int i = 0; i<n ; i++){
        c[i].employee = i+1;
        c[i].experience = rand() % 21;     
    }
    
    int start = 0; int end = n-1;
    mergeSort(c, start, end);
    
    // Display sorted candidates
    cout << "Sorted candidates by experience (Ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << "Employee ID: " << c[i].employee << ", Experience: " << c[i].experience << " years\n";
    }
    
    
    return 0;
}








        

