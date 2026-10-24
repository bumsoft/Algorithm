#include <bits/stdc++.h>

using namespace std;

int ans = INT_MAX;
vector<string> board;
int N,M;
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
bool vis[101][101];

pair <int,int> move(int r, int c, int type) // r,c에서 type방향으로 쭉 이동했을 때의 좌표 반환
{
    while(true)
    {
        int nr = r + dx[type];
        int nc = c + dy[type];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) break;
        if(board[nr][nc] == 'D') break;
        r = nr;
        c = nc;
    }
    return {r,c};
}

void dfs(pair<int,int> pos, int cnt)
{
    if(cnt > ans) return;
    if(board[pos.first][pos.second] == 'G')
    {
        ans = min(ans,cnt);
        return;
    }
    for(int i=0;i<4;i++)
    {
        auto t = move(pos.first, pos.second, i);
        if(vis[t.first][t.second]) continue;
        vis[t.first][t.second] = 1;
        dfs(t, cnt+1);
        vis[t.first][t.second]=0;
    }
}

void bfs(pair<int,int> pos)
{
    queue<pair<int,pair<int,int>>> Q;
    Q.push({0,{pos.first, pos.second}});
    
    while(!Q.empty())
    {
        auto t = Q.front().second;
        int cnt = Q.front().first;
        Q.pop();
        
        
        for(int i=0;i<4;i++)
        {
            auto nt = move(t.first, t.second, i);
            if(vis[nt.first][nt.second]) continue;
            vis[nt.first][nt.second] = 1;
            Q.push({cnt+1,nt});
            
            if(board[nt.first][nt.second] == 'G') 
            {
                ans = cnt+1;
                return;
            }
        }
    }
}

int solution(vector<string> board_) {
    
    N = board_.size();
    M = board_[0].size();
    board = board_;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(board[i][j] == 'R')
            {
                vis[i][j]=1;
                bfs({i,j});
                if(ans == INT_MAX) return -1;
                return ans;
            }
        }
    
}