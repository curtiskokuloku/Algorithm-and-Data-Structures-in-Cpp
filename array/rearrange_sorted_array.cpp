#include <iostream>
#include "print_array.cpp"
using namespace std;

// Given a sorted array of integers, rearrange the array in such a way that the first position
// will have the largest number, the second will have the smallest, the third will have the
// second-largest, and so on. Using O(1) extra space.
// i.e., Input: arr = {1, 2, 3, 4, 5, 6, 7}
//       Output: arr = {7, 1, 6, 2, 5, 3, 4}

class RearrangeSortedArray {
    public:
        void rearrange(int arr[], int n) {
            int i = 0;               // Pointer to the left of the array
            int j = n - 1;  // Pointer to the right of the array
            int max = arr[j] + 1;    // Maximum element in the array + 1

            for (int k = 0; k < n; k++) {
                // At even indices, store the maximum elements
                if (k % 2 == 0) {
                    arr[k] += (arr[j] % max) * max;
                    j--;
                } else {
                    arr[k] += (arr[i] % max) * max;
                    i++;
                }
            }

            // Divide all elements by 'max' to get the rearranged array
            for (i = 0; i < n; i++) {
                arr[i] = arr[i] / max;
            }
        }
};

int main() {
    cout << "Array 1:" << endl;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    PrintArray p;
    p.printArray(arr1, n1);

    RearrangeSortedArray test;
    test.rearrange(arr1, n1);
    p.printArray(arr1, n1);


    cout << "\nArray 2:" << endl;
    int arr2[] = {2, 3, 5, 6, 8, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    p.printArray(arr2, n2);

    test.rearrange(arr2, n2);
    p.printArray(arr2, n2);

    return 0;
}