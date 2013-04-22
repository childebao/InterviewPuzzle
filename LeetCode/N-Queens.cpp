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




/* 
// Another implementation

typedef Int64 uint64_t;

class Solution {
public:
    vector<vector<string> > ans;
    
    bool check(int n, int r, int c, uint64_t flag, uint64_t & ret)
    {
        int result = true;
        if (flag & (1 << c)) result = false;
        if (flag & (1 << (n + r + c))) result = false;
        if (flag & (1 << (4 * n + r - c))) result = false;
        
        if (result) {
            ret = flag;
            ret |= (1 << c);
            ret |= (1 << (n + r + c));
            ret |= (1 << (4 * n + r - c));
        }
        
        return result;
    }
    
    void bitSolve(int n, int curr, uint64_t flag, vector<int> & columns) {
        if (n == curr) {
            vector<string> ret(n, string(n, '.'));
            
            for (int i = 0; i < n; i ++) {
                ret[i][columns[i]] = 'Q';
            }
            
            ans.push_back(ret);
            return;
        }
        
        uint64_t newFlag;
        for (int i = 0; i < n; i ++) {
            if (!check(n, curr, i, flag, newFlag)) continue;
    
            columns[curr] = i;
            bitSolve(n, curr + 1, newFlag, columns);
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        
        vector<int> columns(n, -1);
        
        bitSolve(n, 0, 0, columns);
        
        return ans;
    }
};

 */