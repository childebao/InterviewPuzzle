class Solution {
public:
    vector<vector<string> > ans;
    
    void bitmapSolve(int n, int curr, int checkCols, int checkDiag1, int checkDiag2, vector<int> & columns) {
        if (n == curr) {
            vector<string> ret(n, string(n, '.'));
            
            for (int i = 0; i < n; i ++) {
                ret[i][columns[i]] = 'Q';
            }
            
            ans.push_back(ret);
            return;
        }
        
        for (int i = 0; i < n; i ++) {
            if (checkCols & (1 << i)) continue;
            if (checkDiag1 & (1 << (i + curr))) continue;
            if (checkDiag2 & (1 << (n + i - curr))) continue;
            
            long long tmpCheck = checkDiag2;
            tmpCheck |= (1 << (n  + i - curr));
            
            columns[curr] = i;
            solve(n, curr + 1, checkCols | (1 << i), checkDiag1 | (1 << (i + curr)), checkDiag2 | (1 << (n  + i - curr)), columns);
        }
    }
    
    void solve(int n, int curr, vector<bool> & check, vector<int> & columns) {
        if (n == curr) {
            vector<string> ret(n, string(n, '.'));
            
            for (int i = 0; i < n; i ++) {
                ret[i][columns[i]] = 'Q';
            }
            
            ans.push_back(ret);
            return;
        }
        
        for (int i = 0; i < n; i ++) {
            if (check[i]) continue;
            if (check[n + i + curr]) continue;
            if (check[4 * n + i - curr]) continue;
            
            check[i] = true;
            check[n + i + curr] = true;
            check[4 * n + i - curr] = true;
            columns[curr] = i;
            
            solve(n, curr + 1, check, columns);
            
            // backtracking
            check[i] = false;
            check[n + i + curr] = false;
            check[4 * n + i - curr] = false;
        }
    }
    
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        
        vector<int> columns(n, -1);
        vector<bool> check(6 * n, false);
        
        solve(n, 0, check, columns);
        
        return ans;
    }
};