#include <bits/stdc++.h>
using namespace std;
#define INF 2'100'000'000

vector<pair<int, int>> vertex[100'001];
int D[100'001];
int main()
{
	int N, M;
	cin >> N >> M;
	if (N == 1)
	{
		cout << 0;
		return 0;
	}
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		vertex[a].push_back(make_pair(b, 1));
	}
	for (int i = 0; i <= N; i++)D[i] = INF;
	D[1] = 0;
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, 1));
	while (!PQ.empty())
	{
		int Ver = PQ.top().second;
		int Cost = PQ.top().first;
		PQ.pop();
		if (Cost > D[Ver])continue;
		for (int i = 0; i < vertex[Ver].size(); i++)
		{
			int nextVer = vertex[Ver][i].first;
			int nextCost = vertex[Ver][i].second;
			if (D[Ver] + nextCost < D[nextVer])
			{
				D[nextVer] = D[Ver] + nextCost;
				PQ.push(make_pair(-D[nextVer], nextVer));
			}
		}
	}
	if (D[N] == INF)cout << -1;
	else cout << D[N];
	return 0;
}