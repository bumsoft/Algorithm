#include <bits/stdc++.h>
#define INF 2'100'000'000
using namespace std;
int D[10001];
vector<pair<int, int>> nodes[10001];
int main()
{
	int N; cin >> N;
	if (N == 1)
	{
		cout << 0;
		return 0;
	}
	int a, b, c;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> c;
		nodes[a].push_back(make_pair(b, c));
		nodes[b].push_back(make_pair(a, c));
	}
	for (int i = 1; i <= N; i++) D[i] = INF;
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, 1));
	D[1] = 0;
	while (!PQ.empty())
	{
		int Node = PQ.top().second;
		int Cost = -PQ.top().first;
		PQ.pop();
		if (Cost > D[Node]) continue;
		for (int i = 0; i < nodes[Node].size(); i++)
		{
			int nextNode = nodes[Node][i].first;
			int nextCost = nodes[Node][i].second;
			if (D[Node] + nextCost < D[nextNode])
			{
				D[nextNode] = D[Node] + nextCost;
				PQ.push(make_pair(-D[nextNode], nextNode));
			}
		}
	}
	int max = 0;
	int index = 0;
	for (int i = 1; i <= N; i++)
	{
		if (D[i] > max) { max = D[i]; index = i; }
		D[i] = INF;
	}
	PQ.push(make_pair(0, index));
	D[index] = 0;
	while (!PQ.empty())
	{
		int Node = PQ.top().second;
		int Cost = -PQ.top().first;
		PQ.pop();
		if (Cost > D[Node]) continue;
		for (int i = 0; i < nodes[Node].size(); i++)
		{
			int nextNode = nodes[Node][i].first;
			int nextCost = nodes[Node][i].second;
			if (D[Node] + nextCost < D[nextNode])
			{
				D[nextNode] = D[Node] + nextCost;
				PQ.push(make_pair(-D[nextNode], nextNode));
			}
		}
	}
	max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (D[i] > max) { max = D[i]; }
	}
	cout << max;

}