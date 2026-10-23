#include <bits/stdc++.h>
#define INF INT_MAX;

using namespace std;

// 번호는 1~N

vector<pair<int,int>> vertex[51]; // 0 사용 x, 1~50 <번호, 거리>
priority_queue<pair<int,int>> PQ; // <시작점부터 거리, 번호>
int D[51]; //D[i]: 시작 ~ i까지의 거리

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i=0;i<road.size();i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        vertex[a].push_back({b,c});
        vertex[b].push_back({a,c});   
    }
    
    for(int i=1;i<=N;i++) D[i] = INF;
    D[1] = 0;
    PQ.push({0,1});
    
    while(!PQ.empty())
    {
        int now = PQ.top().second;
        int cost = -PQ.top().first;
        PQ.pop();
        
        if(cost != D[now]) continue;
        for(int i=0;i<vertex[now].size();i++)
        {
            int next_ver = vertex[now][i].first;
            int next_cost = vertex[now][i].second + cost;
            if(next_cost >= D[next_ver]) continue;
            D[next_ver] = next_cost;
            PQ.push({-next_cost, next_ver});
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(D[i]<=K) answer++;
    }
    

    return answer;
}