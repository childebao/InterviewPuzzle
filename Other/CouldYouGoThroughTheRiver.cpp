/*
 * 
 * Question:
 * There is a river, "** *** **  ****  * * ***", '*' star stands for rock, ' ' space stands for water.
 * You are at the position 0 in speed 0 in the beginning, every time you could increase your current speed
 * by 1 or decreasing it by 1 or keep it as the same. But speed should be non negtive.
 * Could you reach the end of the river?
 *
 *
 * Solution:
 * Memorization Dynamic Programming.
 * Search each state of dp[p][s], which should be true if we could reach position p with speed s, otherwise,
 * false.
 * Time and space complexity are both: O(n*sqrt(n))
 * 
*/

#include <iostream>
#include <vector>
using namespace std;

int a[1000], N;
string river;
const int LEN = 100;
int f[LEN][LEN];
int caled[LEN][LEN];

bool reachable(int posi, int speed)
{
  if (posi == N - 1 && river[posi] == '*') {
    return true;
  } else if (posi >= N || river[posi] == ' ') {
    return false;
  } else if (caled[posi][speed]) {
    return f[posi][speed];
  }
  
  f[posi][speed] = false;
  caled[posi][speed] = true;
  
  for (int i = -1; i <= 1; i ++) {
    int s = speed + i;
    if (s > 0) {
      f[posi][speed] |= reachable(posi + s, s);
      if (f[posi][speed]) {
        return true;
      }
    }
  }
  
  return f[posi][speed];
}

bool isReachable()
{
  memset(caled, false, sizeof(caled));
  
  return reachable(0, 0);
}

int main()
{
  while (getline(cin, river)) {
    N = river.length();
    if (isReachable()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  
  return 0;
}
