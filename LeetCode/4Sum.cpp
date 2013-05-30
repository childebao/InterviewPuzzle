/**
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:

 Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ? b ? c ? d)
 The solution set must not contain duplicate quadruplets.
     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

     A solution set is:
     (-1,  0, 0, 1)
     (-2, -1, 1, 2)
     (-2,  0, 0, 2)
 */
 
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ans;
        
        if (num.size() < 4) return ans;
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size(); i ++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            
            for (int j = num.size() - 1; j > i + 2; j --) {
                if (j < num.size() - 1 && num[j] == num[j + 1]) continue;
                
                int tmpTarget = target - num[i] - num[j];
                
                int b = i + 1, e = j - 1;
                while (b < e) {
                    int sum = num[b] + num[e];
                    if (sum > tmpTarget) {
                        e --;
                    } else if (sum < tmpTarget) {
                        b ++;
                    } else {
                        vector<int> n;
                        n.push_back(num[i]);
                        n.push_back(num[b ++]);
                        n.push_back(num[e --]);
                        n.push_back(num[j]);
                        ans.push_back(n);
                                                
                        while (b < e && num[b] == num[b - 1]) b ++;
                    }
                    
                }
            }
        }
        
        return ans;
    }
};