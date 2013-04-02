class Solution {
public:
  vector<vector<string> > ans;
  int minimalLevel;
  
  vector<string> getNeighbours(string start, unordered_set<string> &dict)
  {
    vector<string> res;
    string tmp = start;
    
    for (int i = 0; i < start.length(); i ++) {
      for (int j = 'a'; j <= 'z'; j ++) {
        if (j != start[i]) {
          tmp[i] = j;
          if (dict.find(tmp) != dict.end()) res.push_back(tmp);
          tmp[i] = start[i];
        }
      }
    }
    return res;
  }
  
  void getLadderLevel(string start, string end, unordered_set<string> &dict)
  {
    map<string, bool> visited;
    visited[start] = true;
    
    queue<pair<string, int> >q;
    q.push(make_pair(start, 1));
    
    minimalLevel = dict.size();
    
    while (!q.empty()) {
      pair<string, int> node = q.front();
      
      if (node.first == end) {
        minimalLevel = node.second;
        return;
      }
      
      vector<string> nbs = getNeighbours(node.first, dict);
      for (int i = 0; i < nbs.size(); i ++) {
        string nb = nbs[i];
        if (!visited[nb]) {
          visited[nb] = true;
          q.push(make_pair(nb, node.second + 1));
        }
      }
      
      q.pop();
    }
  }
  
  void dfs(string start, string end, vector<string> & path, unordered_set<string> &visited, unordered_set<string> &dict)
  {    
    if (start == end) {
      path.push_back(start);
      if (path.size() == minimalLevel) {
        ans.push_back(path);
      }
      return;
    }

    path.push_back(start);
    if (path.size() >= minimalLevel) return;

    visited.insert(start);
    
    vector<string> nbs = getNeighbours(start, dict);
    
    for (int i = 0; i < nbs.size(); i ++) {
      string nb = nbs[i];
      if (visited.find(nb) == visited.end()) {
        dfs(nb, end, path, visited, dict);
        path.pop_back();
      }
    }
    
    visited.erase(start);
  }
  
  vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) 
  {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
    getLadderLevel(start, end, dict);
    vector<string> path;
    ans.clear();
    
    unordered_set<string> visited;
    dfs(start, end, path, visited, dict);
    
    return ans;
  }
    
    
};

