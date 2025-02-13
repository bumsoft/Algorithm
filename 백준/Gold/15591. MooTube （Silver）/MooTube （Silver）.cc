#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//MooTube
//쿼리당 dfs한번씩만 하기.

int N, Q, K, M;
int ans;
vector<pair<int,int>> graph[5001];
bool vis[5001];

void init()
{
	M = INT_MAX;
	ans = -1;
	for (int i = 1; i <= N; i++)
	{
		vis[i] = 0;
	}
}

void dfs(int s, int m)
{
	if (m >= K) ans++;
	for (int i = 0; i < graph[s].size(); i++)
	{
		if (!vis[graph[s][i].first])
		{
			vis[graph[s][i].first] = 1;
			dfs(graph[s][i].first, min(m,graph[s][i].second));
		}
	}
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> Q;
	int a, b, c;
	for (int i = 0; i < N-1; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	int v;
	while (Q--)
	{
		cin >> K >> v;
		init();
		vis[v] = 1;
		dfs(v, INT_MAX);
		cout << ans << '\n';
	}
}