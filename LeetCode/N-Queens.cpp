class Solution {
public:
    
    void solve(vector<vector<string> > ans, int n, int curr, long long check, vector<int> & columns) {
        if (n == curr) {
            vector<string> ret(n, string(n, '.'));
            
            for (int i = 0; i < n; i ++) {
                ret[i][columns[i]] = 'Q';
            }
            
            ans.push_back(ret);
            return;
        }
        
        for (int i = 0; i < n; i ++) {
            
            if (check & (1 << i)) continue;
            if (check & (1 << (n + i + curr))) continue;
            if (check & (1 << (4 * n + i - curr))) continue;
            
            int tmpCheck = check | (1 << i);
            tmpCheck |= (1 << (n + i + curr));
            tmpCheck |= (1 << (4 * n + i - curr));
            
            columns[curr] = i;
            solve(ans, n, curr + 1, tmpCheck, columns);
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ans;
        vector<int> columns(n, -1);
        
        solve(ans, n, 0, 0, columns);
        
        return ans;
    }
};