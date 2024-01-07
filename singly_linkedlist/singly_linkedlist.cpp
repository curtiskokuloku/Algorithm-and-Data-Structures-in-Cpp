#include <iostream>
#include "node.h"
using namespace std;

class SinglyLinkedList {
    public:
        Node* head;

        int numNodes;

        SinglyLinkedList() : head(nullptr), numNodes(0) {} // Constructor

        // Method to check whether the list is empty
        bool isEmpty() {
            return numNodes == 0 || head == nullptr;
        }

        // Method to count the nodes in the list
        int size() {
            if (isEmpty()) return 0;
            int count = 0;
            Node* current = head;
            while (current != nullptr) {
                count++;
                current = current->next;
            }
            numNodes = count;
            return count;
        }

        // Method to insert a node at the beginning of the list
        void insertAtFirst(int value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            numNodes++;
        }

        // Method to insert a node at the end of the list
        void insertAtLast(int value) {
            Node* newNode = new Node(value);
            if (isEmpty()) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
            numNodes++;
        }

        // Method to insert a node at a given position
        void insertAtPosition(int value, int position) {
            if (position > numNodes + 1 || position <= 0) {
                cout << "Position out of bounds." << endl;
                return;
            } else if (position == 1) {
                insertAtFirst(value);
            } else {
                Node* newNode = new Node(value);
                Node* previous = head;
                int count = 1;
                while (count < position - 1) {
                    previous = previous->next;
                    count++;
                }
                newNode->next = previous->next;
                previous->next = newNode;
                numNodes++;
            }
        }

        // Method to delete the first node in the list and return that node
        Node* deleteFirst() {
            if (isEmpty()) return nullptr;
            Node* temp = head;
            head = head->next;
            temp->next = nullptr;
            numNodes--;
            return temp;
        }

        // Method to delete the last node in the list and return that node
        Node* deleteLast() {
            if (isEmpty() || head->next == nullptr) {
                return deleteFirst();
            }
            Node* current = head;
            Node* previous = nullptr;
            while (current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            previous->next = nullptr;
            numNodes--;
            return current;
        }

        // Method to delete a node from the list at a given position and return that node
        Node* deleteAtPosition(int position) {
            if (position == 1) {
                return deleteFirst();
            } else if (position > 1 && position < numNodes) {
                Node* previous = head;
                int count = 1;
                while (count < position - 1) {
                    previous = previous->next;
                    count++;
                }
                Node* current = previous->next;
                previous->next = current->next;
                current->next = nullptr;
                numNodes--;
                return current;
            }
            return nullptr;
        }

        // Method to get the value of the node at the given position; -1 if not found
        int getValue(int position) {
            if (position < 0 || position > numNodes || isEmpty()) return -1;
            Node* current = head;
            int index = 1;
            while (index <= position - 1) {
                current = current->next;
                index++;
            }
            if (current == nullptr) return -1;
            return current->data;
        }

        // Method to get the position of the node with the given key; -1 if not found
        int getPosition(int key) {
            if (isEmpty()) return -1;
            int position = 1;
            Node* current = head;
            while (current != nullptr) {
                if (key == current->data) return position;
                position++;
                current = current->next;
            }
            return -1;
        }
        
        // Method to display the list
        void display() {
            if (isEmpty()) return;
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " --> ";
                current = current->next;
            }
            cout << "null" << endl;
        }

        // Method to free the memory by deallocating linked list nodes
        void clear() {
            if (isEmpty()) return;
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};

int main() {
    SinglyLinkedList myList;

    myList.insertAtLast(10);
    myList.insertAtLast(20);
    myList.insertAtLast(30);

    cout << "Initial list:" << endl;
    myList.display();
    cout << "Size of the list: " << myList.size() << endl;

    myList.insertAtFirst(5);
    myList.insertAtPosition(25, 3);
    myList.display();
    cout << "Size of the list: " << myList.size() << endl;

    int deletedValue = myList.deleteFirst()->data;
    cout << "Deleted first node with value: " << deletedValue << endl;
    myList.display();
    cout << "Size of the list: " << myList.size() << endl;

    deletedValue = myList.deleteAtPosition(2)->data;
    cout << "Deleted node at position 2 with value: " << deletedValue << endl;
    myList.display();
    cout << "Size of the list: " << myList.size() << endl;

    myList.clear();
    cout << "List after clearing: ";
    myList.display();
    cout << "Size of the list: " << myList.size() << endl;

    return 0;
}
