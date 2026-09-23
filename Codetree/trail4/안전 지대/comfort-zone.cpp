#include <bits/stdc++.h>

using namespace std;

int N, M;
int grid[50][50];

int end_;
int ans_k;
int ans_num;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool vis[50][50];

void init_vis()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            vis[i][j]=0;
    }
}

void bfs(int r, int c, int k)
{
    queue<pair<int,int>> Q;
    Q.push({r,c});
    while(!Q.empty())
    {
        int nr = Q.front().first;
        int nc = Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int nnr = nr + dx[i];
            int nnc = nc + dy[i];
            if(grid[nnr][nnc] <= k) continue;
            if(vis[nnr][nnc]) continue;
            vis[nnr][nnc]=1;
            Q.push({nnr,nnc});
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            end_ = max(end_, grid[i][j]);
        }
    }
    // K(mid)가 커지면, 안전구역이 많아지고
    // K가 작아지면, 안전구역의 수는 줄어든다.
    for(int mid = 1; mid < end_; mid++)
    {
        init_vis();
        int temp = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(vis[i][j]) continue;
                if(grid[i][j] <= mid) continue;
                vis[i][j]=1;
                temp++;
                bfs(i,j,mid);
            }
        }

        if(temp > ans_num)
        {
            ans_num = temp;
            ans_k = mid;
        }
    }
    cout<<ans_k<<' '<<ans_num;
    

    return 0;
}
