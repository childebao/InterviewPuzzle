class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() <= 1) return 0;
        
        int ans = 0, curr = 0;
        
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[curr] < prices[i]) {
                ans += prices[i] - prices[curr];
                curr = i;
            }
            
            curr = i;
        }
        
        return ans;
    }
};