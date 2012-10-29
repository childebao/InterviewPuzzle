#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

const int moder = 1000000007;

struct State
{
    int score;

    bool strike1;
    bool strike2;
    bool spare;

    State()
    {
        score = 0;
        strike1 = strike2 = spare = false;
    }

    State(int _score, bool s1, bool s2, bool s)
    {
        score = _score;
        strike1 = s1;
        strike2 = s2;
        spare = s;
    }

    friend ostream& operator <<(ostream& out, const State& s)
    {
        out << "score = " << s.score << " " << s.strike1 << " " << s.strike2 << " " << s.spare << endl;
        return out;
    }

    vector<State> getNextState()
    {
        vector<State> ret;

        // strike for this frame
        State newS = *this;
        newS.score += 10;
        if (strike1 || spare)
            newS.score += 10;
        if (strike2)
            newS.score += 10;
        newS.strike2 = strike1;
        newS.strike1 = true;
        newS.spare = false;
        ret.push_back(newS);

        for (int a = 0; a <= 9; ++a)
        {
            for (int b = 0; b <= 10 - a; ++b)
            {
                State newS = *this;
                newS.score += (a + b);
                if (strike1)
                    newS.score += (a + b);
                if (strike2)
                    newS.score += a;
                if (spare)
                    newS.score += a;
                newS.strike2 = false;
                newS.strike1 = false;
                newS.spare = (a + b == 10);
                ret.push_back(newS);
            }
        }
        return ret;
    }
};

int f[101][3001][2][2][2];

void init()
{
    memset(f, 0, sizeof(f));
    f[0][0][0][0][0] = 1;
    for (int i = 0; i <= 99; ++i)
        for (int j = 0; j <= 30 * i; ++j)
            for (int s1 = 0; s1 < 2; ++s1)
                for (int s2 = 0; s2 < 2; ++s2)
                    for (int s = 0; s < 2; ++s)
                    {
                        if (f[i][j][s1][s2][s] != 0)
                        {
                            State curS(j, s1, s2, s);
                            vector<State> newS = curS.getNextState();
                            for (unsigned int k = 0; k < newS.size(); ++k)
                            {
                                f[i + 1][newS[k].score][newS[k].strike1][newS[k].strike2][newS[k].spare] += f[i][j][s1][s2][s];
                                f[i + 1][newS[k].score][newS[k].strike1][newS[k].strike2][newS[k].spare] %= moder;
                            }
                        }
                    }

}

int main()
{
    init();
    //cout << "mie" << endl;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N, M;
        scanf("%d%d", &N, &M);

        int ans = 0;
        ans += f[N][M][0][0][0];
        ans %= moder;

        // deal with last one spare
        for (int x = 0; x <= 10; ++x)
            if (M - x >= 0)
            {
                ans += f[N][M - x][0][0][1];
                ans %= moder;
            }
        //cout << ans << endl;

        // deal with last one strike
        for (int x = 0; x <= 10; ++x)
        {
            for (int y = 0; y <= 10; ++y)
            {
                if (x != 10 && x + y > 10)
                    continue;
                if (M - x - y >= 0)
                {
                    ans += f[N][M - x - y][1][0][0];
                    ans %= moder;
                }
            }
        }
        //cout << ans << endl;

        // deal with last two strike
        for (int x = 0; x <= 10; ++x)
        {
            for (int y = 0; y <= 10; ++y)
            {
                if (x != 10 && x + y > 10)
                    continue;
                if (M - x - x - y >= 0)
                {
                    ans += f[N][M - x - x - y][1][1][0];
                    ans %= moder;
                }
            }
        }

        //cout << ans << endl;

        printf("%d\n", ans);
    }
    return 0;
}