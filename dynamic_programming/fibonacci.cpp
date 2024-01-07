#include <iostream>
using namespace std;

class DynamicFibonacci {
    public:
        // Recursive implementation of Fibonacci
        int fib(int n) {
            if (n == 0) return 0;
            if (n == 1) return 1;
            return fib(n - 1) + fib(n - 2);
        }

        // Bottom-up approach of fibonacci using iteration and a table to store smaller sub-problems
        // Generally considered the most efficient and scalable for larger values of n, because it
        // avoids the issues of excessive function calls and redundant calculations that can occur
        // in the recursive approach.
        int bottomUpFib(int n) {
            int* table = new int[n + 1];
            if (n == 0) {
                delete[] table;
                return 0;
            }
            table[0] = 0;
            table[1] = 1;
            for (int i = 2; i <= n; i++) {
                table[i] = table[i - 1] + table[i - 2];
            }
            int result = table[n];
            delete[] table;
            return result;
        }

        // Top-down approach of fibonacci that memorizes solutions of sub-problems and reuses it if necessary
        int topDownFib(int* memo, int n) {
            if (memo[n] == 0) {
                if (n <= 1) {
                    memo[n] = n;
                } else {
                    memo[n] = topDownFib(memo, n - 1) + topDownFib(memo, n - 2);
                }
            }
            return memo[n];
        }
};

int main() {
    DynamicFibonacci tester;
    int n = 10;

    cout << "Fibonacci Recursive: " << tester.fib(n) << endl;
    cout << "Fibonacci Bottom-Up: " << tester.bottomUpFib(n) << endl;

    int* memo = new int[n + 1]();
    cout << "Fibonacci Top-Down: " << tester.topDownFib(memo, n) << endl;

    delete[] memo;

    return 0;
}