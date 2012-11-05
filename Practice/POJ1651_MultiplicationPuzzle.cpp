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
 
 Then, dp[i][i + L - 1] = min(A1, A2, ... Ak)  (1 <= k <= L - 2)
                              Ak = dp[i][i + k] + dp[i + k][i + L - 1] + s[i] * s[i + k] * s[i + L - 1];
 
 So the answer is dp[0][N - 1];
 
 g[i][j] saves the index of the last number selected between i and j.
 
 Function print(s,t,m), print the numbers in order of who is selected first.
 
 */

#include <iostream>
#include <string>

using namespace std;

#define M 101
int N;
int s[M];
int dp[M][M];
int g[M][M];

void print(int s, int t, int m)
{
  if (m == 0) return;

  print(s, m, g[s][m]);
  print(m, t, g[m][t]);
  
  cout << m << ' ';
}

int deal()
{
  for (int L = 3; L <= N; L ++) {
    for (int i = 0; i < N - L + 1; i ++) {
      int j = i + L - 1;
      dp[i][j] = 999999999;
      
      for (int k = 1; k < L - 1; k ++) {
        int sum = dp[i][i + k] + dp[i + k][j] + s[i] * s[i + k] * s[j];
        if (dp[i][j] > sum) {
          dp[i][j] = sum;
          g[i][j] = i + k;
        }
      }
    }
  }

  print(0, N - 1, g[0][N - 1]);
  cout << endl;
  
  return dp[0][N - 1];
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i ++) {
    scanf("%d", &s[i]);
  }
  
  printf("%d\n", deal());
  
  return 0;
}