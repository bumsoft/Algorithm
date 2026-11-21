#include <bits/stdc++.h>
using namespace std;


//출력 : 최소비용 \n 경로에 포함된 도시개수 \n 경로
//경로추적 : 최소가 갱신될 때마다 이전 도시를 기록해줌

#define INF 2000000000
vector<pair<int, int>> vertex[1001];
int ans[1001];
int path[1001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int u, v, w, V, E;
	cin >> V >> E; //도시, 노선
	for (int e = 0; e < E; e++)
	{
		// u->v 가중치w
		cin >> u >> v >> w;
		vertex[u].push_back(make_pair(v, w));
	}
	int start, end;
	cin >> start >> end;
	for (int i = 0; i <= V; i++)
	{
		ans[i] = INF;
	}
	ans[start] = 0;
	queue<int> temp; temp.push(start);
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, start)); //w,v

	while (!PQ.empty())
	{
		int WW = -PQ.top().first;
		int VV = PQ.top().second;
		PQ.pop();
		if (ans[VV] < WW) continue;
		for (int i = 0; i < vertex[VV].size(); i++)
		{
			int nextVer = vertex[VV][i].first;
			int nextCost = vertex[VV][i].second;

			if (ans[VV] + nextCost < ans[nextVer])
			{
				ans[nextVer] = ans[VV] + nextCost;
				path[nextVer] = VV;
				PQ.push(make_pair(-ans[nextVer], nextVer));
			}
		}
	}
	vector<int> p;
	int tt = end;
	while (tt) //tt가 0이 되면 끝
	{
		p.push_back(tt);
		tt = path[tt];
	}
	cout << ans[end] << '\n' << p.size() << '\n';
	for (int i = p.size() - 1;i>=0; i--)
	{
		cout << p[i] << ' ';
	}

	return 0;
}