/*
 Timus 1917: http://acm.timus.ru/problem.aspx?space=1&num=1917
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int N, P, i, h[1000100], flag[1010];
vector<pair<int, int> > nodes;

void deal(const int & P)
{
  int maxCoins = 0, minSpells = 0, tmp = 0;
  
  for (i = 1; i < nodes.size(); i ++) {
    tmp += nodes[i].second;
    if (tmp * nodes[i].first > P) {
      tmp -= nodes[i --].second;
      if (tmp == 0) break; else maxCoins += tmp;
      
      minSpells ++;
      tmp = 0;
    } else if (i == nodes.size() - 1) {
      maxCoins += tmp;
      minSpells ++;
    }
  }
  
  cout << maxCoins << ' ' << minSpells << endl;
}


void BFS(const int & P)
{
  int maxCoins = 0, minSpells = 0, tmp = 0, maxPower = 0;
  
  queue<int> q;
  q.push(0);
  int front, back = q.back();
  
  while (!q.empty()) {
    front = q.front();
    tmp = 0;
    for (i = front + 1; i < nodes.size(); i ++) {
      tmp += nodes[i].second;
      if (tmp * nodes[i].first > P) break;
      if (flag[i]) continue; else flag[i] = 1;

      q.push(i);
      maxPower = max(maxPower, i);
    }
    
    if (front == back) {
      back = q.back();
      minSpells ++;
    }
    
    q.pop();
  }
  
  for (int i = 1; i <= maxPower; i ++) maxCoins += nodes[i].second;
  cout << maxCoins << ' ' << minSpells - 1 << endl;  // minSpells - 1
}

int main()
{
  cin >> N >> P;
  while (N -- && cin >> i) h[i] ++;
  
  nodes.push_back(make_pair(0, 0));
  for (i = 0; i < 1000000; i ++) {
    if (h[i]) nodes.push_back(make_pair(i, h[i]));
  }
  
  deal(P);
  BFS(P);
  
  return 0;
}
