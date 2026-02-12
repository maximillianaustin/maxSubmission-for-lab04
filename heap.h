// heap.h
// Binary heap tree header file for CS 24 lab
// Diba Mirza

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap{

 public:
    Heap() {}  // default constructor
    Heap(std::vector<int>::iterator start, std::vector<int>::iterator end); // build a heap from a range using heapify
    void push(int value);     // insert value; //duplicates are allowed
    void pop(); // delete the min element
    int top();
    bool empty();

 private:
   bool compare(int parentVal, int childVal); // helper function to compare values based on heap type (min or max)
   void bubbleUp(int pos); // helper function to maintain heap property after insertion
   void bubbleDown(int pos); // helper function to maintain heap property after deletion
    std::vector<int> heapData; //store the binary heap tree as a dynamic array
};

#endif