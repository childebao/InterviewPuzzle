
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int N, a[66], M, sum, maxLength, lengths[100];
int dp[3300], sticks[66];

bool search(int len, int num, int curLen, int curNum)
{
  if (curLen >= len) curNum ++, curLen = 0;
  if (curNum >= num) return true;

  for (int i = 0; i < N; i ++) {
    if (sticks[i]) continue;
    if (a[i] > len - curLen) continue;
    
    sticks[i] = 1;
    if (search(len, num, curLen + a[i], curNum)) return true;
    
    sticks[i] = 0;
    if (a[i] == len - curLen || curLen == 0) break;
  }
  
  return false;
}

int main()
{
  while (cin >> N && N) {
    maxLength = 0, sum = 0;
    for (int i = 0; i < N; i ++) {
      cin >> a[i];
      maxLength = max(maxLength, a[i]);
      sum += a[i];
    }
    
    sort(a, a + N, greater<int>());
    
    M = 0;
    for (int i = maxLength; i <= sum; i ++) 
      if (sum % i == 0) lengths[M ++] = i;
    
    bool flag = false;
    for (int i = 0; i < M && !flag; i ++) {
      memset(sticks, 0, sizeof(sticks));
      if (search(lengths[i], sum / lengths[i], 0, 0)) {
        cout << lengths[i] << endl;
        flag = true;
        break;
      }
    }
  
  }
  
  return 0;
}
