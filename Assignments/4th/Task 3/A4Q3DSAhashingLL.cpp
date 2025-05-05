#include <iostream>
using namespace std;

struct node
{
    node *next;
    string book;
};

class Hash
{
private:
    node **arr;
    int size;

    int hashFunction(string name)
    {
        return name[0] - 65;
    }

public:
    Hash(int l)
    {
        size = l;
        arr = new node *[l];
        for (int i = 0; i < size; i++)
            arr[i] = NULL;
    };

    void addBook(string name)
    {
        node *n = new node;
        n->book = name;
        n->next = NULL;
        int i = hashFunction(name);
        if (arr[i] == NULL)
        {
            arr[i] = n;
            return;
        }
        node *cur = arr[i];
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = n;
    }

    void search(string name)
    {
        int i = hashFunction(name);
        node *cur = arr[i];
        while (cur != NULL)
        {
            if (cur->book == name)
            {
                cout << "Book Found: " << cur->book << endl;
                return;
            }
            cur = cur->next;
        }
        cout << "Book not Found!" << endl;
    }
};

int main()
{
    Hash h1(26);

    h1.addBook("Treasure Ireland");
    h1.addBook("The Tower");
    h1.addBook("The Catcher in the Rye");
    h1.addBook("Tom Sawyer");
    h1.addBook("The Alchemist");
    h1.addBook("Pride and Prejudice");
    h1.addBook("The Odyssey");
    h1.addBook("War and Peace");
    h1.addBook("Brave New World");
    h1.addBook("Moby Dick");
    h1.addBook("The Shining");
    h1.addBook("Frankenstein");
    h1.addBook("Dracula");
    h1.addBook("The Picture of Dorian Gray");
    h1.addBook("The Brothers Karamazov");
    h1.addBook("Crime and Punishment");

    cout << "\nSearching for 'Treasure Ireland':" << endl;
    h1.search("Treasure Ireland");

    cout << "\nSearching for 'The Catcher in the Rye':" << endl;
    h1.search("The Catcher in the Rye");

    cout << "\nSearching for 'War and Peace':" << endl;
    h1.search("War and Peace");

    cout << "\nSearching for 'The Great Gatsby':" << endl;
    h1.search("The Great Gatsby");

    cout << "\nSearching for 'Banana Fish':" << endl;
    h1.search("Banana Fish");

    return 0;
}
