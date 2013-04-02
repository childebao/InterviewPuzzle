class Solution {
public:

    map<string, vector<string> > next;
    vector<vector<string> > ans;
    
    void bfs(string start, string end, unordered_set<string> &dict)
    {
        map<string, bool> visited;
        visited[start] = true;
        next.clear();
        
        queue<pair<string, int> >q;
        q.push(make_pair(start, 1));
        
        int minimalLevel = dict.size();
        
        while (!q.empty()) {
            
            pair<string, int> node = q.front();
            q.pop();
            string tmp = node.first;
            
            if (node.first == end) {
                minimalLevel = node.second;
            }
            
            if (node.second + 1 > minimalLevel) return;
            
            for (int i = 0; i < start.length(); i ++) {
                for (int j = 'a'; j <= 'z'; j ++) {
                    if (j != node.first[i]) {
                        tmp[i] = j;
                        
                        if (dict.find(tmp) != dict.end() && !visited[tmp]) {
                            visited[tmp] = true;
                            q.push(make_pair(tmp, node.second + 1));
                            next[node.first].push_back(tmp);
                        }
                        
                        tmp[i] = node.first[i];
                    }
                }
            }
        }
        
    }
    
    void output(string start, string end, vector<string> & strs)
    {
        if (start == end) {
            strs.push_back(start);
            ans.push_back(strs);
            return;
        }
        
        strs.push_back(start);
        for (int i = 0; i < next[start].size(); i ++) {
            output(next[start][i], end, strs);
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
        
        output(start, end, strs);
        
        return ans;
    }
    
};