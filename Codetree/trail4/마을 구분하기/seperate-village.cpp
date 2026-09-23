#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[25][25];
bool vis[25][25];
vector<int> town;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(int r, int c)
{
    int temp = 0;
    queue<pair<int,int>> Q;
    Q.push({r,c});
    while(!Q.empty())
    {
        auto t = Q.front();
        Q.pop();
        int nr = t.first;
        int nc = t.second;

        temp++;

        for(int i=0;i<4;i++)
        {
            int nnr = nr + dx[i];
            int nnc = nc + dy[i];
            if(nnr < 0 || nnr >= n || nnc < 0 || nnc >=n) continue;
            if(vis[nnr][nnc]) continue;
            if(grid[nnr][nnc]!=1) continue;
            vis[nnr][nnc] = 1;
            Q.push({nnr,nnc});
        }
    }
    town.push_back(temp);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[i][j] || grid[i][j]==0) continue;
            vis[i][j]=1;
            bfs(i,j);
        }
    }
    cout<<town.size()<<'\n';
    sort(town.begin(), town.end());
    for(int i=0;i<town.size();i++)
    {
        cout<<town[i]<<'\n';
    }

    return 0;
}
