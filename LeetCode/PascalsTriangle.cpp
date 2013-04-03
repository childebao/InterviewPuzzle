class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans(numRows, vector<int>(1, 1));
        
        for (int i = 1; i < numRows; i ++) {
            for (int j = 1; j < i; j ++) {
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans[i].push_back(1);
        }
        
        return ans;
    }
};