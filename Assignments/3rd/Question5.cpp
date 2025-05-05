#include <iostream>
using namespace std;

class MaxHeap
{
private:
    int *arr;
    int index;
    int L;

    void trickleUp(int i)
    {
        int parent = (i - 1) / 2;
        while (parent >= 0 && arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void trickleDown(int i)
    {
        int leftChild, rightChild, maxValex;
        while (true)
        {
            leftChild = (2 * i) + 1;
            rightChild = (2 * i) + 2;
            maxValex = i;
            if (leftChild <= index && arr[maxValex] < arr[leftChild])
                maxValex = leftChild;
            if (rightChild <= index && arr[maxValex] < arr[rightChild])
                maxValex = rightChild;
            if (maxValex == i)
                break;
            swap(arr[i], arr[maxValex]);
            i = maxValex;
        }
    }

public:
    MaxHeap(int l)
    {
        L = l;
        index = -1;
        arr = new int[L];
    };

    void insert(int x)
    {
        if (index == L - 1)
        {
            cout << "Heap Full!" << endl;
            return;
        }
        index++;
        arr[index] = x;
        trickleUp(index);
    }

    void remove()
    {
        if (index == -1)
        {
            cout << "Heap Empty!" << endl;
            return;
        }
        cout << "Removed = " << arr[0] << endl;
        arr[0] = arr[index];
        index--;
        trickleDown(0);
    }
};

int main()
{
    MaxHeap h1(10);
    h1.insert(54);
    h1.insert(64);
    h1.insert(514);
    h1.insert(214);
    h1.insert(84);
    h1.remove();
    h1.insert(1000);
    h1.remove();
    h1.remove();
    h1.remove();
    h1.remove();
    h1.remove();
}
