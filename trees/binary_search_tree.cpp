#include <iostream>
#include "tree_node.h" // Include the TreeNode header
using namespace std;

// Represents a Binary Search Tree (BST)
class BinarySearchTree {
    public:
        TreeNode* root;

        BinarySearchTree() : root(nullptr) {} // Constructor

        TreeNode* getRoot() {
            // Return the root node of the BST
            return this->root;
        }

        bool isEmpty(TreeNode* root) {
            // Determine if the BST is empty
            return root == nullptr;
        }

        int size(TreeNode* root) {
            // Count the number of nodes in the BST
            if (isEmpty(root)) return 0;
            return 1 + size(root->left) + size(root->right);
        }

        int height(TreeNode* root) {
            // Get the height of the BST
            if (isEmpty(root)) return 0;
            return max(height(root->left), height(root->right)) + 1;
        }

        void print(TreeNode* root) {
            // Display the BST in an in-order fashion: left subtree, root, right subtree
            if (isEmpty(root)) return;
            print(root->left);
            cout << root->data << " ";
            print(root->right);
        }

        void insert(int value) {
            root = insertHelper(root, value);
        }

        TreeNode* search(int key) {
            // Search if a given key is present in the BST
            return searchHelper(root, key);
        }

        bool doesExist(int key) {
            // Determine if a given key is present in the BST
            return search(key) != nullptr;
        }

        // Determine if the Binary Tree is a valid binary search tree.
        // Consider the interval {min, max}:
        // - If you go towards left subtree, min remains the same & max changes to parent value
        // - If you go towards right subtree, max remains the same & min changes to parent value
        bool isValid(TreeNode* root, int min, int max) {
            if (isEmpty(root)) return true;
            if (root->data <= min || root->data >= max) return false;
            bool left = isValid(root->left, min, root->data);
            if (left) {
                bool right = isValid(root->right, root->data, max);
                return right;
            }
            return false;
        }

    private:
        TreeNode* insertHelper(TreeNode* root, int value) {
            // Helper function to insert a value in a BST
            if (isEmpty(root)) {
                root = new TreeNode(value);
                return root;
            }
            if (value < root->data) {
                root->left = insertHelper(root->left, value);
            } else {
                root->right = insertHelper(root->right, value);
            }
            return root;
        }

        TreeNode* searchHelper(TreeNode* root, int key) {
            // Helper function to search if a given key is present in the BST
            if (isEmpty(root) || root->data == key) return root;
            if (key < root->data) {
                return searchHelper(root->left, key);
            } else {
                return searchHelper(root->right, key);
            }
        }
};

int main() {
    BinarySearchTree bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);
    bst.insert(7);

    cout << "In-order traversal: ";
    bst.print(bst.getRoot()); // 1 2 3 4 5 6 7
    cout << endl;

    int keyToSearch = 3;
    if (bst.doesExist(keyToSearch)) {
        cout << keyToSearch << " exists in the BST." << endl;
    } else {
        cout << keyToSearch << " does not exist in the BST." << endl;
    }

    keyToSearch = 8;
    if (bst.doesExist(keyToSearch)) {
        cout << keyToSearch << " exists in the BST." << endl;
    } else {
        cout << keyToSearch << " does not exist in the BST." << endl;
    }

    if (bst.isValid(bst.getRoot(), INT_MIN, INT_MAX)) {
        cout << "The given Binary Tree is a valid binary search tree." << endl;
    } else {
        cout << "The given Binary Tree is not a valid binary search tree." << endl;
    }

    return 0;
}