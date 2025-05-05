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
customer *last=NULL;

customer *findMid(customer *head) {
    if (head == NULL || head->next == NULL)
        return head;
    customer *slow = head;
    customer *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

customer *merge(customer *left, customer *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    customer *dummy = new customer;
    customer *newList = dummy;

    while (left != NULL && right != NULL)
    {
        if (left->yearsOfExperience >= right->yearsOfExperience)
        {
            newList->next = left;
            left = left->next;
        }
        else
        {
            newList->next = right;
            right = right->next;
        }
        newList = newList->next;
    }

    if (left != NULL)
        newList->next = left;
    else
        newList->next = right;

    customer *res = dummy->next;
    delete dummy;
    return res;
}

customer *mergeRec(customer *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    customer *mid = findMid(head);
    customer *left = head;
    customer *right = mid->next;
    mid->next = NULL;
    left = mergeRec(left);
    right = mergeRec(right);
    customer *result = merge(left, right);
    return result;
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
        first = last=n;
        return;
    }
    last->next=n;
    last=n;
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
        cout << "Name = " << cur->name << "\nSerial Number = " << cur->serialNo <<"\nSalary = "<<cur->salary<< "\nYears of Experience = " << cur->yearsOfExperience << endl;
        cout << "-------------------------------------------\n";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{

    addCustomer(11, "Atif Aslam", 15, 1500);
    addCustomer(12, "Sufyan Afzal", 25, 2500);
    addCustomer(13, "Ali Zafar", 12, 1200);
    addCustomer(14, "Sonu Nigam", 22, 2200);
    addCustomer(15, "Shreya Ghoshal", 18, 1800);
    addCustomer(16, "Asim Azhar", 10, 1000);
    addCustomer(17, "Young Stunners", 5, 500);
    addCustomer(18, "Arijit Singh", 14, 1400);

    cout << "\nBefore Sorting:\n";
    traverse();
    first = mergeRec(first);
    cout << "\nAfter Sorting by Balance (Descending):\n";
    traverse();

    return 0;
}