class Solution {
public:
    vector<int> ans;
    
    
    void reverse(string &s) {
        int b = 0, e = s.length() - 1;
        while (b < e) swap(s[b ++], s[e --]);
    }
    
    void mutiplySingleNum(const string &num, int n) {
        if (n == 0) return;
        
        for (int i = 0; i < num.length(); i ++) {
            ans[i] += (num[i] - '0') * n;
        }
    }
    
    string getAnswerString() {
        int delta = 0;
        
        for (int i = 0; i < ans.size(); i ++) {
            ans[i] += delta;
            delta = ans[i] / 10;
            ans[i] %= 10;
        }
        
        while (delta > 0) {
            ans.push_back(delta % 10);
            delta /= 10;
        }
        
        while (ans.back() == 0) ans.pop_back();
        
        string ret = "";
        for (int i = ans.size() - 1; i >= 0; i --) {
            ret += string(1, ans[i] + '0');
        }
        
        // Remember, the 0 case...
        if (ret.length() == 0) ret = "0";
        
        return ret;
    }
    
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.assign(num1.length() + num2.length() + 1, 0);
        
        reverse(num1);
        reverse(num2);
        
        for (int i = 0; i < num2.length(); i ++) {
            mutiplySingleNum(num1, num2[i] - '0');
            
            num1 = string(1, '0') + num1;
        }
        
        return getAnswerString();
    }
};