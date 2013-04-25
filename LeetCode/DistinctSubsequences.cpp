class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > dp(S.length() + 1, vector<int>(T.length() + 1, 0));
        
        for (int i = 0; i <= S.length(); i ++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= T.length(); i ++) {
            for (int j = 1; j <= S.length(); j ++) {
                dp[j][i] = dp[j - 1][i];
                if (S[j - 1] == T[i - 1]) {
                    dp[j][i] += dp[j - 1][i - 1];
                }
            }
        }
        
        /*
        // We can also change the computing sequence as following:
        for (int i = 1; i <= S.length(); i ++) {
            for (int j = 1; j <= T.length(); j ++) {
                dp[i][j] = dp[i - 1][j];
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        */
        
        return dp[S.length()][T.length()];
    }
};