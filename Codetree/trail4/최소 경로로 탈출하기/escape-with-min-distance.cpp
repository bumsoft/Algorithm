#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int vis[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    queue<pair<int,pair<int,int>>> Q;
    vis[0][0]=1;
    Q.push({0,{0,0}});
    bool ck = 0;
    while(!Q.empty())
    {
        int r = Q.front().second.first;
        int c = Q.front().second.second;
        int cnt = Q.front().first;
        Q.pop();

        if(r==n-1 && c == m-1)
        {
            cout<<cnt;
            return 0;
        }

        for(int i=0;i<4;i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >=n || nr < 0 || nc >=m || nc < 0) continue;
            if(vis[nr][nc]) continue;
            if(a[nr][nc]==0) continue;
            vis[nr][nc]=1;
            Q.push({cnt+1,{nr,nc}});
        }
    }
    cout<<-1;


    return 0;
}
