// 가장자리 0에서 0인 칸들로 이동하며 bfs를 돌면서, (다음턴에 0이 될) 1인 칸을 별도 Q에 넣는다.
// 이때 큐의 한 원소는 좌표 외에, 턴 수를 기록하는 것도 별도로 넣는다.
// 이제 이 Q로 bfs를 돌린다.
// 1인 것을 큐에 넣고, 아직 방문하지 않았던 0도 큐에 넣어준다. 턴수는 현재턴 + 1로 넣는다.
// 이걸 반복하다가...  끝나면, 마지막 턴수와 개수를 출력한다.


#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[200][200];
bool vis[200][200];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main() {
    cin >> N >> M;
    int n = N;
    int m = M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    priority_queue<pair<int, pair<int,int>>> Q; // <turn, <i, j>>
    //1. 바깥쪽 모든 물을 Q에 넣고 방문처리한다.
    queue<pair<int,int>> temp_Q;
    temp_Q.push({0,0});
    vis[0][0]=1;
    Q.push({0,{0,0}});
    while(!temp_Q.empty())
    {
        int r = temp_Q.front().first;
        int c = temp_Q.front().second;
        temp_Q.pop();
        
        for(int i=0;i<4;i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(a[nr][nc]!= 0) continue;
            if(vis[nr][nc])continue;
            vis[nr][nc]=1;
            temp_Q.push({nr,nc});
            Q.push({0,{nr,nc}});
        }
    }

    int turn = 0;
    int cnt = 0;
    while(!Q.empty())
    {
        int _turn = -Q.top().first;
        int r = Q.top().second.first;
        int c = Q.top().second.second;
        Q.pop();

        if(_turn == turn) 
        {
            if(a[r][c]==1) cnt++; //빙하였어야만 개수 증가
        }
        else
        {
            turn = _turn;
            cnt = 1;
        }
        for(int i=0;i<4;i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(vis[nr][nc]) continue;
            // 다음에 물이 될 것을 찾아야하는데, 원래 물이었던 것은 개수에 포함시키면 안됨.(위에서 처리)
            if(a[nr][nc]==0)
            {
                Q.push({-turn,{nr,nc}});
            }
            else Q.push({-(turn+1), {nr,nc}});
            vis[nr][nc]=1;
        }
    }
    cout<<turn<<' '<<cnt;


    return 0;
}
