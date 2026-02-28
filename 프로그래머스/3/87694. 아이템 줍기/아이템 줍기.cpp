#include <bits/stdc++.h>

using namespace std;
// 좌표 해상도를 늘려줘야함

// 모든 좌표는 1~50
// 1. bool board[51][51];
// 2. 모든 직사각형을 1로 채운다.
// 3. 외부와 맞닿아있는 부분만을 새로운 보드에 그린다.
// 4. 시작점에서 1을 따라서 양쪽으로(사실상 4방향) 이동해본다.
// 5. 최소를 찾는다.

int dx[]= {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool board[104][104];
bool final_board[104][104];
bool vis[104][104];
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    // 모든 직사각형을 board에 1로 채운다.
    for(int i=0;i<rectangle.size();i++)
    {
        int ax = rectangle[i][0]*2;//좌하x
        int ay = rectangle[i][1]*2;//좌하y
        
        int bx = rectangle[i][2]*2;//우상x
        int by = rectangle[i][3]*2;//우상y
        for(int x = ax; x<=bx;x++)
        {
            for(int y = ay; y<=by;y++)
            {
                board[x][y] = 1;
            }
        }
    }
    // for(int i=0;i<15;i++)
    // {
    //     for(int j=0;j<15;j++)
    //     {
    //         if(board[i][j]) cout<<'O';
    //         else cout<<'X';
    //     }
    //     cout<<'\n';
    // }
    
    //외부와 맞닿아있는 부분만을 새로운 보드에 그린다.
    for(int i=1;i<=104;i++)
    {
        for(int j=1;j<=104;j++)
        {
            if(board[i][j])
            {
                // 상하좌우가 false와 닿고있으면 경계선 + 대각선까지
                if(!board[i-1][j] ||!board[i][j-1] ||!board[i+1][j] ||!board[i][j+1]) final_board[i][j]=1;
                else if(!board[i-1][j-1] ||!board[i+1][j-1] ||!board[i-1][j+1] ||!board[i+1][j+1]) final_board[i][j]=1;
            }
        }
    }
        for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            if(final_board[i][j]) cout<<'O';
            else cout<<' ';
        }
        cout<<'\n';
    }
    //시작점에서 1을 따라서 bfs
    queue<pair<int,pair<int,int>>> Q;
    Q.push({0,{characterX*2, characterY*2}});
    vis[characterX*2][characterY*2] = 1;
    while(!Q.empty())
    {
        int x = Q.front().second.first;
        int y = Q.front().second.second;
        int dis = Q.front().first;
        cout<<"x:"<<x<<"  y:"<<y<<"\n";
        Q.pop();
        if(x == itemX*2 && y == itemY*2) return dis/2;
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!final_board[nx][ny]) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({dis+1,{nx,ny}});
        }
    }
    return answer;
}