#include <iostream>
using namespace std;

// Print a given matrix in Spiral form

void spiralPrint(int** matrix, int rows, int cols) {
    int i, k = 0, l = 0, r = rows, c = cols;
    while (k < r && l < c) {
        for (i = l; i < c; i++) {   // left to right
            cout << matrix[k][i] << " ";
        }
        k++;
        for (i = k; i < r; i++) {   // top to bottom
            cout << matrix[i][c - 1] << " ";
        }
        c--;
        if (k < r) {
            for (i = c - 1; i >= l; i--) {  // right to left
                cout << matrix[r - 1][i] << " ";
            }
            r--;
        }
        if (l < c) {
            for (i = r - 1; i >= k; i--) {  // bottom to top
                cout << matrix[i][l] << " ";
            }
            l++;
        }
    }
    cout << endl;
}

int main() {
    int rows = 4;
    int cols = 4;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Fill the matrix (example values)
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = count++;
        }
    }

    // Print the matrix in spiral form
    cout << "Spiral Print: ";
    spiralPrint(matrix, rows, cols);

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
