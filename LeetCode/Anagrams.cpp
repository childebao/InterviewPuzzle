/**
 Given an array of strings, return all groups of strings that are anagrams.

 Note: All inputs will be in lower-case.
 */

class Solution {
public:
    string getAnagram(string s) {
        sort(s.begin(), s.end());
        return s;
    }
    
    // Another solution using map
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        
        map<string, vector<string> > mp;
        
        for (int i = 0; i < strs.size(); i ++) {
            mp[getAnagram(strs[i])].push_back(strs[i]);
        }
        
        for (map<string, vector<string> >::iterator it = mp.begin(); it != mp.end(); it ++) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); i ++) {
                    ans.push_back(it->second[i]);
                }
            }
        }
        
        return ans;
    }
};