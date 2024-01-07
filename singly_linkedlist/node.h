#ifndef NODE_H
#define NODE_H

// Represents a node in a singly linked list
struct Node {
    int data;      // 'data' can be any generic type
    Node* next;    // Pointer to the next node in the list

    // Constructor
    Node(int inputData) : data(inputData), next(nullptr) {
        // Constructor sets the initial values of data and next.
    }
};

#endif
