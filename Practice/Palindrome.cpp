/*
 Calculate the minimal characters that need to be added to string S to make S a palindrome.
 
 Sample Input:
 sadfasfg
 
 Sample Output: 3
 
 
 http://poj.org/problem?id=1159
 
 */

#include <iostream>
#include <string>

using namespace std;

short int dp[5001][5001];

void reverse(char s[], char t[], int N)
{
  t[0] = s[0];
  
  int head = 1, tail = N;
  while (head <= tail) {
    t[head] = s[tail];
    t[tail] = s[head];
    head ++, tail --;
  }
}

short int min(short int a, short int b)
{
  return a <= b ? a : b;
}

short int deal(char s[], int N)
{
  int len = N + 1;
  char t[5001];
  reverse(s, t, N);
    
  dp[0][0] = 0;
  
  for (int i = 1; i < len; i ++) {
    dp[0][i] = dp[i][0] = i;
  }
  
  for (int i = 1; i < len; i ++) {
    for (int j = 1; j < len - i; j ++) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i - 1][j - 1];
        continue;
      }
      
      dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
    }
  }
  
  short int ans = len;
  
  for (int i = 0; i < len; i ++) {
    int j = len - 1 - i;
    if (i > 0 && s[i] == t[j]) {
      ans = min(ans, min(dp[i][len - 1 - i], min(dp[i - 1][j], dp[i][j - 1])));
      continue;
    }
    
    if (i > 0 && j > 0) {
      short int tmp = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + 1);
      ans = min(min(ans, tmp), dp[i][j]);
      continue;
    }
    
    if (i == 0) {
      ans = min(ans, j - 1);
    } else {
      ans = min(ans, i - 1);
    }
  }
  
  return ans;
}

int main()
{
  char s[5010];
  int N;
  scanf("%d", &N);
  getchar();
  
  s[0] = '-';
  for (int i = 1; i <= N; i ++) {
    s[i] = getchar();
  }
  
  printf("%d\n", deal(s, N));
  return 0;
}