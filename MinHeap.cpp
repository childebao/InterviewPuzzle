/*
 
 Min-Heap:
 A[parent(i)] <= A[i]
 
 */

#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct MinHeap {
  vector<int> heap;
  
  MinHeap() { heap.push_back(MAX_INT); }
  
  void switchUp(int position) {
    int p = position, f = p >> 1;
    int tmp = heap[p];
    while (f > 0) {
      if(tmp < heap[f]) heap[p] = heap[f]; else break;
      p = f; f = f >> 1;
    }
    heap[p] = tmp;
  }
  
  void switchDown(int position) {
    int p = position, c = p << 1;
    int tmp = heap[p];
    while (c < heap.size()) {
      if(c < heap.size() - 1 && heap[c + 1] < heap[c]) c++;
      if(heap[c] < tmp) heap[p] = heap[c]; else break;
      p = c; c = c << 1;
    }
    heap[p] = tmp;
  }

  void push(int n) {
    heap.push_back(n);
    switchUp(heap.size() - 1);
  }
  
  void pop() {
    if (heap.size() == 1) return;
    
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();
    switchDown(1);
  }
  
  int min() {
    if (heap.size() == 1) { return heap[0]; }
    return heap[1];
  }
  
  bool isEmpty() { return heap.size() <= 1; }

};

int main()
{
  MinHeap heap;
  heap.push(4);
  heap.push(11);
  heap.push(2);
  heap.push(4);
  heap.push(10);
  heap.push(8);
  
  while (!heap.isEmpty()) {
    cout << heap.min() << endl;
    heap.pop();
  }

  return 0;
}