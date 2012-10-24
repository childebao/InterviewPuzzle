
/*
 
 isSquare!
 
 */

#include <iostream>

using namespace std;

struct Point {
  int x, y;
  Point () {}
  Point (int _x, int _y) : x(_x), y(_y) {}
};

bool isSquare(const Point &lt, const Point &rb)
{
  return (abs(rb.x - lt.x) == abs(lt.y - rb. y)) && rb.x != lt.x;
}

int main()
{
  Point lt, rb;
  
  while (cin >> lt.x >> lt.y >> rb.x >> rb.y) {    
    if (isSquare(lt, rb)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}