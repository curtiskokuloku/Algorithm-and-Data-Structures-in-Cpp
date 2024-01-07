#include <iostream>
using namespace std;

class MaxHeapPQ {
    public:
        int n;         // size of the heap
        int* heap;     // array representing the heap; first element is always 0 (empty)

        // Constructor
        MaxHeapPQ(int capacity) {
            heap = new int[capacity+1];
            n = 0;
            heapSize = capacity;
        }

        int findMax() {
            // Return the element with maximum value in the heap
            return heap[1];
        }

        // Return the number of elements in the heap
        int size() {
            return n;
        }

        // Insert element x into the Max Heap; call swim() to reheapify the heap
        void insert(int x) {
            if (n == heapSize - 1) resize(2 * heapSize);
            n++;
            heap[n] = x;
            swim(n);
        }

        // Delete the maximum element in a max heap; call sink() to reheapify the heap
        int deleteMax() {
            int max = heap[1];
            swap(1, n);
            n--;
            sink(1);
            heap[n+1] = 0;
            if (n > 0 && (n == (heapSize - 1) / 4)) resize(heapSize / 2);
            return max;
        }

        // Display the elements in the heap
        void display() {
            for (int i = 0; i <= n; i++) {
                if (get(i) == 0) {
                    cout << "null" << " ";
                } else {
                    cout << get(i) << " ";
                }
            }
            cout << endl;
        }

        // Destructor
        ~MaxHeapPQ() {
            delete[] heap;
        }

    private:
        int heapSize;   // length of the heap

        // Determine if the heap is empty
        bool isEmpty() {
            return n == 0;
        }

        // Return the element at index k
        int get(int k) {
            return heap[k];
        }

        // Return the index of the parent node at index k
        int parent(int k) {
            return heap[k/2];
        }

        // Return the index of left child of node at index k
        int left(int k) {
            return heap[2 * k];
        }

        // Return the index of right child of node at index k
        int right(int k) {
            return heap[2 * k + 1];
        }

        // Bottom-up reheapify technique to maintain the heap property when inserting into the heap
        // 'k' is the index of the element being inserted
        void swim(int k) {
            while (k > 1 && parent(k) < get(k)) {
                int temp = get(k);
                heap[k] = parent(k);
                heap[k/2] = temp;
                k = k/2;
            }
        }

        // Top-down reheapify (sink) operation to maintain the max heap property
        void sink(int k) {
            bool isHeapified = false;
            while (!isHeapified && 2 * k <= n) {
                int j = 2 * k;
                if (j < n && get(j) < get(j+1)) j++;
                if (get(k) >= get(j)) {
                    isHeapified = true;
                } else {
                    swap(k, j);
                    k = j;
                }
            }
        }

        // Resize the heap if necessary
        void resize(int newCapacity) {
            int* newHeap = new int[newCapacity];
            for (int i = 0; i <= n; i++) newHeap[i] = heap[i];
            delete[] heap;
            heap = newHeap;
            heapSize = newCapacity;
        }

        // Swap two elements in the heap
        void swap(int a, int b) {
            int temp = heap[a];
            heap[a] = heap[b];
            heap[b] = temp;
        }
};

int main() {
    MaxHeapPQ maxHeap(10); // Create a max heap with capacity 10
    
    maxHeap.insert(5);
    maxHeap.insert(8);
    maxHeap.insert(3);
    maxHeap.insert(10);
    maxHeap.insert(2);

    cout << "Max element: " << maxHeap.findMax() << endl;
    cout << "Size of heap: " << maxHeap.size() << endl;

    cout << "Original heap: ";
    maxHeap.display();

    int deletedMax = maxHeap.deleteMax();
    cout << "Deleted max element: " << deletedMax << endl;

    cout << "Heap after deletion: ";
    maxHeap.display();

    return 0;
}
