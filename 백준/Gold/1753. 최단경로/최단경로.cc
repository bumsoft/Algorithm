#include <bits/stdc++.h>
using namespace std;

#define INF 2000000000
//서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.
//출력 : 모든 정점과의 최단거리를 한줄씩 출력한다. 
int V, E; //1~20000, 1~300000;
int V1;

vector<pair<int,int>> vertex[20001];
int ans[20001];
int visit[20001];

void search(int n)
{

}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int u, v, w;
	cin >> V >> E >> V1;
	for (int e = 0; e < E; e++)
	{
		// u->v 가중치w
		cin >> u >> v >> w;
		vertex[u].push_back(make_pair(v, w));
	}
	for (int i = 0; i <= V; i++)
	{
		ans[i] = INF;
	}
	ans[V1] = 0;

	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, V1)); //w,v

	while (!PQ.empty())
	{
		int WW = -PQ.top().first;
		int VV = PQ.top().second;
		PQ.pop();
        if (ans[VV] < WW) continue;
		for (int i = 0; i < vertex[VV].size(); i++)
		{
			if (ans[VV] + vertex[VV][i].second < ans[vertex[VV][i].first])
			{
				ans[vertex[VV][i].first] = ans[VV] + vertex[VV][i].second;
				PQ.push(make_pair(-ans[vertex[VV][i].first], vertex[VV][i].first));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (ans[i] == INF) cout << "INF\n";
		else cout << ans[i] << '\n';
	}
	return 0;
}