#include <iostream>
using namespace std;

class PrintArray {
    public:
        void printArray(int arr[], int size) {
            cout << "array: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i];
                if (i < size - 1) cout << ", ";
            }
            cout << endl;
        }
};