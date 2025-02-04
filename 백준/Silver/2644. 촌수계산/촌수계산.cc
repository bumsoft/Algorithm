#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//BFS

vector<int> person[101];
bool vis[101];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	int a, b;
	int m;
	int x, y;
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		person[x].push_back(y);
		person[y].push_back(x);
	}

	queue<pair<int,int>> Q;
	Q.push({ a,0 });

	while (!Q.empty())
	{
		int p = Q.front().first;
		int cost = Q.front().second;
		Q.pop();
		if (p == b)
		{
			cout << cost;
			return 0;
		}
		for (int i = 0; i < person[p].size(); i++)
		{
			if (vis[person[p][i]]) continue;
			vis[person[p][i]] = true;
			Q.push({ person[p][i], cost + 1 });
		}
	}
	if (!vis[b])cout << -1;


	return 0;
}