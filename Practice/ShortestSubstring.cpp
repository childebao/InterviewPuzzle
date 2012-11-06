/*
  Find the shortest subString of sourceString which contains all the characters in the patternString.
 
 Sample Input:
 abghxfip gxf 
 
 Sample Output:
 ghxf
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

string source, pattern;

void reset(bool hash[])
{
  for (int i = 0; i < 256; i ++) {
    hash[i] = false;
  }
}

int flagHash(string s, bool hash[])
{
  reset(hash);
  int c = 0;
  for (int i = 0; i < pattern.length(); i ++) {
    if (!hash[s[i]]) { hash[s[i]] = true; c ++;};
  }
  return c;
}

void deal()
{
  bool hsPattern[256];
  bool hsFound[256];
  int patternCount = flagHash(pattern, hsPattern);
  
  int head = 0, tail = 0;
  int ans = source.length() + 10, posi = -1;
  
  for (int i = 0; i < source.length(); i ++) {
    if (hsPattern[source[i]]) {
      reset(hsFound);
      
      int count = 1;
      hsFound[source[i]] = true;
      
      head = i; tail = i;
      while (count < patternCount && tail < source.length()) {
        tail ++;
        if (hsPattern[source[tail]] && !hsFound[source[tail]]) {
          count ++;
        }
      }
      
      if (count == patternCount && ans > tail - head + 1) {
        ans = tail - head + 1;
        posi = head;
      }
    }
  }
  
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
