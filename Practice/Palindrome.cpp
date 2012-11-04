/*
 Calculate the minimal characters that need to be added to string S to make S a palindrome.
 
 Sample Input:
 sadfasfg
 
 Sample Output: 3
 
 */

#include <iostream>
#include <string>

using namespace std;

string reverse(string s)
{
  int head = 0, tail = s.length() - 1;
  while (head < tail) {
    swap(s[head ++], s[tail --]);
  }
  return s;
}

int deal(string s)
{
  string t = reverse(s);
  s = '0' + s;
  t = '0' + t;
  
  int dp[s.length()][s.length()][2];
  
  dp[0][0][0] = dp[0][0][1] = 0;
  
  for (int i = 1; i < s.length(); i ++) {
    dp[0][i][0] = dp[i][0][0] = i;
    dp[0][i][1] = dp[i][0][1] = i - 1;
  }
  
  for (int i = 1; i < s.length(); i ++) {
    for (int j = 1; j < s.length() - i; j ++) {
      if (s[i] == t[j]) {
        dp[i][j][0] = dp[i - 1][j - 1][0];
        dp[i][j][1] = min(dp[i - 1][j][0], dp[i][j - 1][0]);
        continue;
      }
      
      dp[i][j][0] = min(dp[i - 1][j][0] + 1, dp[i][j - 1][0] + 1);
      dp[i][j][1] = min(min(dp[i - 1][j][0], dp[i][j - 1][0]), dp[i - 1][j - 1][0] + 1);
//      cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
    }
  }
  
  int ans = s.length();
  
  for (int i = 0; i < s.length(); i ++) {
    ans = min(ans, min(dp[i][s.length() - 1 - i][0], dp[i][s.length() - 1 - i][1]));
  }
  
  return ans;
}

int main()
{
  string s;
  
  while (cin >> s) {
    cout << deal(s) << endl;
  }
  
  return 0;
}