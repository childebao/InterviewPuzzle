/*
 
 Power Outage I 
 https://cs3.interviewstreet.com/challenges/dashboard/#problem/4fea4d68bf9fc
 
 */

#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, K;

struct UnionFindSet {
  vector<int> f;
  int setCnt;
  
  UnionFindSet (int N) {
    f = vector<int> (N, -1);
    setCnt = N;
  }
  
  int Find(int x) {
    if (f[x] < 0) return x;
    return f[x] = Find(f[x]);
  }
  
  bool Union(int x1, int x2) {
    int f1 = Find(x1);
    int f2 = Find(x2);
    
    if (f1 == f2) return false;
    if (rand() & 1) f[f1] = f2; else f[f2] = f1;
    setCnt --;
    return true;
  }
};


struct Edge {
  int a, b, c;
  bool operator < (const Edge & edge) const {
    return c < edge.c;
  }
};

vector<Edge> edges;

void solve() {
  UnionFindSet ufs = UnionFindSet(N);
  int ans = 0;
  
  sort(edges.begin(), edges.end());
  
  for (int i = 0; i < M; i ++) {
    if (ufs.setCnt <= K) break;
    if (ufs.Union(edges[i].a - 1, edges[i].b - 1)) ans += edges[i].c;
  }
  
  if (ufs.setCnt <= K) {
    cout << ans << endl;
  } else {
    cout << "Impossible!" << endl;
  }
}

int main() {
  cin >> T;
  while (T --) {
    cin >> N >> M >> K;
    edges.resize(M);
    
    for (int i = 0; i < M; i ++) {
      cin >> edges[i].a >> edges[i].b >> edges[i].c;
    }
    solve();
  }
}