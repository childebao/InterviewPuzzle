class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
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