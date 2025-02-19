#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//지게차
// 특정 컨테이너의 출고 요청시, 접근 가능한 같은 모든 컨테이너를 제거한다.
// 1면 이상이 외부와 연결된 컨테이너를 말함.

//크레인
// 특정 출고 요청시, 같은 모든 컨테이너 제거.

// 지게차 요청시, bfs => 시작시 접근 가능한 것만 꺼낼 수 있다!
// 크레인 요청시 완탐

//50*50 = 2500
//최대 100번의 요청
// 250'000 최악의 경우.

char board[55][55];
int N,M;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void ppp()
{
        for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(board[i][j] == 0)cout<<'0'<<' ';
            else if(board[i][j] == 1) cout<<'1'<<' ';
            else cout<<board[i][j]<<' ';
        }cout<<'\n';
    }
    cout<<'\n';
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    N = storage.size() + 2;
    M = storage[0].size() + 2;
    
    for(int i=1;i<=N-2;i++)
    {
        for(int j=1;j<=M-2;j++)
        {
            board[i][j] = storage[i-1][j-1];
        }
    }
    
    for(int i=0;i<requests.size();i++)
    {
        char target = requests[i][0];
        if(requests[i].size() == 2) //크레인
        {
            for(int r = 0;r<N;r++)
            {
                for(int c = 0;c<M;c++)
                {
                    if(board[r][c] == target)
                    {
                        board[r][c] = 0;
                    }
                }
            }
        }
        else //지게차
        {
            queue<pair<int,int>> Q;
            bool vis[55][55];
            //초기화 및 Q넣기
            for(int r=0;r<N;r++)
            {
                for(int c=0;c<M;c++)
                {
                    vis[r][c] = false;
                    if(board[r][c] == 1)
                    {
                        board[r][c] = 0;
                    }
                }
            }
            Q.push({0,0});
            vis[0][0] = true;
            while(!Q.empty())
            {
                int r = Q.front().first;
                int c = Q.front().second;
                Q.pop();
                for(int k=0;k<4;k++)
                {
                    int nr = r + dx[k];
                    int nc = c + dy[k];
                    if(nr < 0 || nr >= N || nc<0||nc>=M) continue;
                    
                    if(vis[nr][nc])continue;
                    vis[nr][nc] = true;
                    if(board[nr][nc] == target)
                    {
                        board[nr][nc] = 1; //빈자리는 큐에 넣지 않는다.
                        continue;
                    }
                    if(board[nr][nc]==0) Q.push({nr,nc});
                }
            }
            
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(board[i][j] != 0 && board[i][j] != 1) answer++;
        }
    }
    
    
    return answer;
}