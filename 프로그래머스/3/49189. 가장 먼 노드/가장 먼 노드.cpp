#include <bits/stdc++.h>

using namespace std;

int D[20'001];
queue<int> Q;
vector<int> node[20'001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0;i<edge.size();i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        D[i] = INT_MAX;
    }
    D[1]=0;
    Q.push(1);
    
    int tmp = 0;
    while(!Q.empty())
    {
        int now = Q.front();
        int cost = D[now];
        Q.pop();
        tmp = max(tmp, cost);
        for(int i=0;i<node[now].size();i++)
        {
            int next = node[now][i];
            if(D[next]!=INT_MAX) continue;
            D[next] = cost+1;
            Q.push(next);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(D[i]==tmp) answer++;
    }
    return answer;
}