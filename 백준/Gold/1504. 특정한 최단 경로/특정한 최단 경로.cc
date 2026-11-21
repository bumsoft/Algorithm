#include <bits/stdc++.h>
using namespace std;

//1에서 v1 v2를 거쳐 N으로 가는 최단경로.

//1) 1-V1-V2-N

//2) 1-V2-V1-N

#define INF 2'100'000'000
vector<pair<int, int>> vertex[801];
int D[801];
int TD[801];

int ans;

void dijk(int s) //s:시작점
{
	memcpy(&TD, &D, sizeof(int) * 801);
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, s));
	TD[s] = 0;

	while (!PQ.empty())
	{
		int Cost = -PQ.top().first;
		int Ver = PQ.top().second;
		PQ.pop();
		if (Cost > TD[Ver]) continue;

		for (int i = 0; i < vertex[Ver].size(); i++)
		{
			int nextVer = vertex[Ver][i].first;
			int nextCost = vertex[Ver][i].second;
			
			if (TD[Ver] + nextCost < TD[nextVer])
			{
				TD[nextVer] = TD[Ver] + nextCost;
				PQ.push(make_pair(-TD[nextVer], nextVer));
			}
		}
	}
}


int main()
{
	int N, E, a, b, c;
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(b, c));
		vertex[b].push_back(make_pair(a, c));
	}
	int v1, v2;
	cin >> v1 >> v2;
	for (int i = 1; i <= N; i++) D[i] = INF;
	//
	long long v1_1, v1_v2, v1_n, v2_1, v2_n;

	dijk(v1);
	v1_1 = TD[1];
	v1_v2 = TD[v2];
	v1_n = TD[N];
	dijk(v2);
	v2_1 = TD[1];
	v2_n = TD[N];

	long long ans1 = v1_1 + v1_v2 + v2_n;
	long long ans2 = v2_1 + v1_v2 + v1_n;
	long long ans = ans1 < ans2 ? ans1 : ans2;

	if (ans >= INF) ans = -1;
	cout << ans;

	return 0;
}