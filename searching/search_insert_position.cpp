#include <iostream>
using namespace std;

// Given a sorted array of distinct integers and a target value,
// return the index if the target is found. If not, return the index where it would be if it was
// inserted in order. The algorithm should run in O(log n) time.
// i.e., Input: arr = {1, 3, 5, 7}, target = 5
//       Output: 2
//       Input: arr = {1, 3, 5, 7}, target = 2
//       Output: 1
//       Input: arr = {1, 3, 5, 7}, target = 8
//       Output: 4
//       Input: arr = {1, 3, 5, 7}, target = 0
//       Output: 0

class SearchInsertPosition {
    public:
        int searchInsert(int arr[], int n, int target) { // O(log n)
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target) return mid;
                if (target < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return low;
        }

        void display(int arr[], int n, int target) {
            cout << "Input: {";
            for (int i = 0; i < n; i++) {
                cout << arr[i];
                if (i < n - 1) cout << ", ";
            }
            cout << "}, target: " << target << endl;
            cout << "Output: index " << searchInsert(arr, n, target) << endl;
        }
};

int main() {
    SearchInsertPosition test;

    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int target = 5;
    test.display(arr1, n1, target);

    target = 2;
    test.display(arr1, n1, target);

    target = 8;
    test.display(arr1, n1, target);

    target = 0;
    test.display(arr1, n1, target);

    int arr2[] = {1, 10, 20, 47, 59, 65, 75, 88, 99};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    target = 66;
    test.display(arr2, n2, target);

    return 0;
}





