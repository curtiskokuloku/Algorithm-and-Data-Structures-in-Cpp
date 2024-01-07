#ifndef TREENODE_H  // checks if the macro TREENODE_H is not defined. If it's not defined,
                    // the subsequent code block is included. If it is defined (because the
                    // header has been included before), the code block is skipped.

#define TREENODE_H  // defines the macro TREENODE_H if not previously defined.

// Represents a node in a Binary Tree
struct TreeNode {
    int data;          // Generic type
    TreeNode* left;    // left child of the node
    TreeNode* right;   // right child of the node

    TreeNode(int inputData) : data(inputData), left(nullptr), right(nullptr) {
        // Constructor sets the initial values of data, left, and right.
    }
};

#endif