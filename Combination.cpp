/*
 Combination Generation:

 Sample Input:
 
 4 4
 1 2 3 4
 5 3
 2 4 6 8 10
 
 Sample Output:
 1 2 3 4 
 
 2 4 6 
 2 4 8 
 2 4 10 
 2 6 8 
 2 6 10 
 2 8 10 
 4 6 8 
 4 6 10 
 4 8 10 
 6 8 10 
 

 */

#include <iostream>
using namespace std;

bool flag[100];
int ans;


int N, K;
int nums[20];

void output(int a[])
{
  for (int i = 0; i < K; ++i)
    cout << a[nums[i]] << " ";
  cout << endl;
}

void recursive(int curK, int curNum, int a[])
{
  if (curK == K) return output(a);
  for (int i = curNum; i < N; ++i)
  {
    nums[curK] = i;
    recursive(curK + 1, i + 1, a);
  }
}

void iteration(int a[])
{  
  int count = 0;
  nums[count ++] = 0;
  
  while (count >= 0) {
    //When left numbers is not enough
    if (nums[count - 1] >= N - K + count) {
      count --;
      if (count >= 0) {
        nums[count - 1] ++;
      }
      continue;
    }
    
    //Output when K numbers generated
    if (count >= K) {
      output(a);
      nums[count - 1] ++;
      continue;
    }
    
    //Generate next number
    nums[count] = nums[count - 1] + 1;
    count ++;
  }
}

int main()
{
  int n, k;
  while (cin >> n >> k && n > 0) {
    ans = 0;
    int a[n];
    for (int i = 0; i < n; i ++) {
      cin >> a[i];
    }
    
    N = n; K = k;
    recursive(0, 0, a);
    cout << endl;
    iteration(a);
  }
  
  return 0;
}