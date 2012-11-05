/*
 
 Sample Input:
 5
 10 1 50 20 5
 
 Sample Output: 
 1150
 
 http://poj.org/problem?id=1651
 
 Hint:
 dp[i][j] indicates the minimal sum that clears those numbers between i and j.
 
 It is easy to calculate the dp[i][i + 2], the sum is s[i] * s[i + 1] * s[i + 2];
 Then, dp[i][i + 3], could be A1 = s[i] * s[i + 1] * s[i + 3] + dp[i + 1][i + 3]
                           or A2 = dp[i][i + 2] + s[i] * s[i + 2] * s[i + 3]
       dp[i][i + 3] = min(A1, A2);
 
 Then, dp[i][i + L - 1] = min(A1, A2, ... Ak)  (k = L - 2)
                              Ak = dp[i][i + k] + s[i] * s[i + k] * s[i + L - 1];
 
 So the answer is dp[0][N - 1];
 
 */

#include <iostream>
#include <string>

using namespace std;

#define M 101
int N;
int s[M];
int dp[M][M];

int deal()
{  
  memset(dp, 0, sizeof(dp));
  
  for (int L = 3; L <= N; L ++) {
    for (int i = 0; i < N - L + 1; i ++) {
      int j = L + i - 1;
      dp[i][j] = 999999999;
      for (int k = i + 1; k < j; k ++) {
        int sum = dp[i][k] + dp[k][j] + s[i] * s[k] * s[j];
        dp[i][j] = min(dp[i][j], sum);
      }
    }
  }

  return dp[0][N - 1];
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i ++) {
    cin >> s[i];
  }
  
  cout << deal() << endl;
  
  return 0;
}