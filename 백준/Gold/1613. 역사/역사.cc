#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
bool vis[401][401];
vector<int> vertex[401];
queue<int> Q;


void bfs(int s)
{
	vis[s][s] = 1;
	Q.push(s);
	while (!Q.empty())
	{
		int V = Q.front();
		Q.pop();
		for (int i = 0; i < vertex[V].size(); i++)
		{
			if (vis[s][vertex[V][i]])continue;

			vis[s][vertex[V][i]] = 1;

			Q.push(vertex[V][i]);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	int a, b;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		vertex[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		bfs(i);
	}

	int s; cin >> s;
	for (int i = 0; i < s; i++)
	{
		cin >> a >> b;
		if (vis[a][b])
		{
			cout << -1 << '\n';
			continue;
		}
		if (vis[b][a])
		{
			cout << 1 << '\n';
			continue;
		}
		cout << 0 << '\n';
	}

	return 0;
}