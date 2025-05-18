#include <bits/stdc++.h>
using namespace std;

//INF가 아닌 것의 개수와 아닌 것들의 최대값.
#define INF 2'100'000'000
priority_queue<pair<int, int>> PQ;
int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int T,n, d, c, a, b, s;
	cin >> T;
	while (T--)
	{
		vector<pair<int, int>> vertex[10001];
		int D[10001];
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++)
		{
			cin >> a >> b >> s;
			vertex[b].push_back(make_pair(a, s));
		}
		for (int i = 1; i <= n; i++)D[i] = INF;
		PQ.push(make_pair(0, c));
		D[c] = 0;
		while (!PQ.empty())
		{
			int Ver = PQ.top().second;
			int Cost = -PQ.top().first;
			PQ.pop();
			if (Cost > D[Ver])continue;
			for (int i = 0; i < vertex[Ver].size(); i++)
			{
				int nextVer = vertex[Ver][i].first;
				int nextCost = vertex[Ver][i].second;
				if (nextCost + D[Ver] < D[nextVer])
				{
					D[nextVer] = nextCost + D[Ver];
					PQ.push(make_pair(-D[nextVer], nextVer));
				}
			}
		}
		int max = 0, num = 0;
		for (int i = 1; i <= n; i++)
		{
			if (D[i] != INF)
			{
				max = max > D[i] ? max : D[i];
				num++;
			}
		}
		cout << num << ' ' << max << '\n';
	}
	return 0;
}