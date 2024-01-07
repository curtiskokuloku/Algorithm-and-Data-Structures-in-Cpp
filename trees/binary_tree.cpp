#include <iostream>
#include <queue>
#include <stack>
#include "tree_node.h" // Include the TreeNode header
#include <climits>
using namespace std;

class BinaryTree {
    public:
        TreeNode* root; // parent node of the tree

        BinaryTree() : root(nullptr) {} // Constructor

        TreeNode* getRoot() {
            // Return the root node of the tree
            return this->root;
        }

        void setRoot(TreeNode* newRoot) {
            // Set the root of the tree to a new node
            this->root = newRoot;
        }

        bool isEmpty(TreeNode* root) {
            // Check if the tree is empty
            return root == nullptr;
        }

        int size(TreeNode* root) {
            // Count the number of nodes in the tree
            if (isEmpty(root)) return 0;
            return 1 + size(root->left) + size(root->right);
        }

        int height(TreeNode* root) {
            // Get the height of the tree
            if (isEmpty(root)) return 0;
            return max(height(root->left), height(root->right)) + 1;
        }

        void preOrderR(TreeNode* root) {
            // Recursive pre-order traversal of a Binary Tree
            if (isEmpty(root)) return;
            cout << root->data << " ";
            preOrderR(root->left);
            preOrderR(root->right);
        }

        void inOrderR(TreeNode* root) {
            // Recursive in-order traversal of a Binary Tree
            if (isEmpty(root)) return;
            inOrderR(root->left);
            cout << root->data << " ";
            inOrderR(root->right);
        }

        void postOrderR(TreeNode* root) {
            // Recursive post-order traversal of a Binary Tree
            if (isEmpty(root)) return;
            postOrderR(root->left);
            postOrderR(root->right);
            cout << root->data << " ";
        }

        void preOrderI(TreeNode* root) {
            // Iterative pre-order traversal of a Binary Tree, using a stack
            if (isEmpty(root)) return;
            stack<TreeNode*> stack;
            stack.push(root);
            while (!stack.empty()) {
                TreeNode* temp = stack.top();
                stack.pop();
                cout << temp->data << " ";
                if (temp->right) stack.push(temp->right);
                if (temp->left) stack.push(temp->left);
            }
        }

        void inOrderI(TreeNode* root) {
            // Iterative in-order traversal of a Binary Tree, using a stack
            if (isEmpty(root)) return;
            stack<TreeNode*> stack;
            TreeNode* temp = root;
            while (!stack.empty() || temp != nullptr) {
                if (temp != nullptr) {
                    stack.push(temp);
                    temp = temp->left;
                } else {
                    temp = stack.top();
                    stack.pop();
                    cout << temp->data << " ";
                    temp = temp->right;
                }
            }
        }

        void postOrderI(TreeNode* root) {
            // Iterative post-order traversal of a Binary Tree
            if (isEmpty(root)) return;
            stack<TreeNode*> stack;
            TreeNode* current = root;
            TreeNode* prev = nullptr;
            while (current || !stack.empty()) {
                if (current) {
                    stack.push(current);
                    current = current->left;
                } else {
                    TreeNode* temp = stack.top();
                    if (temp->right == nullptr || temp->right == prev) {
                        cout << temp->data << " ";
                        prev = temp;
                        stack.pop();
                    } else {
                        current = temp->right;
                    }
                }
            }
        }

        void levelOrderI(TreeNode* root) {
            // Iterative level order traversal of a Binary tree
            if (isEmpty(root)) return;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                TreeNode* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }

        int findMax() {
            return findMaxHelper(root);
        }

        int* flatten(TreeNode* root) {
            int size = this->size(root);
            int* flattenedArray = new int[size];
            makeArray(root, flattenedArray, 0);
            return flattenedArray;
        }

        void displayArray(int arr[], int size) {
            cout << "[";
            for (int i = 0; i < size; i++) {
                cout << arr[i];
                if (i < size - 1) cout << ", ";
            }
            cout << "]" << endl;
        }

        // Member function for creating the example binary tree
        void createBinaryTree() {
            // Create a Binary Tree with 5 nodes and 1 being the root
            TreeNode* first = new TreeNode(1);
            TreeNode* second = new TreeNode(2);
            TreeNode* third = new TreeNode(3);
            TreeNode* fourth = new TreeNode(4);
            TreeNode* fifth = new TreeNode(5);
            TreeNode* sixth = new TreeNode(6);
            TreeNode* seventh = new TreeNode(7);

            setRoot(first);         // root --> first

            first->left = second;
            first->right = third;   // second <-- first --> third

            second->left = fourth;
            second->right = fifth;  // fourth <-- second --> fifth

            third->left = sixth;
            third->right = seventh; // sixth <-- third --> seventh
        }

        // Destructor to free memory
        // called automatically when an instance of the BinaryTree class goes out of scope or is explicitly deleted.
        // helper function to properly deallocate the memory used by the binary tree when it goes out of scope or
        // is explicitly deleted. This is important for preventing memory leaks.
        ~BinaryTree() {
            destroyTree(root);
        }

    private:
        // Helper function to recursively find the maximum value in a tree
        int findMaxHelper(TreeNode* root) {
            if (isEmpty(root)) return INT_MIN;
            int result = root->data;
            int left = findMaxHelper(root->left);
            int right = findMaxHelper(root->right);

            if (left > right) result = left;
            if (right > result) result = right;

            return result;
        }

        // Helper function to recursively convert a binary tree into an array
        int makeArray(TreeNode* root, int arr[], int i) {
            if (root == nullptr) return i;
            arr[i] = root->data;
            i = makeArray(root->left, arr, i+1);
            i = makeArray(root->right, arr, i);
            return i;
        }

        // Helper function to recursively delete the tree nodes
        void destroyTree(TreeNode* node) {
            if (node == nullptr) return;
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
};

int main() {
    BinaryTree tree;
    tree.createBinaryTree();

    cout << "Root of the tree is " << tree.getRoot()->data << endl;
    cout << "Size of the tree is " << tree.size(tree.getRoot()) << endl;
    cout << "Height of the tree is " << tree.height(tree.getRoot()) << endl;

    cout << "Pre-order: ";
    tree.preOrderR(tree.getRoot());    // 1 2 4 5 3 6 7
    cout << endl;

    cout << "In-order: ";
    tree.inOrderR(tree.getRoot());    // 4 2 5 1 6 3 7
    cout << endl;

    cout << "Post-order: ";
    tree.postOrderR(tree.getRoot());    // 4 5 2 6 7 3 1
    cout << endl;

    cout << "Level-order: ";
    tree.levelOrderI(tree.getRoot());    // 1 2 3 4 5 6 7
    cout << endl;

    cout << "Maximum value: " << tree.findMax() << endl;

    int* flattenedTree = tree.flatten(tree.getRoot());
    int size = tree.size(tree.getRoot()); // Calculate the size using the size function
    cout << "Flattened tree: ";
    tree.displayArray(flattenedTree, size);
    delete[] flattenedTree;  // Remember to free the allocated memory

    return 0;
}