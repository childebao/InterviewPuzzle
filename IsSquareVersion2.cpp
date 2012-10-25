#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

// square decision

struct Point
{
    int x, y;
    Point(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};

inline int sqr(int x)
{
    return x * x;
}

inline int sqrdist(const Point & a, const Point & b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

bool isSquare(vector<Point>& pts)
{
    if (pts.size() != 4)
        return false;

    vector<int> sqrdists;
    for (unsigned int i = 0; i < 4; ++i)
        for (unsigned int j = i + 1; j < 4; ++j)
            sqrdists.push_back(sqrdist(pts[i], pts[j]));

    sort(sqrdists.begin(), sqrdists.end());
    return sqrdists[0] == sqrdists[3] && sqrdists[4] == sqrdists[5] && sqrdists[4] == 2 * sqrdists[0];
}

int main()
{
    vector<Point> pts;
    pts.push_back(Point(0, 4));
    pts.push_back(Point(4, 4));
    pts.push_back(Point(4, 0));
    pts.push_back(Point(0, 0));

    cout << isSquare(pts) << endl;
}