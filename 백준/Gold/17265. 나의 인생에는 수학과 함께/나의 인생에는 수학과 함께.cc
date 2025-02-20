#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
char board[5][5];
bool vis[10][10];

int min_ = INT_MAX;
int max_ = INT_MAX + 1;
void backTracking(int r, int c)
{
    if (r >= N || c >= N) return;
    if (r == N - 1 && c == N - 1)
    {
        char cal = '+';
        int save = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (vis[i][j])
                {
                    if (board[i][j] >= '0' && board[i][j] <= '5')
                    {
                        if (cal == '+')
                        {
                            save += board[i][j] - 48;
                        }
                        if (cal == '*')
                        {
                            save *= board[i][j] - 48;
                        }
                        if (cal == '-')
                        {
                            save -= board[i][j] - 48;
                        }
                    }
                    else cal = board[i][j];
                }
            }
        }
        min_ = min(min_, save);
        max_ = max(max_, save);
        return;
    }

    vis[r + 1][c] = true;
    backTracking(r + 1, c);
    vis[r + 1][c] = false;

    vis[r][c + 1] = true;
    backTracking(r, c + 1);
    vis[r][c + 1] = false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    char c;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    vis[0][0] = true;
    backTracking(0, 0);

    cout << max_ << '\n' << min_;
    return 0;
}