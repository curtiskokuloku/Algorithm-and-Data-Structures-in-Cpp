#include <iostream>
#include "node.h"
using namespace std;

class RemoveDuplicates {
    public:
        // Method to remove duplicate nodes from the list; having the list sorted can improve performance
        void removeDuplicates(Node* head) {
            if (head == nullptr) return;
            Node* current = head;
            while (current != nullptr && current->next != nullptr) {
                if (equals(current, current->next)) {
                    current->next = current->next->next;
                } else {
                    current = current->next;
                }
            }
        }

        // Helper method to check if two nodes have the same value
        bool equals(Node* n1, Node* n2) {
            return (n1->data == n2->data);
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
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);

    RemoveDuplicates remover;

    cout << "Original List: ";
    remover.display(head);

    // Remove duplicate nodes
    remover.removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    remover.display(head);

    // Free the memory by deallocating linked list nodes
    remover.clear(head);

    return 0;
}
