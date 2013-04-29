/**
 Implement regular expression matching with support for '.' and '*'.
 
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") ? false
 isMatch("aa","aa") ? true
 isMatch("aaa","aa") ? false
 isMatch("aa", "a*") ? true
 isMatch("aa", ".*") ? true
 isMatch("ab", ".*") ? true
 isMatch("aab", "c*a*b") ? true
*/

bool couldMatch[200][200];
bool caled[200][200];

class Solution {
public:
    /**
     * Is pattern p[po..] matches string s[so..] or not ?
     * Use memorization and dynamic programming approach
     */
    bool getIsMatch(const string& s, const string& p, int so, int po)
    {
        if (caled[so][po]) return couldMatch[so][po];
        caled[so][po] = true;
        
        bool & ret = couldMatch[so][po];
        ret = false;
        
        // pattern and input string are both empty, aka, great
        if (so == s.length() && po == p.length()) return ret = true;
        // otherwise, if pattern is emtpy, we still have jobs to match input string, failed
        if (po == p.length()) return ret = false;
        // be careful, when input string s is all matched, we still need to look at pattern,
        // if remain pattern could match empty string, it is ok
        
        if (so < s.length())
        {
            // if current character matches pattern character, go on
            if (s[so] == p[po]) ret |= getIsMatch(s, p, so + 1, po + 1);
            // if pattern character is ., we could match any character
            if (p[po] == '.') ret |= getIsMatch(s, p, so + 1, po + 1);
            // if current character is *
            if (p[po] == '*')
            {
                // match previous character once or could match more
                if (p[po - 1] == s[so] || p[po - 1] == '.')
                    ret |= getIsMatch(s, p, so + 1, po);
            }
        }
        
        // if current character is *, could match empty
        if (p[po] == '*') ret |= getIsMatch(s, p, so, po + 1);
        
        // if next character is *, be careful!!, we could skip these two character in pattern, because * could match zero times
        if (po + 1 < p.length() && p[po + 1] == '*')
            ret |= getIsMatch(s, p, so, po + 2);
        
        return ret;
    }
    
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ss(s);
        string pp(p);
        memset(caled, false, sizeof(caled));
        
        return getIsMatch(ss, pp, 0, 0);
    }
};