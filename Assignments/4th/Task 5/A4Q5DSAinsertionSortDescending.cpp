#include <iostream>
using namespace std;

int insertionComparisons = 0, insertionSwaps = 0;

void insertionSort(int arr[], int n) {
    int temp;

    for (int i = 1; i < n; i++) {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < temp) { 
            ++insertionComparisons;
            arr[j + 1] = arr[j];
            j--;
            ++insertionSwaps; 
        }
        ++insertionComparisons; 
        arr[++j] = temp;
    }
}

int main() {
    cout << "------------------------" << endl;
    cout << "     Insertion Sort" << endl;
    cout << "------------------------\n" << endl;

    int arr[7] = {39, 38, 44, 40, 43, 42, 41};
    int n = 7;

    cout << "Values Before Descending order: " << endl << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "No of Comparisons = " << insertionComparisons << "  ,  No of Swaps = " << insertionSwaps << endl;
    cout << endl << endl;

    insertionSort(arr, n);

    cout << "Values in Descending order: " << endl << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "No of Comparisons = " << insertionComparisons << "  ,  No of Swaps = " << insertionSwaps << endl;
    cout << endl << endl;

    return 0;
}
