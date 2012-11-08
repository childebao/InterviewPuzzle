#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int a[N], b[N];
  
  int total = 0;
  
  for (int i = 0; i < N; i ++) {
    cin >> a[i];
    b[i] = 0;
  }
  
  b[0] = 1;
  for (int i = 1; i < N; i ++) {
    b[i] = 1;
    
    if (a[i - 1] < a[i]) {
      b[i] = b[i - 1] + 1; 
    } else {
      int j = i;
      while (j > 0 && a[j - 1] > a[j]) {
        b[j - 1] = max(b[j - 1], b[j] + 1);
        j --;
      }
    }
  }
  
  for (int i = 0; i < N; i ++) {
    total += b[i];
  }
  
  cout << total << endl;
  
  return 0;
}