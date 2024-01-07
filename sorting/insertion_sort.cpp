#include <iostream>
using namespace std;
#include "print_array.cpp"

class InsertionSort {
    public:
        void insertionSort(int arr[], int n) {
            for (int i = 1; i < n; i++) {   // unsorted part
                int temp = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > temp) {   // sorted part
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = temp;
            }
        }
};

int main() {
    InsertionSort test;
    PrintArray p;

    int arr[] = {5, 1, 9, 2, 10};
    int size = sizeof(arr) / sizeof(int);
    p.printArray(arr, size);

    test.insertionSort(arr, size);

    cout << "sorted ";
    p.printArray(arr, size);
    return 0;
}