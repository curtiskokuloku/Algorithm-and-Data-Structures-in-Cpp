#include <iostream>
#include "print_array.cpp"
using namespace std;

class BinarySearch {
    public:
        int binarySearch(int arr[], int low, int high, int key) {
            // Search for a 'key' in the array 'arr' starting at index 'low' and ending at index 'high'
            // If found, return the index of the key, -1 otherwise
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == key)
                    return mid;
                if (key < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return -1;
        }
};

int main() {
    int arr[] = {1, 10, 20, 47, 59, 65, 75, 88, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0, high = n-1;
    int key = 65;

    PrintArray p;
    p.printArray(arr, n);

    BinarySearch test;
    int result = test.binarySearch(arr, low, high, key);

    cout << key << " is found at index " << result << endl;
    
    return 0;
}