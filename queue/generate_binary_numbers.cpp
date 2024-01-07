#include <iostream>
#include <string>
#include <queue>
using namespace std;

// Generating a sequence of Binary Numbers from 1 to n using a Queue.
// i.e., Input: n = 3
//       Output: result = {"1", "10", "11"}
//       Input: n = 5
//       Output: result = {"1", "10", "11", "100", "101"}
// This can be treated as a binary tree where every left branch is an even number and every
// right branch is an odd number. For example, let 1 be the root of the tree. The left child of 1
// would be 2 (10 in binary) and the right child would be 3 (11 in binary).
// If we use a pre-order traversal, such that we first visit the root node first, followed by the
// left subtree, and then the right subtree, we will get: 1 --> 10 --> 11 --> ...

class GenerateBinaryNumbers {
    public:
        string* generateBinaryNumbers(int n) {
            if (n == 0) {
                string* result = new string[1];
                result[0] = "0";
                return result;
            }
            if (n == 1) {
                string* result = new string[1];
                result[0] = "1";
                return result;
            }
            string* result = new string[n];
            queue<string> q;
            q.push("1");                        // add 1 to the front of the queue
            for (int i = 0; i < n; i++) {
                result[i] = q.front();          // get the element from the front of the queue
                string n1 = result[i] + "0";    // left branch
                string n2 = result[i] + "1";    // right branch
                q.push(n1);
                q.push(n2);       // add next numbers to the rear of the queue
                q.pop();
            }
            return result;
        }

        void display(string* result, int n) {
        cout << "{";
        for (int i = 0; i < n; i++) {
            cout << result[i];
            if (i < n - 1) cout << ", ";
        }
        cout << "}" << endl;
    }
};

int main() {
    GenerateBinaryNumbers generator;

    int n = 5;  // result: {"1", "10", "11", "100", "101"}
    cout << "Input: n = " << n << endl;
    string* result = generator.generateBinaryNumbers(n);
    cout << "Output: result = ";
    generator.display(result, n);
    delete[] result;
    cout << endl;

    n = 1;  // result: {"1"}
    cout << "Input: n = " << n << endl;
    result = generator.generateBinaryNumbers(n);
    cout << "Output: result = ";
    generator.display(result, n);
    delete[] result;
    cout << endl;

    n = 0;  // result: {}
    cout << "Input: n = " << n << endl;
    result = generator.generateBinaryNumbers(n);
    cout << "Output: result = ";
    generator.display(result, 1);
    delete[] result;
    cout << endl;

    n = 100;
    cout << "Input: n = " << n << endl;
    result = generator.generateBinaryNumbers(n);
    cout << "Output: result = ";
    generator.display(result, n);
    delete[] result;
    return 0;
}