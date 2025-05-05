#include <iostream>
using namespace std;

struct customer
{
    int serialNo;
    string name;
    int yearsOfExperience;
    int salary;
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
        if (sorted == NULL || sorted->yearsOfExperience < current->yearsOfExperience)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            customer *temp = sorted;
            while (temp->next != NULL && temp->next->yearsOfExperience >= current->yearsOfExperience)
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

void addCustomer(int sr, string NAME, int yoe, int s)
{
    customer *n = new customer;
    n->serialNo = sr;
    n->name = NAME;
    n->yearsOfExperience = yoe;
    n->salary = s;
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
        cout << "Name = " << cur->name << "\nSerial Number = " << cur->serialNo << "\nSalary = " << cur->salary << "\nYears of Experience = " << cur->yearsOfExperience << endl;
        cout << "-------------------------------------------\n";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{

    cout << "------------------------------------------\n";
    cout << "    Insertion Sort for LL Descending" << endl;
    cout << "------------------------------------------\n";

    addCustomer(11, "Atif Aslam", 15, 1500);
    addCustomer(12, "Sufyan Afzal", 25, 2500);
    addCustomer(13, "Ali Zafar", 12, 1200);
    addCustomer(14, "Sonu Nigam", 22, 2200);
    addCustomer(15, "Shreya Ghoshal", 18, 1800);
    addCustomer(16, "Asim Azhar", 10, 1000);
    addCustomer(17, "Young Stunners", 5, 500);
    addCustomer(18, "Arijit Singh", 14, 1400);

    cout << "\nBefore Sorting:\n\n";
    traverse();

    insertionSort(first);

    cout << "\nAfter Sorting by Years of Experience (Descending):\n\n";
    traverse();

    return 0;
}
