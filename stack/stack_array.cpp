#include <iostream>
using namespace std;

class StackArray {
    private:
        int top;        // Top of the stack; Last element added
        int* arr;       // Array of elements added to the stack
        int capacity;   // Capacity of the stack

    public:
        // Constructor
        StackArray(int stackCapacity) : top(-1), capacity(stackCapacity) {
            arr = new int[capacity];
        }
        
        // Determine if the stack is empty
        bool isEmpty() {
            return top <= -1;
        }

        // Determine if the stack is full
        bool isFull() {
            return size() == capacity;
        }

        // Return the size/length of the stack
        int size() {
            return top + 1;
        }

        // Add a new element on the top of the stack
        void push(int data) {
            if (isFull()) throw runtime_error("Stack overflow!");
            top++;
            arr[top] = data;
        }

        // Remove and return the element at the top of the stack
        int pop() {
            if (isEmpty()) throw runtime_error("Stack underflow!");
            int result = arr[top];
            top--;
            return result;
        }

        // Return the element at the top of the stack
        int peek() {
            if (isEmpty()) throw runtime_error("Stack underflow!");
            return arr[top];
        }

        // Print the elements in the stack
        void display() {
            int i = top - size() + 1;
            while (i <= top) {
                cout << arr[i++];
                if (i < top + 1) cout << " | ";
            }
            cout << endl;
        }

        // Destructor
        ~StackArray() {
            delete[] arr;
        }
};

int main() {
    StackArray stack(5);

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