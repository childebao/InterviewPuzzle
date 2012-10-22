/*
 
 Write a function to generate all possible n pairs of balanced parentheses.
 
 Sample Input:
 3
 
 Sample Output:
 ((()))
 (()())
 (())()
 ()(())
 ()()()
 
 {}{}{} 
 {}{{}} 
 {{}}{} 
 {{}{}} 
 {{{}}} 
 
 ((()))
 (()())
 (())()
 ()(())
 ()()()
 
 Question 1: How to generate in iteration like this:
 {}{}{} 
 {}{{}} 
 {{}}{} 
 {{}{}} 
 {{{}}} 
 
 Question 2: What's the relationship between recursion and iteration?
 */


#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 100

void _printParenthesisRecursively(int pos, int n, int open, int close)
{
  static char str[MAX_SIZE];     
  
  if(close == n) 
  {
    printf("%s \n", str);
    return;
  }
  else
  {
    if(open > close) {
      str[pos] = '}';
      _printParenthesisRecursively(pos+1, n, open, close+1);
    }
    
    if(open < n) {
      str[pos] = '{';
      _printParenthesisRecursively(pos+1, n, open+1, close);
    }
  }
}

void printParenthesisRecursively(int n)
{
  if(n > 0)
    _printParenthesisRecursively(0, n, 0, 0);
  return;
}     


//Another sequence
void generateBrackets(int n) {
  string s(n * 2, ')');
  for (int i = 0; i < n; i ++) {
    s[i] = '(';
  }
  
  cout << s << endl;
  
  bool more;
  do {
    more = false;
    for (int i = s.length() - 1, open = 0, close = 0; i >= 0; --i) {
      if (s[i] == '(') open += 1;
      if (s[i] == ')') close += 1;
      if (s[i] == '(' && open < close) {
        s[i++] = ')';
        for (; open > 0; --open, ++i) s[i] = '(';
        for (--close; close > 0; --close, ++i) s[i] = ')';
        cout << s << endl;
        more = true;
        break;
      }
    }
  } while (more);
}

void generateBracketsRecursively(int open, int close, char s[], int count)
{
  if (open == 0 && close == 0) {
    cout << s << endl;
    return;
  }
  
  if (open > 0) {
    s[count] = '(';
    generateBracketsRecursively(open - 1, close, s, count + 1);
  }
  
  if (close > open) {
    s[count] = ')';
    generateBracketsRecursively(open, close - 1, s, count + 1);
  }
}

int main() {
  int n;
  while (cin >> n && n > 0) {
    generateBrackets(n);
    cout << endl;
    printParenthesisRecursively(n);
    cout << endl;
    char s[2 * n];
    generateBracketsRecursively(n, n, s, 0);
  }
  return 0;
}

