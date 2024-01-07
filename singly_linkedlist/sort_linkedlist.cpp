#include <iostream>
#include "node.h"
using namespace std;

class SortList {
    public:
        void sort(Node* head) {
            if (head == nullptr || head->next == nullptr) return;
            Node* previous = head;
            while (previous->next != nullptr) {
                Node* min = previous;
                Node* current = previous->next;
                while (current != nullptr) {
                    if (current->data < min->data) {
                        min = current;
                    }
                    current = current->next;
                }
                if (min != previous) {
                    swap(previous, min);
                }
                previous = previous->next;
            }
        }

        // Helper method to swap the values of two nodes
        void swap(Node* n1, Node* n2) {
            int temp = n1->data;
            n1->data = n2->data;
            n2->data = temp;
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
    // Creating a sample linked list
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);

    // Display the original list
    SortList sorter;
    cout << "Original List: ";
    sorter.display(head);

    // Sorting the list using selection sort
    sorter.sort(head);

    // Display the sorted list
    cout << "Sorted List: ";
    sorter.display(head);

    sorter.clear(head);

    return 0;
}
