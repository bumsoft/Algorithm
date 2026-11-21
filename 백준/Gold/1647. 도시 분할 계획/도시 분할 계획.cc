// N개의 집, M개의 길
// 무향그래프
// 길마다 유지비

// 두개로 분할 => MST를 구하고 거리중 가장 큰 비용을 뺌?

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vertex[100001];
priority_queue<pair<int, int>> PQ;
bool vis[100001];
int N, M;


int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int a, b, c, max = 0, sum = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(b, c));
		vertex[b].push_back(make_pair(a, c));
	}
	PQ.push(make_pair(0, 1));
	while (!PQ.empty())
	{
		int Ver = PQ.top().second;
		int Cost = -PQ.top().first;
		PQ.pop();
		if (vis[Ver]) continue;
		max = max > Cost ? max : Cost;
		vis[Ver] = true;
		sum += Cost;
		for (int i = 0; i < vertex[Ver].size(); i++)
		{
			if (vis[vertex[Ver][i].first]) continue;
			PQ.push(make_pair(-vertex[Ver][i].second, vertex[Ver][i].first));
		}
	}
	cout << sum - max;
	return 0;
}