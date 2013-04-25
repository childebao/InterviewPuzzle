/*
 Always find the Median number with O(1) time complexity.
 */

#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 212999999
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
  int size() { return heap.size() - 1; }
  
  void print() {
    for (int i = 1; i < heap.size(); i ++) {
      cout << heap[i] << ' ';
    }
    cout << endl;
  }
};

struct MaxHeap {
  vector<int> heap;
  
  MaxHeap() { heap.push_back(MAX_INT); }
  
  void switchUp(int position) {
    int p = position, f = p >> 1;
    int tmp = heap[p];
    while (f > 0) {
      if(tmp > heap[f]) heap[p] = heap[f]; else break;
      p = f; f = f >> 1;
    }
    heap[p] = tmp;
  }
  
  void switchDown(int position) {
    int p = position, c = p << 1;
    int tmp = heap[p];
    while (c < heap.size()) {
      if(c < heap.size() - 1 && heap[c + 1] > heap[c]) c++;
      if(heap[c] > tmp) heap[p] = heap[c]; else break;
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
  
  int max() {
    if (heap.size() == 1) { return heap[0]; }
    return heap[1];
  }
  
  bool isEmpty() { return heap.size() <= 1; }
  int size() { return heap.size() - 1; }
  
  void print() {
    for (int i = 1; i < heap.size(); i ++) {
      cout << heap[i] << ' ';
    }
    cout << endl;
  }
};

struct MyStack {
  MinHeap largest;
  MaxHeap smallest;
  
  void balanceHeaps() {
    while (largest.size() > smallest.size() + 1) {
      int n = largest.min();
      smallest.push(n);
      largest.pop();
    }
    
    while (largest.size() < smallest.size()) {
      int n = smallest.max();
      largest.push(n);
      smallest.pop();
    }
  }
  
  void push(int n) {
    if (n <= smallest.max()) {
      smallest.push(n);
    } else {
      largest.push(n);
    }
    balanceHeaps();
  }
  
  int median() {
    return largest.min();
  }
  
  void print() {
    cout << "Largest" << endl;
    largest.print();
    cout << "Smallest" << endl;
    smallest.print();
  }
};

int main()
{
  MyStack s;
  int n;
  while (cin >> n) {
    if (n > 0) {
      for (int i = 0; i < n; i ++) {
        int num = rand() % 1000 + 1;
        s.push(num);
        cout << num << ' ';
      }
      cout << endl;
      
      s.print();
    } else {
      cout << "Median : " << s.median() << endl;
    }
  }
}



