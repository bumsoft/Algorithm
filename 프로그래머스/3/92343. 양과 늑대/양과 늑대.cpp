#include <bits/stdc++.h>

using namespace std;

vector<int> tree[18];
int N;
int dp[1 << 18];
vector<int> info;

int dfs(int state)
{
    if(dp[state] != -1) return dp[state];
    
    int sheep = 0; int wolf = 0;
    for(int i=0;i<N;i++)
    {
        if((state & (1<<i)) == 0) continue;
        if(info[i]==0) sheep++;
        else wolf++;
    }
    if(sheep <= wolf) return dp[state] = 0;
    
    dp[state] = sheep; //state 상태에서 모은 양 수 일단 저장
    
    for(int i=0;i<N;i++)
    {
        if((state & (1<<i)) == 0) continue;
        for(int j=0;j<tree[i].size();j++)
        {
            int next_node = tree[i][j];
            if((state & (1<<next_node)) != 0) continue; //지금 보는자식이 이미 포함됐다면 pass
            dp[state] = max(dp[state], dfs(state | (1<<next_node))); //next_node 포함해서 dfs
        }
    }
    return dp[state];
}

int solution(vector<int> ii, vector<vector<int>> edges) {
    int answer = 0;
    info = ii;
    N = info.size();
    for(int i=0;i<(1<<N);i++)
    {
        dp[i] = -1;
    }
    for(int i=0;i<edges.size();i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        tree[a].push_back(b);
    }
    
    answer = dfs(1);
    
    
    return answer;
}