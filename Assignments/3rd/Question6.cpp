#include <iostream>
using namespace std;

struct Product
{
    int ID;
    int expiry;
};

class MinHeap
{
private:
    Product *arr;
    int index;
    int L;

    void trickleUp(int i)
    {
        int parent = (i - 1) / 2;
        while (parent >= 0 && arr[i].expiry < arr[parent].expiry)
        {
            swap(arr[i].expiry, arr[parent].expiry);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void trickleDown(int i)
    {
        int leftChild, rightChild, minValex;
        while (true)
        {
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            minValex = i;

            if (leftChild <= index && arr[minValex].expiry > arr[leftChild].expiry)
                minValex = leftChild;
            if (rightChild <= index && arr[minValex].expiry > arr[rightChild].expiry)
                minValex = rightChild;
            if (minValex == i)
                break;
            swap(arr[i], arr[minValex]);
            i = minValex;
        }
    }

public:
    MinHeap(int l)
    {
        L = l;
        index = -1;
        arr = new Product[L];
    };

    void insert(int id, int exp)
    {
        Product p;
        p.ID = id;
        p.expiry = exp;

        if (index == L - 1)
        {
            cout << "Heap is full" << endl;
            return;
        }
        index++;
        arr[index] = p;
        trickleUp(index);
    }

    void remove()
    {
        if (index == -1)
        {
            cout << "Empty Heap" << endl;
            return;
        }
        cout << "Product ID = " << arr[0].ID << " | Days till Expiry = " << arr[0].expiry << "\n------------------------------------" << endl;
        arr[0] = arr[index];
        index--;
        trickleDown(0);
    }
};

int main()
{
    MinHeap h1(10);
    h1.insert(1124, 34);
    h1.insert(1654, 74);
    h1.insert(1864, 14);
    h1.insert(2224, 94);
    h1.remove();
    h1.remove();
    h1.insert(4324, 4);
    h1.insert(5524, 64);
    h1.remove();
    h1.remove();
    h1.remove();
    h1.remove();
    h1.remove();
}
