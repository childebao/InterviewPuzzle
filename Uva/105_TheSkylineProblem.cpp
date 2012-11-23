/*
 
 UVA: 105 The Skyline Problem
 http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=41
 
 Analysis:
 1. We got all the nodes with (Li, Hi, Ri) sorted in increasing order of L (and increasing order of R if L is the same).
 2. Then we got all the points of x coordinate, which might be 2 times of the node[] number, record the index of each point in the node[], initialize the height with 0.
 3. Sort the points[] in increasing order of x.
 4. So that now we need to get the max height of each x. How to do it? As for each point[i], we could know the index of the point in node[]. And the point[i] could either be the l or the r of the node. If we could know the point[i] is just the l, then we update all the height of the points in [l, r). (r is not included.)
     
     So, how we could know if the point[i] is the left point of the node? As the node[] is in increasing order of l, so as we visited points[] increasingly we visited the nodes increasingly. Each node needs to be just visited once. 
    
     Now we use lastVisitedIndex to record the last node we have visited. So if we found the point[i].index is less than lastVisitedIndex, that means it is the r of the node, and we've already visited it before, while on the other hand, it is the l of the node, and we just update lastVisitedIndex as the current index.
 
 5. We got the max height of each point, and just print them out. Some details we still need to point out:
     
    a) We may have duplicated points: if we got duplicated points, we need to get the max height of those points, cause we never update the those points when we move to the next point with the same x value.
    b) We may have duplicated height with continuous distinct points: if we found some continuous distince points with the same height, we just need to print the smallest x of them with the height. So, remember to ignore the next duplicated height.
 
 6. That's it, AC at the first time!
 
 Test Case;
 1 11 5
 2 6 7
 2 19 4
 3 13 9
 12 7 16
 12 30 16
 14 3 25
 19 18 22
 23 13 29
 24 4 28
 
 Answer:
 1 11 2 19 4 13 9 0 12 30 16 3 19 18 22 3 23 13 29 0
 
 */

#include <iostream>  
#include <algorithm> 
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;  

int N = 0, M = 0, L, R, H;
struct Node {
  int l, r, h;
  
  // If the nodes are not initially sorted, sort them...
  bool operator < (const Node &n) const {
    if (this->l != n.l) return this->l < n.l;
    return this->r <= n.r;
  };
} node[5010];

struct XPoint {
  int x, index, height;
  bool operator < (const XPoint &p) const {
    if (this->x != p.x) return this->x < p.x;
    return this->index <= p.index;
  }
}points[10010];

int main()  
{
  while (cin >> node[N].l >> node[N].h >> node[N].r) {
    points[M].x = node[N].l;
    points[M].height = 0;
    points[M ++].index = N;
    
    points[M].x = node[N].r;
    points[M].height = 0;
    points[M ++].index = N;
    
    N ++;
  }

  sort(points, points + M);
  
  int lastVisitedIndex = -1;
  for (int i = 0; i < M; i ++) {
    //Each time, we got a point x, and find its l,r,h in the node[]. And updates all the heights [l, r)
    
    //points[i].index < lastVisitedIndex means the points has been visited before.
    if (points[i].index < lastVisitedIndex) continue;
    else lastVisitedIndex = points[i].index;
    
    int right = node[points[i].index].r;
    int height = node[points[i].index].h;
    
    //Don't include the point right.
    for (int j = i; points[j].x < right; j ++) {
      if (points[j].height < height) points[j].height = height;
    }
  }
  
  for (int i = 0; i < M;) {
    //If there are some duplicated points x, get the highest height of them
    while (i + 1 < M && points[i].x == points[i + 1].x) {
      points[i + 1].height = max(points[i].height, points[i + 1].height);
      i ++;
    }
    
    cout << points[i].x << ' ' << points[i].height;
    i ++;
    
    //If the following points x have the same height, ignore them.
    while (i < M && points[i].height == points[i - 1].height) i ++;
    if (i <= M - 1) cout << ' ';
  }
  
  cout << endl;
  return 0;  
}