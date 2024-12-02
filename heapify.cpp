#include <iostream>
using namespace std;

// Define the Heap structure
struct Heap {
    int* arr;  // Pointer to the array representing the heap
    int size;  // Current size of the heap
};

// Function to create a new heap
Heap createHeap(int* array, int n) {
    Heap heap;
    heap.arr = array;
    heap.size = n;
    return heap;
}

// Heapify function to maintain max-heap property
void heapify(Heap& heap, int i) {
    int largest = i;                        // Initialize largest as root
    int left = 2 * i + 1;                   // Left child
    int right = 2 * i + 2;                  // Right child
    int* arr = heap.arr;

    // If left child is larger than root
    if (left < heap.size && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < heap.size && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);         // Swap root and largest
        heapify(heap, largest);            // Recursively heapify the affected subtree
    }
}

// Function to build a max-heap
void buildMaxHeap(Heap& heap) {
    for (int i = heap.size / 2 - 1; i >= 0; i--) {
        heapify(heap, i);
    }
}

// Function to print the heap
void printHeap(const Heap& heap) {
    for (int i = 0; i < heap.size; i++) {
        cout << heap.arr[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create heap from array
    Heap heap = createHeap(arr, n);

    // Build max-heap
    buildMaxHeap(heap);

    // Print the max-heap
    cout << "Max-Heap array: ";
    printHeap(heap);

    return 0;
}
