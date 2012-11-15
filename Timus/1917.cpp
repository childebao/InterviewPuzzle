/*
 Timus 1917: http://acm.timus.ru/problem.aspx?space=1&num=1917
 
 From the problem description, the Annihilation Spell destroys all the coins whose resistance limit is no greater than the power of the spell. 
 
 We could draw some conclusions as:
 1. The power of spell should increase each time.
 2. The power of each spell should be the ones of the coins' resistance limits. Because there is no need to be larger than the maximum limits of the coins we'd like to destroy at the time.
 3. The wizard could no longer give a spell if we meet the kind of coins with N coins of L each, and N * L > P (P is the maximum power the he can survive)
 
 Method 1: BFS().
 This is a Graph theory algorithm.
 Now sort the coins limits, and count the coins of M kinds, nodes[M], adding another kind with 0 coin of 0 limits at the beginning.
 We can construct a directed Graph, if there is an edge from node i to node j, so that the number of coins greater than limit[i] and less and equal than limits[j] is count, count * limit[j] <= P.
 We could use Breadth First Search to find the maximum limit that could be reached from 0 to M.
 
 Method 2: deal().
 This is a greedy algorithm.
 As from the 3 conclusion, we could prove that each time choose as many coins as we can to destoy, until we meet the kind of coins whose total limits is greater than P.
 We could prove the using this greedy algorithm, we could get the minimum spells and the maximum coins we could destroy.
 
 For each spell, we choose some kinds of coins to destroy, until we meet the kind of coins with N coins and L limits, where N * L > P, which could get the maximum coins we could desotry. This is obvious because if we choose the kind with greater limits coins, as we could not destroy them last time, so when destroying the greater limits those left coins would be destroyed together, and the power they give back would be greater, too, that's impossible. So the greedy algorithm could get the maxmum coins we could destroy.
 For each spell, we choose as many kinds of coins as we can to destoy, which could get the minimum spell we destroy those coins. If we could destroy those M coins with N spells, and now we don't choose as many as we can, for example, we could choose the first two kinds of coins, but we just choose the first one, and then we left M - count1 coins, which is greater than M - count1 - count2 if we choose the first two. If we could destroy those M - count1 in less than N - 1 spells, it is obvious that we could destroy those M - count1 - count2 coins in less than N - 1. But that's impossible. 
 So the greedy algorithm is correct.
 
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
