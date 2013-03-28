/*
 * 
 * Given a array of integers, find 3 indexes i,j,k such that, i < j < k and a[i] < a[j] < a[k]. 
 * Could you find possible in O(n) algorithm.
 *
 * 1. Vector one and two, save current found increasing subsequence's index.
 * 2. Max length of one is 1, max length of two is 2.
 * 3. Integer min save the third index
 *
*/

#include <iostream>
#include <vector>
using namespace std;

int a[1000], N;

bool update(vector<int> & one, vector<int> & two, int & min, int t)
{
  if (two.size() == 2) {
    if(a[t] < a[two[1]]) {
      min = t;
      return true;
    } else if (a[t] > a[two[1]]) {
      if (one.size() == 1 && a[t] < a[one[0]]) {
        two[0] = one[0], two[1] = t;
        one.clear();
      } else {
        one.clear();
        one.push_back(t);
      }
    }
  } else if (two.size() == 0) {
    if (one.size() == 1 && a[t] < a[one[0]]) {
      two.push_back(one[0]);
      two.push_back(t);
      one.clear();
    } else {
      one.clear();
      one.push_back(t);
    }
  }
  
  return false;
}

void output(const vector<int> & v, int min)
{
  cout << N - min - 1 << '(' << a[min] << ')' << ' ';
  for (int i = v.size() - 1; i >= 0; i --) {
    cout << N - v[i] - 1 << '(' << a[v[i]] << ')' << ' ';
  }
  
  cout << endl;
}

void deal()
{
  vector<int> one;
  vector<int> two;
  int min;
  
  int i = 0;
  while (i < N) {
    if (update(one, two, min, i ++)) {
      output(two, min);
      return;
    }
  }
  
  cout << "NONE" << endl;
}

void reverse()
{
  int b = 0, e = N - 1;
  while (b < e) {
    swap(a[b ++], a[e --]);
  }
}

int main()
{
  while (cin >> N)
  {
    for (int i = 0; i < N; i ++)
      cin >> a[i];
    
    reverse();
    deal();
  }
  
  return 0;
}

