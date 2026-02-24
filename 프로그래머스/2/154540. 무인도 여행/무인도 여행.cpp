#include <bits/stdc++.h>

using namespace std;

bool vis[101][101];
vector<int> answer;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int bfs(int x, int y, vector<string>& maps)
{
    int x_limit = maps.size();
    int y_limit = maps[x].size();
    
    int total = 0;
    queue<pair<int,int>> Q;
    Q.push({x,y});
    vis[x][y] = 1;
    
    while(!Q.empty())
    {
        int cx = Q.front().first;
        int cy = Q.front().second;
        total += maps[cx][cy] - '0';
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int next_x = cx + dx[i];
            int next_y = cy + dy[i];
            if(next_x >= x_limit || next_y >= y_limit || next_x < 0 || next_y < 0) continue;
            if(vis[next_x][next_y]) continue;
            if(maps[next_x][next_y] == 'X')
            {
                vis[next_x][next_y] = 1;
                continue;
            }
            vis[next_x][next_y] = 1;
            Q.push({next_x, next_y});
        }
    }
    return total;
}

vector<int> solution(vector<string> maps) {
    
    for(int i=0;i<maps.size();i++)
    {
        for(int j=0;j<maps[i].size();j++)
        {
            if(vis[i][j]) continue;
            if(maps[i][j] == 'X') continue;
            //bfs
            int total = bfs(i,j, maps);
            answer.push_back(total);
        }
    }
    if(answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    
    return answer;
}