/*
 
 Power Outage I 
 https://cs3.interviewstreet.com/challenges/dashboard/#problem/4fea4d68bf9fc
 
 */

#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int m, n, k;

struct Road {
  int n, c;
  Road (int node, int cost) : n(node), c(cost) {}
};

class Graph
{
  int V;
  list<Road> *adj;
public:
  Graph(int V);
  void addEdge(int v, int w, int c);
  void solve();
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<Road>[V];
}

void Graph::addEdge(int v, int w, int c)
{
  adj[v].push_back(Road(w, c));
}

void clearArray(bool a[], int n)
{
  for (int i = 0; i < n; i ++) {
    a[i] = false;
  }
}

void Graph::solve()
{
  if (k <= 0) {
    cout << "Impossible!" << endl;
    return;
  }
  
  bool spanningTree[V];
  clearArray(spanningTree, V);
  bool visited[V];
  clearArray(visited, V);

  list<int> q;
  spanningTree[0] = true;
  int count = 1;
  
  list<Road>::iterator i;
  Road minRoad = Road(-1, 999999999);
    
  while (true) {
    for (int node = 0; node < V; node ++) {
      if (visited[node]) {
        continue;
      }
      
      for (i = adj[node].begin(); i != adj[node].end(); i ++) {
        if (spanningTree[node] && !spanningTree[i->n]) {
          if (minRoad.c > i->c) {
            minRoad.c = i->c;
            minRoad.n = i->n;
          }
        } else if (!spanningTree[node] && spanningTree[i->n]) {
          if (minRoad.c > i->c) {
            minRoad.c = i->c;
            minRoad.n = node;
          }
        }
      }
    }
      
            
    if (minRoad.n != -1) {
      spanningTree[minRoad.n] = true;
      q.push_back(minRoad.c);
      minRoad = Road(-1, 999999999);
    } else {
      
      for (int node = 0; node < V; node ++) {
        if (spanningTree[node]) {
          visited[node] = true;
        }
      }
      
      int node;
      
      for (node = 0; node < V; node ++) {
        if (!spanningTree[node]) {
          spanningTree[node] = true;
          count ++;
          
          if (count > k) {
            cout << "Impossible!" << endl;
            return;
          }
          
          break;
        }
      }
      
      if (node == V) {
        if (count >= k) {
          q.sort();
          int ans = 0;
          while (count > k) {
            q.pop_back();
          }
          
          while (!q.empty()) {
            ans += q.front();
            q.pop_front();
          }
          
          cout << ans << endl;
          return;
        }
      }
    }

    
  }
  
}

int main()
{
  int t, i, j, c;
  cin >> t;
  while (t --) {
    cin >> n >> m >> k;
    Graph g = Graph(n);
    while (m --) {
      cin >> i >> j >> c;
      g.addEdge(i - 1, j - 1, c);
    }
    
    g.solve();
  }
}