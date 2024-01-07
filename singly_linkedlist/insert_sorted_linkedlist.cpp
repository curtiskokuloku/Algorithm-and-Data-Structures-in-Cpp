#include <iostream>
#include "node.h"
using namespace std;

class InsertSortedLinkedList {
    public:
        // Method to insert a new node that mains the ordering of the list if list is sorted
        void insertInSortedOrder(Node* head, int value) {
            if (head == nullptr) return;
            Node* newNode = new Node(value);
            Node* current = head;
            Node* temp = nullptr;
            while (current != nullptr && current->data < newNode->data) {
                temp = current;
                current = current->next;
            }
            newNode->next = current;
            temp->next = newNode;
        }

        // Method to display the list
        void display(Node* head) {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " --> ";
                current = current->next;
            }
            cout << "null" << endl;
        }

        // Method to free the memory by deallocating linked list nodes
        void clear(Node* head) {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    InsertSortedLinkedList sorter;

    cout << "Original List: ";
    sorter.display(head);

    // Insert elements in sorted order
    sorter.insertInSortedOrder(head, 25);
    sorter.insertInSortedOrder(head, 15);

    cout << "After Insertion: ";
    sorter.display(head);

    // Free the memory by deallocating linked list nodes
    sorter.clear(head);

    return 0;
}
