// 'vector' is a standard template library (STL) container that represents a dynamic array.
// It provides dynamic sizing, efficient insertion and deletion of elements, and automatic memory
// management. The angle brackets <> are used to specify the type of elements that the vector will hold.

// you can use other data types within the angle brackets to create vectors of different types, such as
// double, char, string, and even custom classes.

#include <iostream>
using namespace std;

#include <vector>

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    int size = v.size();

    for (int i = 0; i < size; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}