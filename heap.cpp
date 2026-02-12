// heap.cpp
// Maximillian Austin, 2/12/26

#include "heap.h"
#include <iostream>
using std::cout;
//Helper functions

  bool Heap::compare(int parentVal, int childVal) {
            return parentVal > childVal; // MinHeap: Parent should be smaller. If Parent > Child, SWAP.
       
    }
    
 void Heap::bubbleUp(int pos) {
        while (pos > 0 ){
            int parentpos = (pos-1)/2;
            if (compare(heapData[parentpos], heapData[pos])) {
                auto temp = heapData[parentpos];
                heapData[parentpos] = heapData[pos];
                heapData[pos] = temp;
                pos = parentpos;
            } else {
                break;
            }
        }
    }
    void Heap::bubbleDown(int pos) {
    int n = heapData.size();

    while (true) {
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        int smallest = pos; // Rename 'largest' to 'smallest'

        // 1. Is Left Child SMALLER than current parent?
        // compare(parent, child) returns true if parent > child
        if (left < n && compare(heapData[smallest], heapData[left])) {
            smallest = left;
        }

        // 2. Is Right Child SMALLER than the current smallest candidate?
        if (right < n && compare(heapData[smallest], heapData[right])) {
            smallest = right;
        }

        if (smallest != pos) {
            auto temp = heapData[smallest];
            heapData[smallest] = heapData[pos];
            heapData[pos] = temp;
            pos = smallest; 
        } else {
            break; 
        }
    }

  }
// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  for (auto it = start; it != end; ++it) {
      heapData.push_back(*it);
  }
  // Heapify the entire array
  for (int i = heapData.size() / 2 - 1; i >= 0; i--) {
      bubbleDown(i);
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  heapData.push_back(value);
  bubbleUp(heapData.size()-1);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (heapData.empty()) {
        return;
    }
    heapData[0] = heapData.back();
    heapData.pop_back();
    bubbleDown(0);
}

// Returns the minimum element in the heap
int Heap::top(){
  return heapData[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return heapData.empty();
}
    