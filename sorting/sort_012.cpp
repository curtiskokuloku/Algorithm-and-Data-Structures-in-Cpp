// Dutch National Flag Problem
// Given an array containing only 0's, 1's, and 2's, sort the array in linear time (O(n))
// and constant space (O(1)).
// i.e., Input:  arr = {2, 0, 2, 2, 0, 1, 1}
//       Output: arr = {0, 0, 1, 1, 2, 2, 2}

#include <iostream>
#include "print_array.cpp"
using namespace std;

class SortArrayOf012 {
    public:
        // Function to swap two integers
        void swap(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }

        // Function to sort the array containing only 0's, 1's, and 2's
        void sort012(int arr[], int n) {
            int k = n - 1;
            int i = 0, j = 0;
            while (i <= k) {
                if (arr[i] == 0) {
                    swap(arr[i], arr[j]);
                    i++;
                    j++;
                } else if (arr[i] == 1) {
                    i++;
                } else if (arr[i] == 2) {
                    swap(arr[i], arr[k]);
                    k--;
                }
            }
        }
};

int main() {
    SortArrayOf012 test;
    PrintArray p;

    int arr[] = {2, 0, 2, 2, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Input ";
    p.printArray(arr, n);

    cout << "Output ";
    test.sort012(arr, n);
    p.printArray(arr, n);

    return 0;
}