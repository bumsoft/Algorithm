#include <bits/stdc++.h>

using namespace std;

// A에서 모든 노드까지 최소비용 구함
// B에서 모든 노드까지 최소비용 구함
// S에서 모든 노드까지 최소비용 구함

// A는 다른 각 노드 i에 대해 다음을 수행함
// - (A~i 비용 + B~i 비용 + S~i 비용) 계산. ans와 비교하여 갱신
// i:4 35 + 66 + 0
// i:1 25 + 63 + 10
// i:5 2 + 46 + 34

int D[3][201];

vector<pair<int,int>> vertex[201]; // <노드, 비용>

void init(int n, int type)
{
    for(int i=1; i<=n;i++)
    {
        D[type][i]=INT_MAX;
    }
}

void dijkstra(int n, int start, int type)
{
    init(n, type);
    D[type][start]=0;
    priority_queue<pair<int,int>> PQ; // <cost, node>
    PQ.push({0,start});
    
    while(!PQ.empty())
    {
        int now = PQ.top().second;
        int cost = -PQ.top().first;
        PQ.pop();
        
        if(cost != D[type][now]) continue;
        for(int i=0;i<vertex[now].size();i++)
        {
            int next_ver = vertex[now][i].first;
            int next_cost = cost + vertex[now][i].second;
            if(next_cost >= D[type][next_ver]) continue;
            D[type][next_ver] = next_cost;
            PQ.push({-next_cost, next_ver});
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    for(int i=0;i<fares.size();i++)
    {
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2];
        vertex[c].push_back({d,f});
        vertex[d].push_back({c,f});
    }
    dijkstra(n,s,0);
    dijkstra(n,a,1);
    dijkstra(n,b,2);

    for(int i=1;i<=n;i++)
    {
        if(D[0][i] == INT_MAX || D[1][i]==INT_MAX || D[2][i]==INT_MAX) continue;
        answer = min(D[0][i] + D[1][i] + D[2][i], answer);
    }
    
    return answer;
}









