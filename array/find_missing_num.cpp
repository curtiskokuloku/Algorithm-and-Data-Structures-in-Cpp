#include <iostream>
#include "print_array.cpp"
using namespace std;

// Given an array of n-1 distinct numbers in the range of 1 to n.
// Find the missing number in the array.
// Input: arr = {2, 4, 1, 8, 6, 3, 7}, n = 8
// Output: 5
// Explanation: The missing number from range 1 to 8 is 5.

class FindMissingNum {
    public:
        int findMissingNumber(int arr[], int n) {
            // Mathematical Approach: sum from 1 to n = n(n+1)/n
            int sum = n * (n + 1) / 2;
            cout << "Current sum: " << sum << endl;
            for (int i = 0; i < n - 1; i++) {
                sum = sum - arr[i];
                cout << "Current sum: " << sum << endl;
            }
            return sum;
        }
};

int main() {
    PrintArray p;
    FindMissingNum test;
    int arr[] = {2, 4, 1, 8, 6, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    p.printArray(arr, size);
    int missingNum = test.findMissingNumber(arr, size+1);
    cout << "The missing number is: " <<  missingNum << endl;
    return 0;
}