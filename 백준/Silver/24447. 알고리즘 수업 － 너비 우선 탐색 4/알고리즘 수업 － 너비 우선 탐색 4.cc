#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//N개 정점 M개 간선
//모든가중치 1

//정점 R에서 시작.
// 모든 정점에 대해 방문순서*깊이   의 합.

priority_queue<int> vertex[100'001];
int N, M, R;
ll ans;
bool vis[100'001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> R;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		vertex[a].push(-b);
		vertex[b].push(-a);
	}
	queue<pair<int,int>> Q;
	Q.push({ R,0 });
	ll order = 1;
	int memory = R;
	bool ck = false;
	while (!Q.empty())
	{
		int Ver = Q.front().first;
		int depth = Q.front().second;
		Q.pop();
		if (vis[Ver])continue;
		vis[Ver] = true;

		ans += depth * order;
		order++;
		while (!vertex[Ver].empty())
		{
			if (!vis[-vertex[Ver].top()])
			{
				Q.push({-vertex[Ver].top(),depth+1});
			}
			vertex[Ver].pop();
		}
	}
	cout << ans;
}