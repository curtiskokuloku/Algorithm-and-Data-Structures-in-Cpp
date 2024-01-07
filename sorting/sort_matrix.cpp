#include <iostream>
using namespace std;

class SortMatrix {
    public:
        void insertionSort(int** matrix, int n) {
            for (int i = 0; i < n; i++) {
                for (int j = 1; j < n; j++) {
                    int key = matrix[i][j];
                    int k = j - 1;
                    while (k >= 0 && matrix[i][k] > key) {
                        matrix[i][k + 1] = matrix[i][k];
                        k--;
                    }
                    matrix[i][k + 1] = key;
                }
            }
        }

        void transpose(int** matrix, int n) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }

        bool isSortedHelper(int* arr, int n) {
            for (int i = 1; i < n; i++) {
                if (arr[i] < arr[i - 1]) return false;
            }
            return true;
        }

        bool isSorted(int** matrix, int n) {
            for (int i = 0; i < n; i++) {
                if (!isSortedHelper(matrix[i], n)) return false;
            }
            for (int j = 0; j < n; j++) {
                int* column = new int[n];
                for (int i = 0; i < n; i++) column[i] = matrix[i][j];
                if (!isSortedHelper(column, n)) {
                    delete[] column;
                    return false;
                }
                delete[] column;
            }
            return true;
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

        void sort(int** matrix, int n) {
            insertionSort(matrix, n);   // sort row-wise
            transpose(matrix, n);       // transpose for column-wise
            insertionSort(matrix, n);   // sort-column wise
            transpose(matrix, n);       // transpose to original form
        }
};

int main() {
    SortMatrix test;

    int n = 4;
    int** unsortedMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        unsortedMatrix[i] = new int[n];
    }

    unsortedMatrix[0][0] = 90; unsortedMatrix[0][1] = 70; unsortedMatrix[0][2] = 35; unsortedMatrix[0][3] = 97;
    unsortedMatrix[1][0] = 15; unsortedMatrix[1][1] = 30; unsortedMatrix[1][2] = 10; unsortedMatrix[1][3] = 18;
    unsortedMatrix[2][0] = 20; unsortedMatrix[2][1] = 14; unsortedMatrix[2][2] = 16; unsortedMatrix[2][3] = 80;
    unsortedMatrix[3][0] = 11; unsortedMatrix[3][1] = 33; unsortedMatrix[3][2] = 39; unsortedMatrix[3][3] = 50;

    cout << "unsortedMatrix before: " << endl;
    test.display(unsortedMatrix, n);
    cout << "Is unsortedMatrix sorted: " << (test.isSorted(unsortedMatrix, n) ? "true" : "false") << endl;

    test.sort(unsortedMatrix, n);

    cout << "unsortedMatrix after: " << endl;
    test.display(unsortedMatrix, n);
    cout << "Is unsortedMatrix sorted: " << (test.isSorted(unsortedMatrix, n) ? "true" : "false") << endl;

    // Free the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] unsortedMatrix[i];
    }
    delete[] unsortedMatrix;

    return 0;
}