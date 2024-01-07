#include <iostream>
using namespace std;
#include "print_array.cpp"

// In C++, it's often recommended to use dynamic memory allocation facilities provided by the
// C++ Standard Library, such as 'new' and 'delete', or better yet, to use modern C++ features
// like smart pointers (unique_ptr and shared_ptr) and containers (vector, array, etc.).

// 'malloc' and 'free' are not part of the C++ Standard Library itself; they are part of the C
// Standard Library. However, they can be used in C++ code as well since C++ has built-in
// compatibility with C. malloc is used for memory allocation and free is used for memory
// deallocation. Remember to include the <cstdlib> header for these functions. Also, note that
// malloc returns a pointer of type void*, so we need to cast it to the appropriate pointer type
// (int* in this case).

class ResizeArray {
public:
    int* resize(int* arr, int size, int capacity) {
        int* temp = new int[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        // *arr = *temp;
        // delete[] temp;   // no need to deallocate memory of old array since it was not allocated using 'new'
        return temp;
    }
};

int main() {
    ResizeArray test;
    PrintArray p;

    int arr[] = {5, 9, 3, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    p.printArray(arr, size);
    cout << "old size: " << size << endl;

    int newSize = size * 2;
    cout << "new size: " << newSize << endl;

    int* resizedArr = test.resize(arr, size, newSize);
    p.printArray(resizedArr, newSize);

    // delete[] resizedArr;     // no need to deallocate since it was not allocated using new

    return 0;
}
