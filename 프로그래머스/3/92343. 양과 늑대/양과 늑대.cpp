#include <bits/stdc++.h>

using namespace std;

vector<int> tree[18];
vector<int> info;

bool vis[18];
int node_cnt;
int dfs(int now, int sheep, int wolf) // 방문한 노드, 양 수, 늑대 수
{
    int ans = 0;
    
    for(int i=0;i<node_cnt;i++)
    {
        if(vis[i]) // i번을 방문했었다면 -> 자식을 방문한다.
        {
            for(int j=0;j<tree[i].size();j++)
            {
                int num = tree[i][j];
                if(vis[num]) continue;
                if(info[num] == 0) //양이라면
                {
                    vis[num] = 1;
                    ans = max(ans,dfs(num, sheep+1, wolf));
                    vis[num] = 0;
                }
                else //늑대라면
                {
                    if(sheep <= wolf+1)
                        continue;
                    vis[num] = 1;
                    ans = max(ans, dfs(num, sheep, wolf+1));
                    vis[num] = 0;
                }
                
            }
        }
    }
    return max(ans, sheep);
}

int solution(vector<int> infoo, vector<vector<int>> edges) {
    int answer = 0;
    info = infoo;
    node_cnt = info.size();
    // 트리 저장
    for(int i=0;i<edges.size();i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        tree[a].push_back(b);
    }
    
    vis[0] = 1;
    return dfs(0, 1, 0);
}