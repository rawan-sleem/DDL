#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Function to insert a node at the end of the linked list
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Function to print the linked list
    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to reverse the linked list
    void reverse()
    {
        Node *current = head;
        Node *prevNode = nullptr;
        while (current)
        {
            Node *nextNode = current->next;
            current->next = prevNode;
            current->prev = nextNode;
            prevNode = current;
            current = nextNode;
        }
        tail = head;
        head = prevNode;
    }

    // Function to check if the linked list is a palindrome
    bool is_palindrome()
    {
        if (size < 2) // A list with 0 or 1 node is a palindrome
            return true;

        Node *left = head;
        Node *right = tail;

        while (left != right && left->prev != right)
        {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main()
{
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(1);

    cout << "Original list: ";
    list.print();

    bool palindrome = list.is_palindrome();
    if (palindrome)
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is not a palindrome." << endl;

    return 0;
}
