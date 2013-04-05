class Solution {
public:
    vector<vector<int> > ans;
    
    void combinationSubSum(const vector<int> &candidates, int index, int target, vector<int> &curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        if (index >= candidates.size()) return;
        
        for (int i = index; i < candidates.size(); i ++) {
            if (candidates[i] > target) return;
            
            int cnt = target / candidates[i];
            
            for (int j = 0; j < cnt; j ++) {  // You always use int i even here...
                curr.push_back(candidates[i]);
                combinationSubSum(candidates, i + 1, target - (j + 1) * candidates[i], curr);
            }
            
            for (int j = 0; j < cnt; j ++) {
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        combinationSubSum(candidates, 0, target, curr);
        return ans;
    }
};