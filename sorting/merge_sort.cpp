#include <iostream>
using namespace std;
#include "print_array.cpp"

class MergeSort {
    public:
        void mergeSort(int arr[], int temp[], int low, int high) {
            if (low < high) {
                int mid = low + (high - low) / 2;
                mergeSort(arr, temp, low, mid);     // divide left part
                mergeSort(arr, temp, mid + 1, high);  // divide right part
                merge(arr, temp, low, mid, high);        // sort left and right
            }
        }

        void merge(int arr[], int temp[], int low, int mid, int high) {
            for (int i = low; i <= high; i++) {
                temp[i] = arr[i];
            }
            int i = low, j = mid + 1, k = low;
            while (i <= mid && j <= high) {
                if (temp[i] <= temp[j]) {
                    arr[k++] = temp[i++];
                } else {
                    arr[k++] = temp[j++];
                }
            }
            while (i <= mid) {
                arr[k++] = temp[i++];
            }
        }
};

int main() {
    MergeSort test;
    PrintArray p;

    int arr[] = {9, 5, 2, 4, 3};
    int size = sizeof(arr) / sizeof(int);
    int low = 0;
    int high = size - 1;
    int temp[size];
    p.printArray(arr, size);

    test.mergeSort(arr, temp, low, high);

    cout << "sorted ";
    p.printArray(arr, size);
    
    return 0;
}