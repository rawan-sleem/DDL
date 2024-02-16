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

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

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
    }

    void merge_2sorted_lists(DoublyLinkedList &other)
    {
        Node *current1 = head;       // Pointer to traverse list1
        Node *current2 = other.head; // Pointer to traverse list2

        // Create a dummy node as the starting point for the merged list
        Node *dummy = new Node(0);
        Node *tail = dummy; // Pointer to track the tail of the merged list

        // Merge the two lists
        while (current1 && current2)
        {
            if (current1->data <= current2->data)
            {
                tail->next = current1;
                current1->prev = tail;
                current1 = current1->next;
            }
            else
            {
                tail->next = current2;
                current2->prev = tail;
                current2 = current2->next;
            }
            tail = tail->next;
        }

        // Append remaining nodes from list1 or list2
        if (current1)
        {
            tail->next = current1;
            current1->prev = tail;
        }
        else
        {
            tail->next = current2;
            current2->prev = tail;
        }

        // Update head to point to the first node of the merged list
        head = dummy->next;
        head->prev = nullptr;

        // Delete the dummy node
        delete dummy;

        // Update the other list to be empty
        other.head = nullptr;
    }
};



