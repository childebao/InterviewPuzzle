/*
 Given strings A, B, C
 Check if C could be created by A and B, without disording the characters in each of them.
 
 Sample Input:
 abcdfe dc adbccdfe
 aa bb bbaa
 abcd ef fabcde
 
 Sample Output:
 YES
 YES
 NO
 
 */

#include <iostream>
#include <string>

using namespace std;

string A, B, C;

int dp[1000][1000];

void solve()
{
  dp[0][0] = 1;
  
  for (int i = 1; i <= A.length(); i ++) {
    if (dp[i - 1][0] && C[i - 1] == A[i - 1]) {
      dp[i][0] = 1;
    }
  }
  
  for (int i = 1; i <= B.length(); i ++) {
    if (dp[0][i - 1] && C[i - 1] == B[i - 1]) {
      dp[0][i - 1] = 1;
    }
  }

  for (int i = 1; i <= A.length(); i ++) {
    for (int j = 1; j <= B.length(); j ++) {
      dp[i][j] = 0;
      
      if (dp[i][j - 1] && C[i + j - 1] == B[j - 1]) {
        dp[i][j] = 1;
        continue;
      }
      
      if (dp[i - 1][j] && C[i + j - 1] == A[i - 1]) {
        dp[i][j] = 1;
      }
    }
  }
  
  if (dp[A.length()][B.length()]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main()
{
  while (cin >> A >> B >> C) {
    solve();
  }
  
  return 0;
}