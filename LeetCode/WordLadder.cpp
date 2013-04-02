class Solution {
public:
    int bfs(string start, string end, unordered_set<string> &dict)
    {
        map<string, bool> visited;
        visited[start] = true;
        
        queue<pair<string, int> >q;
        q.push(make_pair(start, 1));
        
        while (!q.empty()) {
            pair<string, int> node = q.front();
            q.pop();
            string tmp = node.first;
            
            if (node.first == end) return node.second;
            
            for (int i = 0; i < start.length(); i ++) {
                for (int j = 'a'; j <= 'z'; j ++) {
                    if (j != node.first[i]) {
                        tmp[i] = j;
                        
                        if (dict.find(tmp) != dict.end() && !visited[tmp]) {
                            visited[tmp] = true;
                            q.push(make_pair(tmp, node.second + 1));
                        }
                        
                        tmp[i] = node.first[i];
                    }
                }
            }
        }
        
        return 0;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start.length() != end.length()) return 0;
        
        return bfs(start, end, dict);
    }
};