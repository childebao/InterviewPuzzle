/*
 Given an N, print out all the prime factors. 
 
 12 = 2^2 * 3^1;
 
 Sample Input:
 12
 Sample Ouput:
 2(2) 3(1)
 
*/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<int> primes;
bool flag[1100];

void initPrimes()
{
  memset(flag, false, sizeof(flag));
  
  for (int i = 2; i < 1000; i ++) {
    if (!flag[i]) {
      primes.push_back(i);
      
      int j = i * i;
      while (j < 1000) {
        flag[j] = true;
        j += i;
      }
    }
  }
  
//  cout << primes.size() << endl;
//  
//  for (int i = 0; i < 100; i ++) {
//    cout << primes[i] << ' ';
//  }
//  cout << endl;
}

void deal(int N)
{
  if (N <= 1) {
    cout << "Invalid input" << endl;
    return;
  }
    
  for (int i = 0; i < primes.size() && primes[i] <= N; i ++) {
    int count = 0;
    while (N > 0 && N % primes[i] == 0) {
      count ++;
      N /= primes[i];
    }
    
    if (count > 0) {
      cout << primes[i] << '(' << count << ')' << ' ';
    }
  }
  
  if (N > 1) {
    cout << N << "(1)" << endl;
  }

  cout << endl;
}

int main()
{
  initPrimes();
  int N;
  
  while (cin >> N) {
    deal(N);
  }
  
  return 0;
}