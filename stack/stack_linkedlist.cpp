#include <iostream>
#include "node.h"
using namespace std;

class StackLinkedList {
    private:
        int length; // number of elements in the stack
        Node* top;  // top of the stack; last element added

    public:
        StackLinkedList() : length(0), top(nullptr) {}  // Constructor

        // Return the length of the stack
        int getLength() {
            return length;
        }

        // Determine if the stack is empty
        bool isEmpty() {
            return length == 0 || top == nullptr;
        }

        // Add a new element on the top of the stack
        void push(int data) {
            Node* temp = new Node(data);
            temp->next = top;
            top = temp;
            length++;
        }

        // Remove and return the element at the top of the stack
        int pop() {
            if (isEmpty()) throw runtime_error("Stack is empty!");
            int result = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            length--;
            return result;
        }

        int peek() {
            if (isEmpty()) throw runtime_error("Stack is empty!");
            return top->data;
        }

        // Print the elements in the stack
        void display() {
            if (isEmpty()) return;
            Node* temp = top;
            cout << "null";
            while (temp != nullptr) {
                cout << " <-- " << temp->data;
                temp = temp->next;
            }
            cout << endl;
        }

        // Destructor
        ~StackLinkedList() {
            while (top != nullptr) {
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }
};

int main() {
    StackLinkedList stack;

    stack.push(5);
    stack.push(8);
    stack.push(3);
    stack.push(10);
    stack.push(2);

    cout << "Stack elements: ";
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    int popped = stack.pop();
    cout << "Popped element: " << popped << endl;

    cout << "Stack elements after pop: ";
    stack.display();

    return 0;
}
