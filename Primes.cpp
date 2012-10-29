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
bool flag[500100];

void initPrimes()
{
  memset(flag, false, sizeof(flag));
  
  for (int i = 2; i < 500000; i ++) {
    if (!flag[i]) {
      primes.push_back(i);
      
      long long j = (long long)i * i;
      while (j < 500000) {
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
  
  int isPrime = true;
  
  for (int i = 0; i < primes.size() && primes[i] < N; i ++) {
    int count = 0, tmp = N;
    while (tmp > 0 && tmp % primes[i] == 0) {
      count ++;
      tmp /= primes[i];
      isPrime = false;
    }
    
    if (count > 0) {
      cout << primes[i] << '(' << count << ')' << ' ';
    }
  }
  
  if (isPrime) {
    cout << "It is prime." << endl;
  } else {
    cout << endl;
  }
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