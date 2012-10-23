#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/// 8 Quene Puzzle
const int N = 8;
bool columnUsed[N];
bool diagonalUsed1[N * 2 - 1];
bool diagonalUsed2[N * 2 - 1];
int columnPosiForRow[N];
int ans;

void output()
{
  ans++;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
      if (columnPosiForRow[i] == j)
        cout << "*";
      else
        cout << "-";
    cout << endl;
  }
  cout << endl;
}

void search(int curRow)
{
  if (curRow == N)
    return output();
  
  for (int c = 0; c < N; ++c)
  {
    if (!columnUsed[c] && !diagonalUsed1[c + curRow] && !diagonalUsed2[c - curRow + N - 1])
    {
      columnUsed[c] = diagonalUsed1[c + curRow] = diagonalUsed2[c - curRow + N - 1] = true;
      columnPosiForRow[curRow] = c;
      search(curRow + 1);
      columnUsed[c] = diagonalUsed1[c + curRow] = diagonalUsed2[c - curRow + N - 1] = false;
    }
  }
}

int main()
{
  ans = 0;
  search(0);
  cout << "Total = " << ans << endl;
}