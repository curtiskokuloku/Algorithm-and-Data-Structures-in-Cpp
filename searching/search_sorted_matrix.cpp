#include <iostream>
using namespace std;

// Given a row and colum wise (nxn) sorted matrix, write a program to search for a
// key in the given matrix. If the matrix isn't already sorted, it would be efficient
// to sort it first, and then search for the key.

class SearchSortedMatrix {
    public:
        void search(int** matrix, int n, int x) {
            // Search for key 'x' in 'matrix' of size 'n' by 'n'
            int i = 0;
            int j = n - 1;
            while (i < n && j >= 0) {
                if (matrix[i][j] == x) {
                    cout << x << " found at (" << i << "," << j << ")." << endl;
                    return;
                }
                if (matrix[i][j] > x) {
                    j--;
                } else {
                    i++;
                }
            }
            cout << x << " not found." << endl;
        }

        void display(int** matrix, int n) {
            for (int i = 0; i < n; i++) {
                cout << "|";
                for (int j = 0; j < n; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << "|" << endl;
            }
        }
};

int main() {
    SearchSortedMatrix test;
    int n = 4;
    int** sortedMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        sortedMatrix[i] = new int[n];
    }

    sortedMatrix[0][0] = 10; sortedMatrix[0][1] = 20; sortedMatrix[0][2] = 30; sortedMatrix[0][3] = 40;
    sortedMatrix[1][0] = 15; sortedMatrix[1][1] = 25; sortedMatrix[1][2] = 35; sortedMatrix[1][3] = 45;
    sortedMatrix[2][0] = 27; sortedMatrix[2][1] = 29; sortedMatrix[2][2] = 37; sortedMatrix[2][3] = 48;
    sortedMatrix[3][0] = 32; sortedMatrix[3][1] = 33; sortedMatrix[3][2] = 39; sortedMatrix[3][3] = 51;

    cout << "sortedMatrix: " << endl;
    test.display(sortedMatrix, n);

    int x = 32;
    test.search(sortedMatrix, n, x);

    x = 40;
    test.search(sortedMatrix, n, x);

    x = 100;
    test.search(sortedMatrix, n, x);

    // Don't forget to free the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] sortedMatrix[i];
    }
    delete[] sortedMatrix;

    return 0;
}