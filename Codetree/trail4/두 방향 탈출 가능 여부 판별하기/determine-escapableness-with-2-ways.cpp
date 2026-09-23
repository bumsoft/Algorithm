#include <iostream>

using namespace std;

int N, M;
int grid[100][100];
bool vis[100][100];

int dx[2] = {0,1};
int dy[2] = {1,0};

bool ans;
void dfs(int r, int c)
{
    if(ans) return;
    for(int i=0;i<2;i++)
    {
        if(r+dx[i] >=N || c+dy[i] >=M) continue;
        if(r+dx[i]==N-1 && c+dy[i]==M-1)
        {
            ans=1;
            return;
        }
        if(grid[r+dx[i]][c+dy[i]] == 0 || vis[r+dx[i]][c+dy[i]]==1) continue;
        vis[r+dx[i]][c+dy[i]]=1;
        dfs(r+dx[i], c+dy[i]);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    vis[0][0]=1;
    dfs(0,0);
    cout<< (ans) ? 1:0;

    return 0;
}
