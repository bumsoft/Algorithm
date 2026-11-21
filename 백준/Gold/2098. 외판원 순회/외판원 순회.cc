#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
int cost[20][20];

ll dp[1<<17][17]; // dp[i][j] : 상태 i에서 j노드일 때, 원점까지의 비용

ll dfs(int state, int now)
{
    if(dp[state][now] != -1) return dp[state][now];
    
    if(state == (1<<N)-1) //모든 도시 방문함
    {
        if(cost[now][0] == 0) return dp[state][now] = INT_MAX;
        return dp[state][now] = cost[now][0];
    }
    dp[state][now] = INT_MAX;
    for(int i=0;i<N;i++)
    {
        if((state & (1<<i)) != 0) continue; //i노드 방문했으면 pass
        ll next_cost = cost[now][i];
        if(next_cost == 0) continue;
        dp[state][now] = min(dp[state][now], dfs(state | (1<<i), i) + next_cost);
    }
    return dp[state][now];
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
             cin>>cost[i][j];
        }
    }
    for(int i=0;i<(1<<N);i++)
    {
        for(int j=0;j<N;j++)
            dp[i][j] = -1;
    }
    //원형이라 어차피 시작점은 아무데나 상관 X
    dfs(1<<0, 0);

   
    cout<<dp[1<<0][0];
    return 0;
}