#include <iostream>
using namespace std;
#include "print_array.cpp"

class QuickSort {
    public:
        int partition(int arr[], int low, int high) {
            int pivot = arr[high];
            int i = low, j = low;
            while (i <= high) {
                if (arr[i] <= pivot) { // sort the elements left of pivot
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    j++;
                }
                i++;
            }
            return j-1;
        }

        void quickSort(int arr[], int low, int high) {
            if (low < high) {
                int p = partition(arr, low, high);
                quickSort(arr, low, p-1);
                quickSort(arr, p+1, high);
            }
        }
};

int main() {
    QuickSort test;
    PrintArray p;

    int arr[] = {8, -3, 5, 2, 6, 9, -6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    p.printArray(arr, n);

    int low = 0, high = n - 1;
    test.quickSort(arr, low, high);

    cout << "After sorting: ";
    p.printArray(arr, n);

    return 0;
}