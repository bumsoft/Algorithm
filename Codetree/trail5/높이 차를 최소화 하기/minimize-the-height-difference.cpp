#include <bits/stdc++.h>

using namespace std;

// 매개변수: (최대 - 최소) : 0 ~ 499 -> log500 = 9번 정도
// 해당 매개변수 이하를 만족하게 dfs(현재최소, 현재최대)를 진행한다. -> 10'000
// 만족하는게 있다면, 매개변수를 더 작게
// 만족하는게 없다면, 매개변수를 더 크게

int n, m;
int board[100][100];
bool vis[100][100];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

void init_vis()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            vis[i][j]=0;
}

bool dfs(int r, int c, int low, int high)
{
    if(r == n-1 && c == m-1) return 1;
    
    for(int i=0;i<4;i++)
    {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if(vis[nr][nc]) continue;
        if(board[nr][nc] >= low && board[nr][nc] <= high)
        {
            vis[nr][nc]=1;
            if(dfs(nr,nc,low,high)) return 1;
        }
    }
    return 0;
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int ans = 501;
    int low = 0;
    int high = 500 - 1;
    int mid;
    while(low <= high)
    {
        bool ck = 0;
        mid = (low + high)/2;

        for(int i=1;i<=500;i++) // 지나는 가장 작은 값이 i일때...
        {
            init_vis();
            vis[0][0] = 1; 
            // i ~ i+mid 만 지나서 갈 수 있는지 확인한다.
            if(dfs(0,0,i,i+mid))
            {
                ck = 1;
                break;
            }
        }
        if(ck) // 해당 값으로 가능하다면 더 작은 값을 찾는다.
        {
            high = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            low = mid + 1;
        }
    }
    cout<<ans;
    return 0;
}
