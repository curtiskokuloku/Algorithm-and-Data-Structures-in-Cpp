#include <iostream>
#include "print_array.cpp"
using namespace std;

class ArrayDemo {
    public:
        void arrayDemo() {
            PrintArray p;
            cout << "First Array: ";
            int myArray[5] = {0}; // Default-initialized to 0
            // p.printArray(myArray); // Commented out because the array is empty at this point
            myArray[0] = 5;
            myArray[1] = 15;
            myArray[2] = 25;
            myArray[3] = 35;
            myArray[4] = 45;
            // myArray[5] = 55; // This will produce an error because the array size is 5
            int size = sizeof(myArray) / sizeof(myArray[0]);
            p.printArray(myArray, 5);

            cout << "Length of array: " << size << endl;
            cout << "Last element: " << myArray[size-1] << endl;

            cout << "Second Array: ";
            int myArray2[] = {5, 15, 25, 35, 45, 55, 100}; // Size is automatically determined
            size = sizeof(myArray2) / sizeof(myArray2[0]);
            p.printArray(myArray2, size);
        }
};

// 'vector' is a standard template library (STL) container that represents a dynamic array.
// It provides dynamic sizing, efficient insertion and deletion of elements, and automatic memory
// management. The angle brackets <> are used to specify the type of elements that the vector will hold.

// you can use other data types within the angle brackets to create vectors of different types, such as
// double, char, string, and even custom classes.

int main() {
    ArrayDemo test;
    test.arrayDemo();
    return 0;
}
