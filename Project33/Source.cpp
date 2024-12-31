#include <iostream>
using namespace std;

class MinHeap {
public:
    int* harr;       // Pointer to the heap array
    int capacity;    // Maximum size of the heap
    int heap_size;   // Current number of elements in the heap

    // Constructor
    MinHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    // Returns the index of the parent of a node
    int parent(int i) { return (i - 1) / 2; }

    // Returns the index of the left child of a node
    int left(int i) { return 2 * i + 1; }

    // Returns the index of the right child of a node
    int right(int i) { return 2 * i + 2; }

    // Inserts a new key into the heap
    void insertKey(int k) {
        if (heap_size == capacity) {
            cout << "Overflow: Could not insertKey\n";
            return;
        }

        // Insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        // Fix the MinHeap property
        while (i != 0 && harr[parent(i)] > harr[i]) {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    // Decreases the value of a key at index i to new_val
    void decreaseKey(int i, int new_val) {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i]) {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    // Extracts the minimum element (root) from the heap
    int extractMin() {
        if (heap_size <= 0)
            return 1e9; // Large constant to represent infinity
        if (heap_size == 1) {
            heap_size--;
            return harr[0];
        }

        // Store the minimum value and remove it
        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);

        return root;
    }

    // Deletes a key at index i
    void deleteKey(int i) {
        decreaseKey(i, -1e9); // Large negative value
        extractMin();
    }

    // Returns the minimum key (root)
    int getMin() { return harr[0]; }

    // Heapifies a subtree with the root at index i
    void MinHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && harr[l] < harr[smallest])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(&harr[i], &harr[smallest]);
            MinHeapify(smallest);
        }
    }

    // Utility function to swap two integers
    void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
};

int main() {
    MinHeap h(11); // Create a MinHeap with capacity 11
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    cout << "Extracted Min: " << h.extractMin() << endl; // Output: 2
    cout << "Minimum Value: " << h.getMin() << endl;    // Output: 3

    h.decreaseKey(2, 1);
    cout << "Minimum Value after decreaseKey: " << h.getMin() << endl; // Output: 1

    return 0;
}
