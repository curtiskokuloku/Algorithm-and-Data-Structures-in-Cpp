#include <iostream>
using namespace std;
#include "print_array.cpp"

class SelectionSort {
    public:
        void selectionSort(int arr[], int n) {
            // Last i elements are already in place, so no need to check them
            for (int i = 0; i < n-1; i++) {
                int min = i;
                for (int j = i+1; j < n; j++) {
                    if (arr[j] < arr[min]) min = j;
                }
                int temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
            }
        }
};

int main() {
    SelectionSort test;
    PrintArray p;

    int arr[] = {5, 1, 9, 2, 10};
    int size = sizeof(arr) / sizeof(int);
    p.printArray(arr, size);

    test.selectionSort(arr, size);

    cout << "sorted ";
    p.printArray(arr, size);
    
    return 0;
}