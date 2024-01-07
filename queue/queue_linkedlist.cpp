#include <iostream>
#include "node.h"
using namespace std;

class QueueLinkedList {
    private:
        Node* front;    // front of the queue; first element added and thus, first to be deleted
        Node* rear;     // end of the queue; last element added and thus, last to be deleted
        int length;     // number of elements in the queue

    public:
        QueueLinkedList() : front(nullptr), rear(nullptr), length(0) {} // Constructor

        // Return the length of the queue
        int size() {
            return length;
        }

        // Return the front of the queue
        Node* getFront() {
            return front;
        }

        // Return the rear of the queue
        Node* getRear() {
            return rear;
        }

        // Return the data of the given node in the queue
        int getData(Node* node) {
            if (isEmpty() || node == nullptr) throw invalid_argument("Queue is empty or node is null!");
            return node->data;
        }

        // Determine whether the queue is empty
        bool isEmpty() {
            return length == 0 || front == nullptr;
        }

        // Insert a data at the back of the queue
        void enqueue(int data) {
            Node* temp = new Node(data);
            if (isEmpty()) {
                front = temp;
            } else {
                rear->next = temp;
            }
            rear = temp;
            length++;
        }

        // Remove an element from the front of the queue, and return that element
        int dequeue() {
            if (isEmpty()) throw runtime_error("Queue is empty");
            int result = front->data;
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) rear = nullptr;
            length--;
            return result;
        }

        // Display the structure of the queue
        void display() {
            if (isEmpty()) return;
            Node* current = front;
            while (current != nullptr) {
                cout << current->data << " --> ";
                current = current->next;
            }
            cout << "null" << endl;
        }

        // Destructor
        ~QueueLinkedList() {
            while (!isEmpty()) {
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }
};

int main() {
    QueueLinkedList queue;

    queue.enqueue(5);
    queue.enqueue(8);
    queue.enqueue(3);
    queue.enqueue(10);
    queue.enqueue(2);

    cout << "Front: " << queue.getData(queue.getFront()) << endl;
    cout << "Rear: " << queue.getData(queue.getRear()) << endl;

    cout << "Queue elements: ";
    queue.display();

    int dequeued = queue.dequeue();
    cout << "Dequeued element: " << dequeued << endl;

    cout << "Queue elements after dequeue: ";
    queue.display();

    return 0;
}