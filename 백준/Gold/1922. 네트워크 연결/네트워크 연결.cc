#include <bits/stdc++.h>
using namespace std;
int N, M, ans;
int vis[1001];
vector<pair<int, int>> vertex[1001];
int main()
{
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(b, c));
		vertex[b].push_back(make_pair(a, c));
	}
	priority_queue < pair<int, int>> PQ;
	PQ.push(make_pair(0, 1));

	while (!PQ.empty())
	{
		int Ver = PQ.top().second;
		int Cost = -PQ.top().first;
		PQ.pop();
		if (vis[Ver]) continue;
		vis[Ver] = true;
		ans += Cost;
		for (int i = 0; i < vertex[Ver].size(); i++)
		{
			if (vis[vertex[Ver][i].first]) continue;
			PQ.push(make_pair(-vertex[Ver][i].second, vertex[Ver][i].first));
		}
	}
	cout << ans;

	return 0;
}