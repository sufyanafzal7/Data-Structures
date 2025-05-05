#include <iostream>
using namespace std;

int selectionComparisons = 0, selectionSwaps = 0;

struct Employee {
    int employeeID;
    string name;
};

void selectionSort(Employee arr[], int n) {
    int minIndex = -1;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            ++selectionComparisons; 
            if (arr[j].employeeID < arr[minIndex].employeeID)
                minIndex = j;
        }
        if (minIndex != i) {
            ++selectionSwaps;
            swap(arr[minIndex], arr[i]);
        }
    }
}

int main() {
    cout << "------------------------------------------\n";
    cout << "      Selection Sort for Employees\n";
    cout << "------------------------------------------\n";

    Employee employees[10] = {
        {105, "John"}, {102, "Alice"}, {110, "Eve"},
        {101, "Bob"}, {108, "Charlie"}, {103, "Diana"},
        {107, "Frank"}, {104, "Grace"}, {109, "Hank"},
        {106, "Ivy"}
    };

    int n = 10;

    cout << "\nEmployees Before Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << "ID: " << employees[i].employeeID << ", Name: " << employees[i].name << endl;

    selectionSort(employees, n);

    cout << "\nEmployees After Sorting (Ascending):\n";
    for (int i = 0; i < n; i++)
        cout << "ID: " << employees[i].employeeID << ", Name: " << employees[i].name << endl;

    cout << "\nSelection Sort Statistics:\n";
    cout << "Comparisons: " << selectionComparisons << ", Swaps: " << selectionSwaps << endl;

    return 0;
}
