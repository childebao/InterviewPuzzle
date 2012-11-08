#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  int a[N];
  int total = 0;
  
  for (int i = 0; i < N; i ++) {
    cin >> a[i];
  }
  
  sort(a, a + N);
  
  int b = 1;
  for (int i = N - 1; i >= 0; i -= K) {
    for (int j = 0; j < K && i - j >= 0; j ++) {
      total += a[i - j] * b;
    }
    b ++;
  }  
  
  cout << total << endl;
  
  return 0;
}
