#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
1->2->3->4
   6->5->

  각 물건에 대해서 비교 결과를 알 수 없는 물건의 개수 출력!

  dfs로 진행하며, 지나간 노드의 개수 저장(본인제외) + 지나간 노드(본인포함)의 값 1씩 증가
  모든 정점에 대해 dfs 수행
*/
int N, M;
bool vis[101];

vector<int> graph[101];
int cnt[101];

void init()
{
	for (int i = 1; i <= N; i++)
	{
		vis[i] = 0;
	}
}

int dfs(int s, int c)
{
	vis[s] = true;
	cnt[s]++;
	for (int i = 0; i < graph[s].size(); i++)
	{
		if (vis[graph[s][i]]) continue;
		c = dfs(graph[s][i], c + 1);
	}

	return c;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 1; i <= N; i++)
	{
		init();
		cnt[i] += dfs(i, 0);
	}
	for (int i = 1; i <= N; i++)
	{
		cout << N - cnt[i] << '\n';
	}
}