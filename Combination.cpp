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

void search(int a[], int begin, int n, int k)
{
  if (begin >= n) {
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
  search(a, begin + 1, n, k - 1);
  
  flag[begin] = false;
  search(a, begin + 1, n, k);
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
    
    search(a, 0, n, k);
  }
  
  return 0;
}