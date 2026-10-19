#include <bits/stdc++.h>

using namespace std;

// 3**10 = 59'049가지 
int N,K;
int ans;
vector<pair<int,int>> node[101]; // node[i]: i번 노드에서 연결된 것들

int order[10];
int start;

bool vis[101];

void init_vis()
{
    for(int i=1;i<=N;i++)
    {
        vis[i]=0;
    }
}

int cal() // 현재 order 순으로 시뮬돌림
{
    init_vis();
    vis[start] =1;
    
    queue<int> Q;
    
    for(int i=0;i<K;i++)
    {
        int type = order[i];
        
        //방문한 모든 것을 큐에 넣기
        for(int t=1;t<=N;t++)
        {
            if(vis[t]) Q.push(t);
        }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            
            for(int a=0;a<node[now].size();a++)
            {
                int next = node[now][a].first;
                int n_type = node[now][a].second;
                
                if(!vis[next] && n_type == type)
                {
                    vis[next] = 1;
                    Q.push(next);
                }
                else
                {
                    continue;
                }
            }
        }
        
        
    }
    int cnt = 0;
    for(int i=1;i<=N;i++)
    {
        if(vis[i]) cnt++;
    }
    return cnt;
}

void back_tracking(int cnt)
{
    if(cnt == K)
    {
        int num = cal();
        ans = max(ans,num);
        return;
    }
    
    order[cnt] = 1;
    back_tracking(cnt+1);
    
    order[cnt] = 2;
    back_tracking(cnt+1);
    
    order[cnt] = 3;
    back_tracking(cnt+1);
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    start = infection;
    N=n;
    K=k;
    for(int i=0;i<edges.size();i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        int type = edges[i][2];
        node[x].push_back({y,type});
        node[y].push_back({x,type});
    }
    
    back_tracking(0);
    
    return ans;
}