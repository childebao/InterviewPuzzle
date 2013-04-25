class Solution {
public:
  string minWindow(string S, string T) {
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
          tmphash[S[b]] --;
          
          b ++;
          while (hash[S[b]] == 0) {
            b ++;
          }
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