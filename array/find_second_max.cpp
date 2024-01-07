#include <iostream>
using namespace std;
#include "print_array.cpp"

// Given an array of integers, return the second maximum value in the array.
// Assume that the second maximum value exists.
// Input: arr = {12, 34, 2, 34, 33, 1}
// Output: 33

class FindSecondMax {
    public:
        int findSecondMax(int* arr, int n) {
            int max = arr[0];
            int secondMax = arr[0];
            for (int i = 1; i < n; i++) {
                if (arr[i] > max) {
                    secondMax = max;
                    max = arr[i];
                } else if (arr[i] > secondMax && arr[i] != max) {
                    secondMax = arr[i];
                }
            }
            return secondMax;
        }
};

int main() {
    PrintArray p;
    FindSecondMax test;

    int arr[] = {12, 34, 2, 34, 33, 1};
    int size = sizeof(arr) / sizeof(int);
    p.printArray(arr, size);
    
    int secondMax = test.findSecondMax(arr, size);
    cout << "Second Max: " << secondMax << endl;
    
    return 0;
}