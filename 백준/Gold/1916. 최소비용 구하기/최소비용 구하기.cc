#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
/*
* 1916
* N개의 도시와 M개의 버스 //노선은 단방향
* A->B로의 최소 버스 비용
*/

int N, M;
int S, E;
int D[1'001];

vector<pair<int, int>> vertex[1'001];

priority_queue<pair<int, int>> PQ;

void dijkstra(int v1)
{
	D[v1] = 0;
	PQ.push({ D[v1],v1});

	while (!PQ.empty())
	{
		int cost = -PQ.top().first; //지금 정점까지의 비용
		int ver = PQ.top().second; //지금 정점
		PQ.pop();

		if (D[ver] != cost) continue;

		for (int i = 0; i < vertex[ver].size(); i++)
		{
			int nextVer = vertex[ver][i].first; //갈 수 있는 정점
			int nextCost = vertex[ver][i].second;//필요한 비용

			if (D[nextVer] <= cost + nextCost) continue;
			D[nextVer] = cost + nextCost; //비용갱신
			PQ.push({ -D[nextVer], nextVer });
		}
	}
}


int main() {
	
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		D[i] = INF;
	}

	int start, end, cost;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> cost;

		vertex[start].push_back({ end,cost });
	}

	cin >> S >> E;

	dijkstra(S);

	cout << D[E];


	return 0;
}