
/*
 
 Min Stack:
 Always make the getting minimal element to be O(1)
 
 */

#include <iostream>
#include <stack>

using namespace std;

#define MAX_INT 2147483647

struct MyStack {
  stack<int> minStack;
  stack<int> stack;
  
  int minElement() {
    if (!minStack.empty()) {
      return minStack.top();
    }
    return MAX_INT;
  }
  
  int top() {
    return stack.top();
  }
  
  void push(int n) {
    int min = minElement();
    if (min >= n) {
      minStack.push(n);
    }
    
    stack.push(n);
  }
  
  void pop() {
    int min = minElement();
    int topNum = top();
    if (min == topNum) {
      minStack.pop();
    }
    
    stack.pop();
  }
};




int main()
{

  
  return 0;
}