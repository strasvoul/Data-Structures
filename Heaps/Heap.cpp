#include "Heap.h"

void Heap::heapify_up(int i) {
    // check if node at index i and its parent violates
    // the heap property
    if (i && appropriate_comparison( A[i],A[PARENT(i)])) {
        // swap the two if heap property is violated
        swap(A[i], A[PARENT(i)]);

        // call Heapify-up on the parent
        heapify_up(PARENT(i));
    }
}

void Heap::heapify_down(int i) {
    // get left and right child of node at index i
    int left = LEFT(i);
    int right = RIGHT(i);

    int largest = i;

    // compare A[i] with its left and right child and find largest value
    if (left < size() && appropriate_comparison(A[left] , A[i]))
        largest = left;

    if (right < size() && appropriate_comparison(A[right] , A[largest]))
        largest = right;

    // swap with child having greater value and
    // call heapify-down on the child
    if (largest != i) {
        swap(A[i], A[largest]);
        heapify_down(largest);
    }
}

bool Heap::appropriate_comparison(int child, int parent) {
    if (isMinHeap && parent > child) {
        return true;
    } else if (!isMinHeap && parent < child) {
        return true;
    }
    return false;
}

void Heap::insertElement(int key) {
    A.push_back(key);
    int index = size() - 1;
    heapify_up(index);
}

void Heap::deleteElement() {
    if (size() == 0)
        return;
    A[0] = A.back();
    A.pop_back();
    heapify_down(0);
}