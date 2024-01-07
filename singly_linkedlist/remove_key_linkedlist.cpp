#include <iostream>
#include "node.h"
using namespace std;

class RemoveKey {
    public:
        // Method to delete the node with the given key from the list
        void removeKey(Node* head, int key) {
            if (head == nullptr) {
                cout << "Nothing to remove!" << endl;
                return;
            }
            Node* current = head;
            Node* temp = nullptr;
            if (current->data == key) { // head contains the key
                head = current->next;
                return;
            }
            while (current != nullptr && current->data != key) {
                temp = current;
                current = current->next;
            }
            if (current == nullptr) return;
            temp->next = current->next;
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

    RemoveKey remover;

    cout << "Original List: ";
    remover.display(head);

    // Remove a node with a specific key
    int keyToRemove = 20;
    remover.removeKey(head, keyToRemove);

    cout << "After Removing Key " << keyToRemove << ": ";
    remover.display(head);

    // Free the memory by deallocating linked list nodes
    remover.clear(head);

    return 0;
}
