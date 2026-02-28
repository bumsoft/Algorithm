#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
bool vis[101][101];

int solution(vector<vector<int> > maps)
{
    int n = maps.size()-1;
    int m = maps[0].size()-1;
    queue<pair<int,pair<int,int>>> Q; // <dis,<x,y>>
    Q.push({1,{0,0}}); // 시작점 포함
    vis[0][0] = 1;
    while(!Q.empty())
    {
        int x = Q.front().second.first;
        int y = Q.front().second.second;
        int dis = Q.front().first;
        Q.pop();
        if(x == n && y == m)
            return dis;
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > n || ny <0 || ny > m) continue;
            if(maps[nx][ny]==0) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({dis+1,{nx,ny}});
        }
    }
    return -1;
}