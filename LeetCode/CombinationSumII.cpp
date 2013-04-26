class Solution {
public:
    vector<vector<int> > ans;
    
    void dfs(vector<int> &curr, int target, int pos, vector<int> &num) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        int pre = -1;
        for (int i = pos; i < num.size(); i ++) {
            if (target < num[i]) return;
            if (pre == num[i]) continue;
            
            pre = num[i]; // Easy to forget
            curr.push_back(num[i]);
            dfs(curr, target - num[i], i + 1, num);
            curr.pop_back();
        }
    }  
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        ans.clear();
        if (num.size() <= 0) return ans;
        
        sort(num.begin(), num.end());
        vector<int> curr;
        dfs(curr, target, 0, num);
        
        return ans;
    }
};