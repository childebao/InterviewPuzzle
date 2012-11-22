/*
 Longest Common Subsequence
 
 Given two string, output the longest length and 'a' longest common subsequence. Using smaller space.
 */

#include <iostream>  
#include <algorithm> 
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;  

int main()  
{  
  string x, y, lcs = "";
  cin >> x >> y;
  if (x.length() > y.length()) swap(x, y);
  
  int dp[x.length() + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < y.length(); i ++) {
    for (int j = 0; j < x.length(); j ++) {
      if (y[i] == x[j]) dp[j + 1] = dp[j] + 1;
      else dp[j + 1] = max(dp[j + 1], dp[j]);
    }
  }
  
  int last = x.length();
  for (int i = x.length() - 1; i >= 0; i --) {
    if (dp[i] < dp[last]) {
      lcs = x[i] + lcs;
      last = i;
    }
  }
  
  cout << dp[x.length()] << ' ' << lcs << endl;
  
  return 0;  
}