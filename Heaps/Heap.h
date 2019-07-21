
#ifndef DATA_STRUCTURES_HEAP_H
#define DATA_STRUCTURES_HEAP_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap {
public:
    int size(){return A.size();}
    void insertElement(int key);
    void deleteElement();
    int getTopElement(){return A[0];}
    Heap(bool flag) {isMinHeap = flag;}
private:
    vector<int> A;
    bool isMinHeap; // we use the same class for implementing minheap and maxheap
    // so we want o boolean flag in order to know the right structure
    int PARENT(int i){return (i - 1) / 2;}
    int LEFT(int i){return (2 * i + 1);}
    int RIGHT(int i){return (2 * i + 2);}
    void heapify_down(int i);
    void heapify_up(int i);
    bool appropriate_comparison(int child, int parent); // We should make the correct comparisons.
    // We use the isMinHeap boolean flag in order to decide whether to use greater or less (Minheap/Maxheap case)

};


#endif //DATA_STRUCTURES_HEAP_H
