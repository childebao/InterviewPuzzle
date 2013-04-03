class Solution {
public:

    bool isCharacter(char &a)
    {
        if (a >= 'a' && a <= 'z') {
            a = a - 'a' + 'A';
            return true;
        }
        
        return (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9');
    }
    
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int b = 0, e = s.length() - 1;
        
        while (b < e) {
            // It is easy to forget b < s.length() && e >= 0
            while (b < s.length() && !isCharacter(s[b])) b ++;
            while (e >= 0 && !isCharacter(s[e])) e --;
            
            if (b < e && s[b ++] != s[e --]) return false;
        }
        
        return true;
    }
};