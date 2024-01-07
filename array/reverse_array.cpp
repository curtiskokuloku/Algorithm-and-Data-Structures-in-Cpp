#include <iostream>
using namespace std;
#include "print_array.cpp"

// Given an array of integers, the task is to reverse the integers in the array
// Input: arr = {2, 11, 5, 10, 7, 8}
// Output: arr = {8, 7, 5, 10, 11, 2}

class ReverseArray {
    public:
        void reverseArray(int arr[], int start, int end) {
            // 'start' and 'end' are the range between which we want to reverse the array
            // We will swap two values as start pointer is smaller than the end pointer
            while (start < end) {
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;    // increase 'start' pointer
                end--;      // decrease 'end' pointer
            }
        }
};

int main() {
    ReverseArray test;
    PrintArray p;

    int arr[] = {2, 11, 5, 10, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    p.printArray(arr, size);

    test.reverseArray(arr, 0, size - 1);

    cout << "Reversed ";
    p.printArray(arr, size);

    return 0;
}