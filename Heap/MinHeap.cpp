#include <iostream>
#include <cmath> 

using namespace std;

class Heap {
private:
    int *h;  
    int l;   
    int size; 

public:
    Heap(int len) {
        l = len;
        h = new int[l];
        size = -1; 
    }

    void trickleUp(int i) {
        int parent = (i - 1) / 2;
        while (parent >= 0 && h[i] < h[parent]) {
            swap(h[i], h[parent]);
            i = parent;
            parent = (parent - 1) / 2;
        }
    }

    void insert(int num) {
        if (size == (l - 1)) {
            cout << "Heap is Full" << endl;
            return;
        }
        size++;
        h[size] = num;
        trickleUp(size);
    }

    void trickleDown(int i) {
        int leftChild, rightChild, minIndex;
        while (true) {
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            minIndex = i;

            if (leftChild <= size && h[leftChild] < h[minIndex]) {
                minIndex = leftChild;
            }
            if (rightChild <= size && h[rightChild] < h[minIndex]) {
                minIndex = rightChild;
            }
            if (minIndex == i) break;

            swap(h[i], h[minIndex]);
            i = minIndex;
        }
    }

    void deleteRoot() {
        if (size == -1) {
            cout << "Nothing to Delete." << endl;
            return;
        }
        h[0] = h[size];
        size--;
        trickleDown(0);
    }

    void display() {
        if (size == -1) {
            cout << "Heap is empty." << endl;
            return;
        }
        for (int i = 0; i <= size; i++) {
            cout << h[i] << " ";
        }
        cout << endl;
    }

    ~Heap() {
        delete[] h;
    }
};

int main() {
    Heap heap(10);

    heap.insert(9);
    heap.insert(8);
    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(1);

    cout << "Heap after insertions: ";
    heap.display();

    heap.deleteRoot();

    cout << "Heap after deleting root: ";
    heap.display();

    heap.insert(0);

    cout << "Heap after final insertion: ";
    heap.display();

    return 0;
}
