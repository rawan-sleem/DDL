#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Node* getHead() {
        return head;
    }

    void swapKth(int k) {
        Node* forward = head;
        Node* backward = head;

        // Traverse forward k-1 nodes
        for (int i = 1; i < k && forward; i++) {
            forward = forward->next;
        }

        // If forward becomes null, k is greater than the length of the list
        if (!forward) {
            cout << "Invalid k value!" << endl;
            return;
        }

        // Traverse backward until forward reaches the end
        while (forward->next) {
            forward = forward->next;
            backward = backward->next;
        }

        // Swap forward and backward nodes' data
        swap(forward->data, backward->data);
    }
};

int main() {
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    cout << "Original List: ";
    for (Node* cur = list.getHead(); cur; cur = cur->next) {
        cout << cur->data << " ";
    }
    cout << endl;

    int k = 2; // Swap 2nd node from both ends
    list.swapKth(k);

    cout << "After Swapping " << k << "th Node from Both Ends: ";
    for (Node* cur = list.getHead(); cur; cur = cur->next) {
        cout << cur->data << " ";
    }
    cout << endl;

    return 0;
}
