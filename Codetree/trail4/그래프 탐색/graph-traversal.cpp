#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> vertex[1'001];

bool vis[1'001];

int ans;

void dfs(int now)
{

    for(int i=0;i<vertex[now].size();i++)
    {
        if(vis[vertex[now][i]]) continue;
        vis[vertex[now][i]] = 1;
        ans++;
        dfs(vertex[now][i]);
    }
}

int main() {
    cin >> n >> m;
    int a,b;

    for (int i = 0; i < m; i++) {
        cin >> a>>b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }

    // Please write your code here.
    vis[1]=1;
    dfs(1);

    cout<<ans;
    return 0;
}
