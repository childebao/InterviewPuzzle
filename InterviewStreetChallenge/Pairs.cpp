#include <iostream>
#include <algorithm>

using namespace std;
int N, K;

int binarySearch(int a[], int left, int right, int target)
{
  int l = left, r = right, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    
    if (a[mid] >= target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  
  int count = 0;
  if (a[l] == target) {
    count = 1;
    
    while (++l <= right && a[l] == target) {
      count ++;
    }
  }
  
  return count;
}

int main()
{
  cin >> N >> K;
  int a[N];
  int count = 0;
  
  for (int i = 0; i < N; i ++) {
    cin >> a[i];
  }
  
  sort(a, a + N);
  
  for (int i = 0; i < N; i ++) {
    count += binarySearch(a, i + 1, N - 1, a[i] + K);
  }
  
  cout << count << endl;
  
  return 0;
}