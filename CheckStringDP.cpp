//if the dictionary has str, return true, otherwise, false
bool hasWord(const string &str);

//DP: check if string s could be formed with those words in the dictionary
bool checkString(const string &s)
{
  int N = s.length();
  vector<bool> isOK(N, false);
  
  for (int i = 0; i < N; i ++) {
    isOK[i] = hasWord(s.subStr(0, i + 1));
    
    if (isOK[i]) continue;
    
    for (int j = 0; j < i; j ++) {
      if (isOK[j] && hasWord(s.subStr(j + 1, i - j))) {
        isOK[i] = true;
        break;
      }
    }
  }
  
  return isOK[N - 1];
}