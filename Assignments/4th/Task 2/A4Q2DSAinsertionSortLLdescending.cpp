#include <iostream>
using namespace std;

struct customer
{
    int accountNo;
    string title;
    int balance;
    customer *next;
};

customer *first = NULL;
customer *last = NULL;

void insertionSort(customer *&head)
{
    if (head == NULL || head->next == NULL)
        return;

    customer *sorted = NULL; 
    customer *current = head; 

    while (current != NULL)
    {
        customer *next = current->next; 
        if (sorted == NULL || sorted->balance < current->balance)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            customer *temp = sorted;
            while (temp->next != NULL && temp->next->balance >= current->balance)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next; 
    }
    head = sorted; 
}

void addCustomer(int an, string t, int b)
{
    customer *n = new customer;
    n->accountNo = an;
    n->title = t;
    n->balance = b;
    n->next = NULL;
    if (first == NULL)
    {
        first = last = n;
        return;
    }
    last->next = n;
    last = n;
}

void traverse()
{
    if (first == NULL)
    {
        cout << "Empty" << endl;
        return;
    }
    customer *cur = first;
    while (cur != NULL)
    {
        cout << "Title = " << cur->title << "\nAccount Number = " << cur->accountNo << "\nBalance = " << cur->balance << endl;
        cout << "---------------------------------------------------------------------------------------\n";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    
    cout << "------------------------------------------\n";
    cout << "    Insertion Sort for LL Descending"<<endl;
    cout << "------------------------------------------\n";
    
    addCustomer(11, "Atif Aslam", 1500);
    addCustomer(12, "Sufyan Afzal", 2500);
    addCustomer(13, "Ali Zafar", 1200);
    addCustomer(14, "Sonu Nigam", 2200);
    addCustomer(15, "Shreya Ghoshal", 1800);
    addCustomer(16, "Asim Azhar", 1000);
    addCustomer(17, "Young Stunners", 500);
    addCustomer(18, "Arijit Singh", 1400);

    cout << "\nBefore Sorting:\n";
    traverse();

    insertionSort(first);

    cout << "\nAfter Sorting by Balance (Descending):\n";
    traverse();

    return 0;
}
