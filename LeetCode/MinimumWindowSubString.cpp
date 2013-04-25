class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // calculate character occurance in T
        vector<int> tCnt(256, 0);
        vector<int> sCnt(256, 0);
        for (int i = 0; i < T.length(); ++i)
            tCnt[T[i]]++;
        
        // get number of different characters
        int diffChars = 0;
        for (int i = 0; i < tCnt.size(); ++i)
            if (tCnt[i] > 0) diffChars++;
        
        // [l, r] is located the current string in S that satisfied T
        int satisfiedChars = 0;
        int l = 0, r = -1;
        int minLen = (int) S.length() + 1;
        int minOffset = -1;
        int LS = (int) S.length();
        
        while (l < LS)
        {
            // find [l, r] satisfied the condition
            while (satisfiedChars < diffChars && r + 1 < LS)
            {
                sCnt[S[++r]]++;
                if (sCnt[S[r]] == tCnt[S[r]]) satisfiedChars++;
            }
            // could not satisfied, return
            if (satisfiedChars < diffChars) break;
            
            // try to push l to right as far as we can
            while (l < r && sCnt[S[l]] > tCnt[S[l]])
                sCnt[S[l++]]--;
            
            // update best answer
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                minOffset = l;
            }
            
            // push l to right
            sCnt[S[l++]]--;
            satisfiedChars--;
        }
        
        return minOffset == -1 ? "" : S.substr(minOffset, minLen);
    }
};
