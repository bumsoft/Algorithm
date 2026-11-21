#include <bits/stdc++.h>
using namespace std;

#define INF 2000000000
vector<pair<int,int>> vertex[1001];
int Tans[1001];
int ans[1001];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int u, v, w, V, E, X;
	cin >> V >> E >> X; //도시, 노선, 목적지
	for (int e = 0; e < E; e++)
	{
		// u->v 가중치w
		cin >> u >> v >> w;
		vertex[u].push_back(make_pair(v, w));
	}
	for (int i = 0; i <= V; i++)
	{
		Tans[i] = INF;
		ans[i] = INF;
	}

	//T에서 각 마을까지 가는데 걸리는 시간 구하기
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, X)); //w,v
	Tans[X] = 0;
	while (!PQ.empty())
	{
		int WW = -PQ.top().first;
		int VV = PQ.top().second;
		PQ.pop();
		if (Tans[VV] < WW) continue;
		for (int i = 0; i < vertex[VV].size(); i++)
		{
			if (Tans[VV] + vertex[VV][i].second < Tans[vertex[VV][i].first])
			{
				Tans[vertex[VV][i].first] = Tans[VV] + vertex[VV][i].second;
				PQ.push(make_pair(-Tans[vertex[VV][i].first], vertex[VV][i].first));
			}
		}
	}

	for (int q = 1; q <= V; q++)
	{
		if (q == X) continue;
		int arr[1001];
		memcpy(&arr, &ans, sizeof(ans));
		PQ.push(make_pair(0, q));
		arr[q] = 0;
		while (!PQ.empty())
		{
			int WW = -PQ.top().first;
			int VV = PQ.top().second;
			PQ.pop();
			if (arr[VV] < WW) continue;
			for (int i = 0; i < vertex[VV].size(); i++)
			{
				if (arr[VV] + vertex[VV][i].second < arr[vertex[VV][i].first])
				{
					arr[vertex[VV][i].first] = arr[VV] + vertex[VV][i].second;
					PQ.push(make_pair(-arr[vertex[VV][i].first], vertex[VV][i].first));
				}
			}
		}
		Tans[q] += arr[X];
	}


	int max = 0;
	for (int i = 1; i <= V; i++)
	{
		if (Tans[i] > max)
		{
			max = Tans[i];
		}
	}
	cout << max;

	return 0;
}