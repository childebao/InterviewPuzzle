/*
 * Given an array of n elements [1, 2, ..., n]. For example { 3, 2, 1, 6, 7, 4, 5}
 * Now create a signature of this array by comparing every consecutive pair of elements
 * If they increase, write 'I' else write 'D'. For example for the array above, the
 * signature would be "DDIIDI". The signature thus has a length of N - 1. Now the 
 * question is given a signature, compute the lexicographically smallest permutation
 * of [1, 2, ..., n].
 *
 *
 * Solution: Greedy.
 * 1. For continuous "D" substring, the lexicographically smallest permutation should be
 * {x + len, x + len - 1, x + len - 2, ..., x}, len should be the number of continuous "D".
 * 2. For continuous "I" substring, the lexicographically smallest permutation should be
 * {x, x + 1, x + 2, ..., x + len - 2, ?}, len should be the number of continuous "I". The 
 * last one could only be defined in case 1.
 *
*/

#include <iostream>
#include <string>
using namespace std;

int N;
string sig;

void deal()
{
  int curr = 0, b = 0, e = 0;
  
  while (curr < N) 
  {
    if (sig[e ++] == 'D') 
    {
      int deCnt = 1;
      while (e < N - 1 && sig[e] == 'D') 
        deCnt ++, e ++;
      
      if (b == 0) curr ++;

      curr += deCnt;
      cout << curr << ' ';
      
      for (int i = b; i < e; i ++)
        cout << curr - (i - b) - 1 << ' ';
      
    }
    else
    {
      int inCnt = 1;
      while (e < N - 1 && sig[e] == 'I') 
        inCnt ++, e ++;
      
      if (b == 0) cout << ++ curr<< ' ';
      
      for (int i = b; i < e - 1; i ++)
        cout << ++ curr << ' ';
      
      if (e == N - 1)
        cout << ++ curr << ' ';
      
      curr ++;
    }
    
    b = e;
  }
  
  cout << endl;
}

// Insert an "I" at sig[0], so that make some end point easier.
void deal2()
{
  int curr = 0, b = 0, e = 0;
  sig = string(1, 'I') + sig;
  
  while (curr < N) 
  {
    if (sig[e ++] == 'D') 
    {
      int deCnt = 1;
      while (e < N && sig[e] == 'D')
        deCnt ++, e ++;
      
      curr += deCnt;
      cout << curr << ' ';
      
      for (int i = b; i < e; i ++)
        cout << curr - (i - b) - 1 << ' ';
      
    } else {
      int inCnt = 1;
      while (e < N && sig[e] == 'I')
        inCnt ++, e ++;
      
      for (int i = b; i < e - 1; i ++)
        cout << ++ curr << ' ';
      
      if (e == N)
        cout << ++ curr << ' ';
      
      curr ++;
    }
    
    b = e;
  }
  
  cout << endl;
}


int main()
{
  while (cin >> N >> sig) 
  {
    deal();
    deal2();
  }
  
  return 0;
}