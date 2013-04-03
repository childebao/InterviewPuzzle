class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> ans(1, 1);
        
        rowIndex ++; //rowIndex is zero based, convert it to 1 based...
        
        while(--rowIndex) {
            ans.push_back(1);
            for (int i = ans.size() - 2; i > 0; i --) {
                ans[i] += ans[i - 1];
            }
        }
        
        return ans;
    }
};