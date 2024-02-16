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

    void reverse()
    {
        if (!head || !head->next)
        {
            // If the list is empty or has only one node, no need to reverse
            return;
        }

        Node *current = head;
        Node *temp = nullptr;

        // Swap next and prev pointers for all nodes of the doubly linked list
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; // Move to the next node
        }

        // Update the head pointer to the last node, which is now the first node after reversal
        head = temp->prev;
    }
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
};
int main()
{
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Original List: ";
    list.print(); // Assume you have a print function to display the list

    list.reverse();

    cout << "Reversed List: ";
    list.print();
}