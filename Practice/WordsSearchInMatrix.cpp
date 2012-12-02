/*
 Here you have a matrix size is 4*4
 each element in matrix is a 'a' - 'z' character
 for e.g.
 
 a b d e
 b d o g
 x y z z
 z z z x
 
 and you have only one function 
 
 int isWord(const string& str)
 {
 return 1; /// if str is exactly a word
 return 2; /// if str is a prefix of some word
 return 3; /// if str is exactly a word and it is a prefix of some word
 return 0; /// if str is not a word nor a prefix of a word
 }
 
 now , you should find all the words that could be find in the matrix
 a word that can be found in the matrix is defined as you can start from one element in the matrix
 and walk as a path, and no duplicated words or elements. 
 for e.g. you can find d->o->g in the e.g.
 
 
 Hint:
 using depth first search and backtracking to deal with the searching starting from each entry.
 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

int isWord(const string &str)
{
  return rand() % 4;
}

set<string> words;

char matrix[4][4];
bool flag[4][4];
int xp[4] = {1, 0, -1, 0};
int yp[4] = {0, 1, 0, -1};

bool isValid(int x, int y)
{
  if (x >= 0 && x < 4 && y >= 0 && y < 4 && !flag[x][y]) return true;
  return false;
}

void dfs(int x, int y, string w)
{
  switch (isWord(w)) {
    case 0:
      return;
    case 1:
      words.insert(w);
      return;
    case 3:
      words.insert(w);
      break;
    default:
      break;
  }
  
  int curX, curY;
  for (int i = 0; i < 4; i ++) { 
    curX = x + xp[i];
    curY = y + yp[i];
    if (isValid(curX, curY)) {
      flag[curX][curY] = true;
      dfs(curX, curY, w + matrix[x][y]); //// 
      flag[curX][curY] = false;
    }
  }
}

void deal()
{
  for (int i = 0; i < 4; i ++) {
    for (int j = 0; j < 4; j ++) {
      memset(flag, false, sizeof(flag));
      flag[i][j] = true;
      dfs(i, j, string(1, matrix[i][j])); //should use string(1, a char)
    }
  }
  
  for (set<string>::iterator itr = words.begin(); itr != words.end(); ++itr)
    cout << *itr << endl;
}

int main()
{
  words.clear();
  
  for (int i = 0; i < 4; i ++) 
    for (int j = 0; j < 4; j ++) 
      cin >> matrix[i][j];
  
  deal();
  
  return 0;
}