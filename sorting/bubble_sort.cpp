#include <iostream>
using namespace std;
#include "print_array.cpp"

class BubbleSort {
    public:
        void bubbleSort(int arr[], int n) {
            bool isSwapped;
            // Last i elements are already in place, so no need to check them
            for (int i = 0; i < n-1; i++) {
                isSwapped = false;
                for (int j = 0; j < n-i-1; j++) {
                    if (arr[j] > arr[j+1]) {
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                        isSwapped = true;
                    }
                }
                if (!isSwapped) break;
            }
        }
};

int main() {
    BubbleSort test;
    PrintArray p;

    int arr[] = {5, 1, 9, 2, 10};
    int size = sizeof(arr) / sizeof(int);
    p.printArray(arr, size);

    test.bubbleSort(arr, size);

    cout << "sorted ";
    p.printArray(arr, size);
    
    return 0;
}