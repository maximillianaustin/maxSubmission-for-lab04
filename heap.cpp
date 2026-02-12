// heap.cpp
// Diba Mirza

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
                int largest = pos; // Assume parent is largest for now
    
                // 1. Is Left Child bigger than current largest?
                
                // first condition checks ("ok is this an actual child)") ((must be asked first))
                // second condition asks ('ok should this be prioritized?   ')
                if (left < n && compare(heapData[largest] , heapData[left])) {
                    largest = left;
                }
                    ///asks it again if.  this also checks if the right node is bigger)
                // 2. Is Right Child bigger than current largest?
                // (Note: This handles the case where Right > Left implicitly)
                if (right < n && compare(heapData[largest] , heapData[right])) {
                    largest = right;
                }
    
                // 3. Did we find a child that is bigger than the parent?
                if (largest != pos) {
                  auto temp = heapData[largest];
                  heapData[largest] = heapData[pos];
                  heapData[pos] = temp;
                    pos = largest; // Update position to continue sinking down
                } else {
                    // If parent is bigger than both children, we are done!
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
    