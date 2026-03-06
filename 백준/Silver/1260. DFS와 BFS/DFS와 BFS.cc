#include <bits/stdc++.h>
using namespace std;

/*
* 1260
* dfs와 bfs로 탐색한 결과를 출력해라
* 정점 번호(1~N)가 작은것 먼저.
*/

int N, M, V;

priority_queue<int> vertex_dfs[1'001];
priority_queue<int> vertex_bfs[1'001];

queue<int> Q;

bool visit_dfs[1'001];
bool visit_bfs[1'001];


void dfs(int c)
{
	if (visit_dfs[c]) return;
	cout << c << ' ';
	visit_dfs[c] = 1;

	while (!vertex_dfs[c].empty())
	{
		dfs(abs(vertex_dfs[c].top()));
		vertex_dfs[c].pop();
	}
}

void bfs(int c)
{
	Q.push(c);
	visit_bfs[c] = 1;
	int n;
	while (!Q.empty())
	{
		n = Q.front();
		Q.pop();
		cout << n << ' ';

		while (!vertex_bfs[n].empty())
		{
			int temp = abs(vertex_bfs[n].top());
			if (!visit_bfs[temp])
			{
				Q.push(temp);
				visit_bfs[temp] = 1;
			}
			vertex_bfs[n].pop();
		}
	}
}


int main() {
	
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> V;

	int s, e;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e;
		vertex_dfs[s].push(-e);
		vertex_dfs[e].push(-s);		
		vertex_bfs[s].push(-e);
		vertex_bfs[e].push(-s);
	}

	dfs(V);
	cout << '\n';
	bfs(V);

	return 0;
}