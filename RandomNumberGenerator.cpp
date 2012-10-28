/*
 
 Random number generator
 https://cs3.interviewstreet.com/challenges/dashboard/#problem/5087a2807930b
 
 */

#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int gcd (int a, int b)
{
  int c;
  while ( a != 0 ) {
    c = a; a = b % a;  b = c;
  }
  return b;
}

void solve(int A, int B, int C, int &s1, int &s2)
{
  if (C >= A + B) {
    s1 = 1, s2 = 1;
    return;
  }
  
  if (A > B) {
    swap(A, B);
  }
  
  s2 = A * B * 2;
  if (C >= B) {
    s1 = s2 - (A + B - C) * (A + B - C);
    return;
  }
  
  if (C >= A) {
    s1 = C * C - (C - A) * (C - A);
    return;
  }
  
  s1 = C * C;
}

int main()
{
  int cases;
  cin >> cases;
  int A, B, C;
  int s1, s2;
  
  while (cases --) {
    cin >> A >> B >> C;
    
    solve(A, B, C, s1, s2);
    
    cout << s1 / gcd(s1, s2) << '/' << s2 / gcd(s1, s2) << endl;
  }
}