#include <iostream>
#include "node.h"
using namespace std;

class ReverseList {
    public:
        // Method to reverse a singly Linked List
        Node* reverse(Node* head) {
            if (head == nullptr) return nullptr;
            Node* current = head;
            Node* next = nullptr;
            Node* previous = nullptr;
            while (current != nullptr) {
                next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            return previous;
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

    ReverseList reverser;

    cout << "Original List: ";
    reverser.display(head);

    // Reverse the linked list
    Node* reversedHead = reverser.reverse(head);

    cout << "Reversed List: ";
    reverser.display(reversedHead);

    // Free the memory by deallocating linked list nodes
    reverser.clear(reversedHead);

    return 0;
}
