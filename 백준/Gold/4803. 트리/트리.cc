#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool vis[501];
vector<int> graph[501];
bool isTree;

void dfs(int s, int pre) //pre: 이전 정점
{
	vis[s] = true;
	for (int i = 0; i < graph[s].size(); i++)
	{
		if (graph[s][i] == pre) continue;
		if (vis[graph[s][i]]) isTree = false;
		else dfs(graph[s][i], s);
	}
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	int num = 0;
	while (true)
	{
		num++;
		int ans = 0;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		int a, b;
		for (int i = 1; i <= n; i++)
		{
			vis[i] = 0;
			graph[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
		{
			if (vis[i]) continue;
			isTree = true;
			dfs(i, 0);
			if (isTree) ans++;
		}
		cout << "Case " << num << ": ";
		if (ans == 0) cout << "No trees.\n";
		else if (ans == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << ans << " trees.\n";
	}

}