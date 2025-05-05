#include <iostream>
using namespace std;

struct Candidate {
    int employee;
    int experience;
};

void merge(Candidate *arr, int start, int end) {
    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    Candidate *firstArr = new Candidate[len1];
    Candidate *secondArr = new Candidate[len2];

    // Copy 1st values to temporary arrays
    int mainArrayIndex = start;
    for (int i = 0; i < len1; i++) {
        firstArr[i] = arr[mainArrayIndex++];
    }

    // Copy 2nd values to temporary arrays
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        secondArr[i] = arr[mainArrayIndex++];
    }

    // Merge 2 sorted arrays
    int index1 = 0, index2 = 0;
    mainArrayIndex = start;

    while (index1 < len1 && index2 < len2) {
        if (firstArr[index1].experience > secondArr[index2].experience) {
            arr[mainArrayIndex++] = firstArr[index1++];
        } else {
            arr[mainArrayIndex++] = secondArr[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainArrayIndex++] = firstArr[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = secondArr[index2++];
    }

    delete[] firstArr;
    delete[] secondArr;
}

void mergeSort(Candidate *arr, int start, int end) {

    // base case
    if (start >= end) return;

    int mid = (start + end) / 2;

    // Sort left part
    mergeSort(arr, start, mid);

    // Sort right part
    mergeSort(arr, mid + 1, end);

    // Merge sorted parts
    merge(arr, start, end);
}

int main() {
    const int n = 100;
    Candidate candidates[n];

    // Initialize candidates with random experience values (for demonstration)
    for (int i = 0; i < n; i++) {
        candidates[i].employee = i + 1;
        candidates[i].experience = rand() % 21; // Random experience between 0 and 20 years
    }

    // Sort candidates by experience in descending order
    mergeSort(candidates, 0, n - 1);

    // Display sorted candidates
    cout << "Sorted candidates by experience (descending):\n";
    for (int i = 0; i < n; i++) {
        cout << "Employee ID: " << candidates[i].employee << ", Experience: " << candidates[i].experience << " years\n";
    }

    return 0;
}
