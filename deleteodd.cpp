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

    // Function to delete all nodes at odd positions
    void delete_odd_positions()
    {
        if (size < 2) // No odd positions to delete
            return;

        Node *current = head;
        while (current)
        {
            Node *temp = current;
            current = current->next ? current->next->next : nullptr; // Move two positions forward
            if (temp->prev)
                temp->prev->next = temp->next; // Update previous node's next pointer
            if (temp->next)
                temp->next->prev = temp->prev; // Update next node's previous pointer
            delete temp;                       // Delete the node
            size--;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(10);

    cout << "Original list: ";
    list.print();

    list.delete_odd_positions();

    cout << "List after deleting nodes at odd positions: ";
    list.print();

    return 0;
}
