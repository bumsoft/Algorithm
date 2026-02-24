#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[1'000'001];

//2) DP
void sol(int x, int y, int n)
{
    dp[x] = 0;
    for(int i=x;i<=y;i++)
    {
        if(i-n < x) continue;
        
        ll min_n = dp[i-n] != -1 ? dp[i-n] : INT_MAX;
        ll div2 = dp[i/2] != -1 ? dp[i/2] : INT_MAX;
        ll div3 = dp[i/3] != -1 ? dp[i/3] : INT_MAX;
        
        if(i%2 == 0 && i%3 == 0)
        {
            dp[i] = 1 + min(min_n, min(div2, div3));
        }
        else if(i%2==0)
        {
            dp[i] = 1 + min(min_n, div2);
        }
        else if(i%3==0)
        {
            dp[i] = 1 + min(min_n, div3);
        }
        else
        {
            dp[i] = 1 + min_n;
        }
        if(dp[i] > INT_MAX) dp[i] = -1;
    }
}

int solution(int x, int y, int n) {
    for(int i=0;i<=y;i++)
        dp[i] = -1;
    
    sol(x,y,n);

    return dp[y];
}