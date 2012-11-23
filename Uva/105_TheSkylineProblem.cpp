/*
 
 UVA: 105 The Skyline Problem
 http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=41
 
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
  int n;
  cin >> n;
  
  while (n -- && cin >> node[N].l >> node[N].h >> node[N].r) {
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
    if (points[i].index < lastVisitedIndex) continue;
    else lastVisitedIndex = points[i].index;
    
    int right = node[points[i].index].r;
    int height = node[points[i].index].h;
    
    for (int j = i; points[j].x < right; j ++) {
      if (points[j].height < height) points[j].height = height;
    }
  }
  
  for (int i = 0; i < M;) {
    while (i + 1 < M && points[i].x == points[i + 1].x) {
      points[i + 1].height = max(points[i].height, points[i + 1].height);
      i ++;
    }
    
    cout << points[i].x << ' ' << points[i].height;
    i ++;
    while (i < M && points[i].height == points[i - 1].height) i ++;
    if (i <= M - 1) cout << ' ';
  }
  
  cout << endl;
  return 0;  
}  



