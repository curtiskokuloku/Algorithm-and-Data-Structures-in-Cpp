#include <iostream>
#include "node.h"
using namespace std;

class MergeList {
    public:
        // Given two sorted singly linked lists, merge them so that the resulting singly
        // linked list is also sorted.
        Node* merge(Node* head1, Node* head2) {
            if (head1 == nullptr) return head2;
            if (head2 == nullptr) return head1;

            Node* dummy = new Node(0);
            Node* tail = dummy;

            while (head1 != nullptr && head2 != nullptr) {
                if (head1->data <= head2->data) {
                    tail->next = head1;
                    head1 = head1->next;
                } else {
                    tail->next = head2;
                    head2 = head2->next;
                }
                tail = tail->next;
            }

            if (head1 == nullptr) {
                tail->next = head2;
            } else {
                tail->next = head1;
            }

            Node* result = dummy->next;
            delete dummy;

            return result;
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
    MergeList merger;

    // Create two sorted linked lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "List 1: ";
    merger.display(list1);

    cout << "List 2: ";
    merger.display(list2);

    Node* merged = merger.merge(list1, list2);

    cout << "Merged List: ";
    merger.display(merged);

    // Clean up memory
    merger.clear(merged);

    return 0;
}