/*
 
 Given you two integer a, b assume a < b and a, b > 0 and a < b
 you should output the fraction format of a / b
 for e.g
 
 a = 1 b = 4  output 0.25
 a = 1 b = 3  output 0.(3)
 a = 2 b = 3  output 0.(6)
 a = 1 b = 7  output 0.(142857)
 a = 1 b = 6  output 0.1(6)
 
 ( means begin of the cycle 
 ) means end of the cycle
 
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;

string getFraction(string& str, int index)
{
  return str.substr(0, index) + "(" + str.substr(index) + ")";
}

string fractionFormat(int a, int b)
{
  map<int, int> mp;
  
  string result = "0.";
  a *= 10;
  
  while (a != 0) {
    while (a < b) {
      mp[a] = result.length();
      result += '0';
      a *= 10;
    }
    
    if (a >= b) {
      mp[a] = result.length();
      result += (int)(a / b) + '0';
      a = (a % b) * 10;
    }
    
    if (mp[a]) return getFraction(result, mp[a]);
  }
  
  return result;
}

int main()
{
  int a, b;
  while (cin >> a >> b) {
    if (!(a > 0 && b > 0 && a < b)) {
      cout << "Make sure a > 0 && b > 0 && a < b" << endl;;
      continue;
    }
    
    cout << fractionFormat(a, b) << endl;
  }
}
