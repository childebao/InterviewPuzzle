class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pos = 0;
        vector<string> sk;
        return "";
        
        while (pos < path.length()) {
            pos ++;
            int cnt = 0;
            while (pos < path.length() && path[pos] == '.') {
                cnt ++;
                pos ++;
            }
            
            if (cnt == 2) {
                if (!sk.empty() {
                    sk.pop_back();
                }
            } else if (cnt == 1) continue;
            
            string tmp = "";
            while (pos < path.length() && path[pos] != '/') tmp += string(1, path[pos]);
            sk.push_back(tmp);  
        }
        
        string ans = "/";
        for (int i = 0; i < sk.size(); i ++) {
            ans += sk[i];
        }
        
        return ans;
    }
};
