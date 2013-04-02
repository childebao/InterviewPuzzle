class Solution {
public:

    map<string, vector<string> > next;
    vector<vector<string> > ans;
    int minimalLevel;
    
    void bfs(string start, string end, unordered_set<string> &dict)
    {
        map<string, int> visited;
        visited[start] = 1;
        next.clear();
        
        queue<pair<string, int> >q;
        q.push(make_pair(start, 1));
        
        minimalLevel = dict.size();
        
        while (!q.empty()) {
            
            pair<string, int> node = q.front();
            q.pop();
            string tmp = node.first;
            
            if (node.second + 1 > minimalLevel) return;
            
            map<string, bool> tmpmap;
            
            for (int i = 0; i < start.length(); i ++) {
                for (int j = 'a'; j <= 'z'; j ++) {
                    if (j != node.first[i]) {
                        tmp[i] = j;
                        
                        if (dict.find(tmp) != dict.end() && !tmpmap[tmp] && (!visited[tmp] || visited[tmp] == node.second + 1)) {
                            if (tmp == end) {
                                if (minimalLevel >= node.second + 1) {
                                    minimalLevel = node.second + 1;   
                                    next[node.first].push_back(tmp);
                                }
                            } else {
                                tmpmap[tmp] = true;
                                visited[tmp] = node.second + 1;
                                q.push(make_pair(tmp, node.second + 1));
                                next[node.first].push_back(tmp);
                            }
                        }
                        
                        tmp[i] = node.first[i];
                    }
                }
            }
        }
        
    }
    
    void output(string start, string end, vector<string> & strs, int level)
    {   
        if (start == end) {
            strs.push_back(start);
            if (level == minimalLevel) {
                ans.push_back(strs);
            }
            return;
        }
        
        strs.push_back(start);
        for (int i = 0; i < next[start].size(); i ++) {
            output(next[start][i], end, strs, level + 1);
            strs.pop_back();
        }
    }


    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        bfs(start, end, dict);
        vector<string> strs;
        ans.clear();
        
        output(start, end, strs, 1);
        
        return ans;
    }
    
};