#include <iostream>
#include "node.h"
using namespace std;

class FindMiddle {
    public:
        // Method to find the middle node of the list
        Node* findMiddle(Node* head) {
            if (head == nullptr) return nullptr;
            int n = getSize(head);
            int i = 1;
            Node* current = head;
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = (n / 2) + 1;
            }
            while (i < n && current != nullptr) {
                current = current->next;
                i++;
            }
            return current;
        }

        // Method to find the middle node using the fast and slow pointer approach
        Node* findMiddleOptimized(Node* head) {
            if (head == nullptr) return nullptr;
            Node* slowPtr = head;
            Node* fastPtr = head;
            while (fastPtr != nullptr && fastPtr->next != nullptr) {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next->next;
            }
            return slowPtr;
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

        // Method to count the number of nodes in the list
        int getSize(Node* head) {
            if (head == nullptr) return 0;
            int count = 0;
            Node* current = head;
            while (current != nullptr) {
                count++;
                current = current->next;
            }
            return count;
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    FindMiddle finder;

    // Find the middle using the size method
    Node* middle1 = finder.findMiddle(head);
    if (middle1 != nullptr) {
        cout << "Middle using the size method: " << middle1->data << endl;
    }

    // Find the middle using the optimized approach
    Node* middle2 = finder.findMiddleOptimized(head);
    if (middle2 != nullptr) {
        cout << "Middle using optimized approach: " << middle2->data << endl;
    }

    // Display the original list
    cout << "Original List: ";
    finder.display(head);

    // Free the memory by deallocating linked list nodes
    finder.clear(head);

    return 0;
}
