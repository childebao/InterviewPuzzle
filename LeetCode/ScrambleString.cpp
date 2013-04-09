class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() funct
        vector<vector<int> > ans;
        
        if (num.size() <= 2) return ans;
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size() - 2; i ++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
    
            int target = 0 - num[i];
            int b = i + 1, e = num.size() - 1;
            while (b < e) {
                int tmp = num[b] + num[e];
                if (tmp < target) {
                    b ++;
                } else if (tmp > target) {
                    e --;
                } else {
                    vector<int> ret(3, 0 - target);
                    ret[1] = num[b ++];
                    ret[2] = num[e --];
                    ans.push_back(ret);
                    // Remove duplicated pairs...
                    while (b < num.size() && num[b] == num[b - 1]) b ++;
                    while (e > b && num[e] == num[e + 1]) e --;
                }
            }
        }
    }
};