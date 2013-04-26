class Solution {
public:

    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        int left = 0, right = 0, start = 0;
        
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(') left ++;
            else right ++;
            
            if (right > left) {
                right = left = 0;
                start = i + 1;
            } else if (right == left) {
                ans = max(ans, left + right);  
            }
        }

        if (left > right) {
            left = right = 0;
            start = s.length() - 1;
            for (int i = s.length() - 1; i >= 0; i --) {
                if (s[i] == ')') right ++;
                else left ++;
                
                if (left > right) {
                    right = left = 0;
                    start = i - 1;
                } else if (left == right) {
                    ans = max(ans, left + right);
                }
            }
        }
        
        return ans;
    }
};