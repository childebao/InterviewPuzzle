
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

int square(int n)
{
  return n * n;
}

int dis(const Point &p1, const Point &p2)
{
  return square(p1.x - p2.x) + square(p1.y - p2.y);
}

bool sum(const Point &p1, const Point &p2, const Point &p3)
{
  return (dis(p1, p2) == dis(p1, p3) && 2 * dis(p1, p2) == dis(p2, p3))
  || (dis(p1, p3) == dis(p2, p3) && dis(p1, p2) == 2 * dis(p2, p3));
}

bool isSquare(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
{
  return sum(p1, p2, p3) && sum(p1, p2, p4) &&  sum(p1, p3, p4) && sum(p2, p3, p4);
}

int main()
{
  Point p1, p2, p3, p4;
  
  while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y) {    
    if (isSquare(p1, p2, p3, p4)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}