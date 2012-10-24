/*
 
 Input:
 
 4 4
 1 2 3 4
 5 3
 1 2 3 4 5
 
 Output:
 1:
 1 2 3 4 
 
 1:
 1 2 5 
 
 2:
 1 3 5 
 
 3:
 1 4 5 
 
 4:
 2 3 5 
 
 5:
 2 4 5 
 
 6:
 3 4 5 
 

 */

#include <iostream>
using namespace std;

bool flag[100];
int ans;

void search1(int a[], int begin, int n, int k)
{
  if (k == 0) {
    cout << ++ans << ":" << endl;
    
    for (int i = 0; i < n; i ++) {
      if (flag[i]) {
        cout << a[i] << ' ';
      }
    }
    cout << endl << endl;
    return;
  }
  
  if (n - begin < k) {
    return;
  }
  
  if (n - begin == k) {
    cout << ++ans << ":" << endl;
    
    for (int i = 0; i < begin; i ++) {
      if (flag[i]) {
        cout << a[i] << ' ';
      }
    }
    
    for (int i = begin; i < n; i ++) {
      cout << a[i] << ' ';
    }
    
    cout << endl << endl;
    return;
  }
  
  flag[begin] = true;
  search1(a, begin + 1, n, k - 1);
  
  flag[begin] = false;
  search1(a, begin + 1, n, k);
}

void search2(int a[], int begin, int n, int k)
{
  if (k == 0) {
    cout << ++ans << ":" << endl;
    
    for (int i = 0; i < n; i ++) {
      if (flag[i]) {
        cout << a[i] << ' ';
      }
    }
    cout << endl << endl;
    return;
  }
    
  if (n - begin < k) {
    return;
  }
  
  if (n - begin == k) {   
    cout << ++ans << ":" << endl;

    for (int i = 0; i < begin; i ++) {
      if (flag[i]) {
        cout << a[i] << ' ';
      }
    }
    
    for (int i = begin; i < n; i ++) {
      cout << a[i] << ' ';
    }
    
    cout << endl << endl;
    return;
  }
  
  for (int i = begin; i < n; i ++) {
    flag[i] = true;
    search2(a, i + 1, n, k - 1);
    flag[i] = false;
  }
}


/// combination generation

int N, K;
int nums[20];

void output(int a[])
{
  for (int i = 0; i < K; ++i)
    cout << a[nums[i] - 1] << " ";
  cout << endl;
}

void search3(int curK, int curNum, int a[])
{
  if (curK == K) return output(a);
  for (int i = curNum; i <= N; ++i)
  {
    nums[curK] = i;
    search3(curK + 1, i + 1, a);
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
    
//    search1(a, 0, n, k);
    
    N = n; K = k;
    search3(0, 1, a);
  }
  
  return 0;
}