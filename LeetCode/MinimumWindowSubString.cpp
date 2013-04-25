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
    
    // Charlene's implementation
    string minWindow2(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans = "";
    
        vector<int> hash(256, 0), tmphash(256, 0);
        int count = 0;
        for (int i = 0; i < T.length(); i ++) {
            if (hash[T[i]] == 0) count ++;
            hash[T[i]] ++;
        }
    
        int b = 0, tmpCount = 0;
    
        while (b < S.length() && hash[S[b]] == 0) b ++;
    
        for (int i = b; i < S.length(); i ++) {
            tmphash[S[i]] ++;
      
            if (hash[S[i]] > 0 && tmphash[S[i]] == hash[S[i]]) {
                tmpCount ++;
            } 
      
            if (tmpCount == count) {
                while (hash[S[b]] > 0 && tmphash[S[b]] > hash[S[b]]) {
                    tmphash[S[b ++]] --;
          
                    while (hash[S[b]] == 0) b ++;
                }
            
                if (ans.length() == 0 || i - b + 1 <= ans.length()) {
                    ans = S.substr(b, i - b + 1);
                }
            
                for (int j = b; j <= i; j ++) {
                    tmphash[S[j]] --;
          
                    if (hash[S[j]] > 0) {
                        if (tmphash[S[j]] < hash[S[j]]) tmpCount --;
            
                        b = j + 1;
            
                        while (b < S.length() && hash[S[b]] == 0) b ++;
                
                        break;
                    }
                }
            } 
        }
    
        return ans;
    }
};
