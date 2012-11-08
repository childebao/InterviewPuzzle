/*
 
 Don't forget those negative numbers!
 
 BUGS:
 -1 / 2 = 0 not -0;
 */

#include <iostream>
#include <algorithm>

using namespace std;
int N;

int find(long long x, long long a[], int N, int &index)
{
  int l = 0, r = N - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    
    if (a[mid] == x) {
      index = mid;
      return 1;
    }
    
    if (a[mid] < x) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  
  index = l;
  return -1;
}

void printAverage(long long a, long long b)
{
  if (a + b < 0) {
    printf("-");
    printAverage(-a, -b);
    return;
  }
  
  if ((a + b) % 2 != 0) {
    printf("%lld.5\n", (a + b) / 2);
  } else {
    printf("%lld\n", (a + b) / 2);
  }
}

void printMedian(long long a[], int N)
{
  if (N == 0) {
    printf("Wrong!\n");
  } else if (N % 2 == 0) {
    printAverage(a[N/2], a[N/2 - 1]);
  } else {
    printf("%lld\n", a[N/2]);
  }
  
}

void insert(long long a[], long long x, int &N)
{
  int index = 0;
  find(x, a, N, index);
  
  for (int i = N; i > index; i --) {
    a[i] = a[i - 1];
  }
  
  a[index] = x;
  N ++;
  
  printMedian(a, N);
}

void remove(long long a[], long long x, int &N)
{
  int index = 0;
  
  if (N > 0 && find(x, a, N, index) == 1) {
    for (int i = index; i < N - 1; i ++) {
      a[i] = a[i + 1];
    }
    
    N --;
    printMedian(a, N);
  } else {
    printf("Wrong!\n");
  }
}

int main()
{
  cin >> N;
  long long a[N + 1];
  int count = 0;
  char op;
  long long num;
  
  for (int i = 0; i < N; i ++) {
    cin >> op >> num;
    
    if (op == 'a') {
      insert(a, num, count);
    } else {
      remove(a, num, count);
    }
  }
  
  return 0;
}
