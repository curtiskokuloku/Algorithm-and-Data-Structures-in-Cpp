#include <iostream>
#include "print_array.cpp"
using namespace std;

class LinearSearch {
    public:
        int search(int arr[], int n, int x) {
            // Search for value 'x' in the array 'arr' in a linear manner
            // Return the index of the element if found, -1 otherwise
            for (int i = 0; i < n; i++) {
                if (arr[i] == x) return i;
            }
            return -1;
        }
};

int main() {
    PrintArray p;
    LinearSearch test;
    int arr[] = {5, 1, 9, 2, 10, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;

    p.printArray(arr, n);

    int result = test.search(arr, n, x);
    cout << x << " found at index " << result << endl;

    return 0;
}