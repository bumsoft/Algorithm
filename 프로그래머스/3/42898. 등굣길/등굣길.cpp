#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool board[101][101];
ll dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    
    for(int i=0;i<puddles.size();i++)
    {
        int mm = puddles[i][0];
        int nn = puddles[i][1];
        board[nn][mm] = 1;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(board[i][j]) continue;
            if(i == 1)
            {
                if(j==1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i][j-1]%1'000'000'007;
                }
            }
            else
            {
                if(j==1)
                {
                    dp[i][j] = dp[i-1][j]%1'000'000'007;
                }
                else
                {
                    ll up = dp[i-1][j];
                    ll left = dp[i][j-1];
                    if(!up && !left) dp[i][j] = 0;
                    else if(!up) dp[i][j] = left;
                    else if(!left) dp[i][j]= up;
                    else dp[i][j] = (up+left)%1'000'000'007;
                }
            }
        }
    }
    return dp[n][m];
}