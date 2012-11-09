#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>

using namespace std;

int minLen = 1;
int val = 1;

string mg(char a, char b) {
    if (a == 'a') {
        return b == 'b' ? "c" : "b";
    }
    
    if (a == 'b') {
        return b == 'a' ? "c" : "a";
    }
    
    return b == 'a' ? "b" : "a";
}

bool deal(string str, int len)
{
    minLen = len;
    
    if (len == 1 || (len == 2 && str[0] == str[1])) {
        val = len;
        return true;
    }
    
    for (int i = 0; i < len - 1; i ++) {
        if (str[i] != str[i + 1]) {
            
            string two = mg(str[i], str[i + 1]);
            string tmpStr = "";
            
            for (int j = 0; j < i; j ++) {
                tmpStr += str[j];
            }
            tmpStr += two;
            for (int j = i + 2; j < len; j ++) {
                tmpStr += str[j];
            }

            bool stop = deal(tmpStr, tmpStr.length());
            if (stop) {
                minLen = minLen > val ? val : minLen;
                return true;
            }
            
        }
    }
    
    return false;
}

int main ()
{
    int t;
    
    cin >> t;
    for (int cases = 0; cases < t; cases ++) {
        string str;
        cin >> str;
        
        int len = str.length();
        
        deal(str, len);
        cout << minLen << endl;
    }
    
    return 0;
}