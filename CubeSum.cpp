/*
 
 3 4
 2 3 4 5
 2 4 8 3
 9 3 4 9
 
 0 0 1 1 
 1 1 2 2
 2 2 1 1
 */

#include <iostream>
using namespace std;

//n rows, m cols
void init(int **a, int h, int w)
{
  for (int j = 1; j < w; j ++) {
    a[0][j] += a[0][j - 1];
  }
  for (int i = 1; i < h; i ++) {
    a[i][0] += a[i - 1][0];
    
    for (int j = 1; j < w; j ++) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i-1][j-1]; 
    }
  }
}

int query(int **a, int r, int c, int h, int w)
{
  if (r == 0 && c == 0) {
    return a[h - 1][w - 1];
  }
  
  if (r == 0) {
    return a[r + h - 1][c + w - 1] - a[r + h - 1][c - 1];
  }
  
  if (c == 0) {
    return a[r + h - 1][c + w - 1] - a[r - 1][c + w - 1];
  }
  
  return a[r + h - 1][c + w - 1] + a[r - 1][c - 1] - a[r + h - 1][c - 1] - a[r - 1][c + w - 1];
}

int main()
{
  int n, m;
  cin >> n >> m;
  int **a = new int * [n];
  
  for (int i = 0; i < n; i ++) {
    a[i] = new int[m];
    
    for (int j = 0; j < m; j ++) {
      cin >> a[i][j];
    }
  }
  
  init(a, n, m);
  
  cout << endl << endl;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  
  cout << endl;
  
  int r, c, h, w;
  while (cin >> r >> c >> h >> w) {
    cout << query(a, r, c, h, w) << endl;
  }
  
  return 0;
}