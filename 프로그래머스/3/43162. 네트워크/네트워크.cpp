#include <bits/stdc++.h>

using namespace std;

bool vis[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        answer++;
        cout<<i<<'\n';
        vis[i] = 1;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int t=0;t<computers[now].size();t++)
            {
                if(computers[now][t] != 1) continue;
                if(vis[t]) continue;
                vis[t] =1;
                Q.push(t);
            }
        }
        
    }
    
    return answer;
}