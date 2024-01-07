#include <iostream>
using namespace std;
#include "print_array.cpp"

// Given an array of integers, return an array with even integers removed
// Input: arr = {3, 2, 4, 7, 10, 6, 5}
// Output: arr = {3, 7, 5}

// Note: In Java, arrays are reference types, which means when you return an array from a method,
// you're actually returning a reference to the array in memory. This allows you to work with the
// same array in the calling code, and any changes made to the array in the called method will
// reflect in the calling code.

// In C++, arrays are treated as value types when returned from a function. This means that when you
// return an array from a function in C++, you're returning a copy of the array, not a reference to
// the original array. This can lead to inefficient memory usage and unnecessary copying of data.
// To work around this limitation and to achieve more flexible memory management, C++ offers alternatives
// like using pointers or the vector container. Pointers can be used to return arrays from functions,
// but manual memory management is required. The vector container is recommended for dynamic arrays,
// as it provides automatic memory management and better safety compared to raw arrays.

class RemoveEvenIntegers {
    public:
        int* removeEven(int* arr, int size, int& newSize) {
            int oddCount = 0;
            for (int i = 0; i < size; ++i) {
                if (arr[i] % 2 != 0) {
                    oddCount++;
                }
            }
            
            int* result = new int[oddCount];
            int idx = 0;
            for (int i = 0; i < size; ++i) {
                if (arr[i] % 2 != 0) {
                    result[idx++] = arr[i];
                }
            }
            
            newSize = oddCount;
            return result;
        } 
};

int main() {
    RemoveEvenIntegers test;
    PrintArray p;

    int arr[] = {3, 2, 4, 7, 10, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    p.printArray(arr, size);

    int newSize = 0;
    int* result = test.removeEven(arr, size, newSize);
    p.printArray(result, newSize);

    delete[] result; // Don't forget to free the memory allocated for the result array

    return 0;
}