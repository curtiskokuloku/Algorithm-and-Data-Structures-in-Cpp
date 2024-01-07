#include <iostream>
using namespace std;

void display(int arr[], int n) {
    // Print the elements in the array
    for (int i = 0; i < n; i++) {
       cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
}

int* merge(int arr1[], int arr2[], int n, int m) {
    // Merge two sorted arrays together to form a new sorted array of n+m integers
    int* result = new int[n + m];
    int i = 0, j = 0, k = 0;    // i traverse arr1, j traverse arr2, k traverse result
    while (i < n && j < m) {    // boundary conditions
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < n) { // left over from arr1
        result[k++] = arr1[i++];
    }
    while (j < m) { // left over from arr2
        result[k++] = arr2[j++];
    }
    return result;
}

int main() {
    int arr1[] = {2, 5, 7};
    int arr2[] = {3, 4, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "arr1: ";
    display(arr1, n);
    std::cout << "arr2: ";
    display(arr2, m);

    int* result = merge(arr1, arr2, n, m);

    std::cout << "result: ";
    display(result, n + m);

    delete[] result;  // Deallocate memory for the merged array

    return 0;
}