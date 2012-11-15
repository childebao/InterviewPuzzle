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
int N, P, i, j, tmp, h[1000100];
vector<pair<int, int> > nodes;

void deal(const int & P)
{
  int maxCoins = 0, minSpells = 0;

  for (i = 0; i < nodes.size();) {
    tmp = 0;
    
    for (j = i + 1; j < nodes.size(); j ++) {
      tmp += nodes[j].second;
      if (tmp * nodes[j].first > P) {
        tmp -= nodes[j].second;
        break;
      }
    }
    
    if (j == i + 1) break;
    else {
      i = j - 1;
      minSpells ++;
      maxCoins += tmp;
    }
  }

  cout << maxCoins << ' ' << minSpells << endl;
}

int main()
{
  cin >> N >> P;
  while (N -- && cin >> tmp) h[tmp] ++;
  
  nodes.push_back(make_pair(0, 0));
  for (int i = 0; i < 1000000; i ++) {
    if (h[i]) nodes.push_back(make_pair(i, h[i]));
  }
  
  deal(P);
  
  return 0;
}
