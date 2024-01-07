#include <iostream>
#include "print_array.cpp"
using namespace std;

// Given an array of integers, the task is to find the minimum value in the array
// Input: arr = {5, 9, 3, 15, 1, 2}
// Output: 1

class FindMin {
    public:
        int findMin(int arr[], int n) {
            if (arr == nullptr || n == 0) { // Edge case
                throw invalid_argument("Invalid input");
            }

            int min = arr[0]; // Assign 'min' to be the first element
            for (int i = 1; i < n; i++) {
                if (arr[i] < min) { // Compare next element with 'min' value
                    min = arr[i]; // Reassign 'min' to be the current element
                }
            }
            return min;
        }
};

int main() {
    int arr[] = {5, 9, 3, 15, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    PrintArray p;
    p.printArray(arr, n);

    FindMin test;

    try {
        int minValue = test.findMin(arr, n);
        cout << "Min Value: " << minValue << endl;
    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
        // 'cerr' is an output stream object that is provided by the C++ Standard Library for writing
        // error messages to the standard error stream.
    }

    return 0;
}