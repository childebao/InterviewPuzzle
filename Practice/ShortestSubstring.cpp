/*
  Find the shortest subString of sourceString which contains all the characters in the patternString.
 
 Sample Input:
 abghxfip gxf 
 
 Sample Output:
 ghxf
 
 
 Hint:
 1. Move tail forward to find the shortest substring from head to tail which meets the conditions.
 2. Then move head forward to find the longgest substring from head to tail which contains (patternCount - 1) characters.
    Then go to step 1.
 
 Time Complexity:
 O(source.length()). becuase every char in source string would at most be checked twice.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

string source, pattern;

void reset(int hash[])
{
  for (int i = 0; i < 256; i ++) {
    hash[i] = 0;
  }
}

int flagString(string s, int hash[])
{
  reset(hash);
  int c = 0;
  for (int i = 0; i < pattern.length(); i ++) {
    if (!hash[s[i]]) { hash[s[i]] = 1; c ++;};
  }
  return c;
}

void deal()
{
  int isInPattern[256], charCnt[256];
  int patternCount = flagString(pattern, isInPattern);
  reset(charCnt);
  
  int head = 0, tail = -1, count = 0, N = source.length();
  int ans = source.length(), posi = 0;
  
  do {
    while (count < patternCount && tail < N) {
      tail ++;
      
      if (isInPattern[source[tail]]) {
        if (!charCnt[source[tail]]) count ++;
        charCnt[source[tail]] ++;
      }
    }
    
    while (count == patternCount && head < N) {
      if (isInPattern[source[head]]) {
        charCnt[source[head]] --;
        
        if (charCnt[source[head]] == 0) {
          count --;
          
          if (ans > tail - head + 1) {
            ans = tail - head + 1;
            posi = head;
          }
        }
      }
      head ++;
    }
    
    head ++;
  } while (head <= tail && count < patternCount);
  
  for (int i = posi; i < posi + ans; i ++) {
    cout << source[i];
  }
  
  cout << endl;
}

int main()
{
  while (cin >> source >> pattern) {
    deal();
  }
  
  return 0;
}
