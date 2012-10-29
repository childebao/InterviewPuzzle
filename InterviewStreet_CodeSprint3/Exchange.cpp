/*
 
 https://cs3.interviewstreet.com/challenges/dashboard/#problem/4f846fced75d3
 
 Test Case:
 
 5
 5 1 3 2 4
 NNNNY
 NNNNY
 NNNYN
 NNYNN
 YYNNN
 
 */

#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;


int K;
int num[110];

class Graph
{
  int V;
  list<int> *adj;
public:
  Graph(int V);
  void addEdge(int v, int w);
  void getMin(int s);
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
}

void Graph::getMin(int start)
{
  int s = start;
  int posi = s;
  int value = num[s];
  bool *visited = new bool[V];
  for (int i = 0; i < V; i ++) {
    visited[i] = false; // to avoid circle...
  }
  
  list<int> q;
  visited[s] = true;
  q.push_back(s);
  
  list<int>::iterator i;
  
  while (!q.empty()) {
    s = q.front();
    
    if (num[s] < value && s > start) {
      posi = s;
      value = num[s];
    }
    
    for (i = adj[s].begin(); i != adj[s].end(); i ++) {
      
      if (!visited[*i]) {
        visited[*i] = true;
        q.push_back(*i);
      }
    }
    
    q.pop_front();
  }
  
  if (posi != start) {
    swap(num[start], num[posi]);
  }
}

int main()
{
  cin >> K;
  Graph g(K);
  
  for (int i = 0; i < K; i ++) {
    cin >> num[i];
  }

  for (int i = 0; i < K; i ++) {
    string line;
    cin >> line;
    for (int j = 0; j < K; j ++) {
      if (line[j] == 'Y') {
        g.addEdge(i, j);
      }
    }
  }
  
  for (int i = 0; i < K; i ++) {
    g.getMin(i);
    cout << num[i] << ' ';
  }

  cout << endl;
}

