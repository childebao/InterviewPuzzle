/**
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */
class Solution {
public:
    // O(N * logN)
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        set<pair<int, int> > s;
        for (int i = 0; i < numbers.size(); i ++) {
            s.insert(make_pair(numbers[i], i + 1));
        }
        
        set<pair<int, int> >::iterator itb = s.begin(), ite = --s.end();
        
        while (itb != ite) {
            int sum = itb->first + ite->first;
            
            if (sum == target) {
                ans.push_back(itb->second);
                ans.push_back(ite->second);
                if (ans[0] > ans[1]) swap(ans[0], ans[1]);
                return ans;
            } else if (sum < target) {
                ++itb;
            } else {
                --ite;
            }
        }
        
        return ans;
    }
    
    // O(N * N)
    vector<int> twoSum2(vector<int> &numbers, int target) {
        // clear, self-descript code is always welcome!
        vector<int> ans;
        
        for (int i = 0; i < numbers.size() - 1; i ++) {
            for (int j = i + 1; j < numbers.size(); j ++) {
                if (numbers[i] + numbers[j] == target) {
                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};
