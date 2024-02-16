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

    // Function to delete all nodes with the given key
    void delete_all_nodes_with_key(int value)
    {
        Node *current = head;
        while (current)
        {
            if (current->data == value)
            {
                if (current == head && current == tail)
                {
                    head = tail = nullptr;
                }
                else if (current == head)
                {
                    head = current->next;
                    head->prev = nullptr;
                }
                else if (current == tail)
                {
                    tail = current->prev;
                    tail->next = nullptr;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
            }
            current = current->next;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(5);
    list.insert(4);
    list.insert(5);
    list.insert(4);
    list.insert(4);

    cout << "Original list: ";
    list.print();

    int key = 5;
    list.delete_all_nodes_with_key(key);

    cout << "List after deleting nodes with key " << key << ": ";
    list.print();

    return 0;
}
