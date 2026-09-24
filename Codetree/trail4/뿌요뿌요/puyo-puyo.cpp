#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool vis[100][100];

int dfs(int r, int c, int num)
{
    int cnt = 0;
    for(int i=0;i<4;i++)
    {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if(vis[nr][nc]) continue;
        if(grid[nr][nc] != num) continue;
        vis[nr][nc] = 1;
        cnt += dfs(nr,nc,num);
    }
    return cnt+1;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans=0;
    int ans_=0;
    // Please write your code here.
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[i][j]) continue;
            vis[i][j]=1;
            int t = dfs(i,j,grid[i][j]);
            if(t >= 4) ans++;
            ans_ = max(ans_, t);
        }
    }
    cout<<ans<<' '<<ans_;

    return 0;
}
