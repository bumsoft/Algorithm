#include <bits/stdc++.h>
using namespace std;
using ll = long long;



vector<int> vertex[10'001];
priority_queue<pair<int, int>> PQ; //<해킹개수, 컴번호>
int vis[10'001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, M;
	cin >> N >> M;

	int A, B; //A가 B를 신뢰 : B에서 A로의 간선 존재
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		vertex[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		//bfs
		queue<int> Q;
		Q.push(i);
		vis[i] = i;
		int num = 0;
		while (!Q.empty())
		{
			int v = Q.front();
			num++;
			Q.pop();
			for (int j = 0; j < vertex[v].size(); j++)
			{
				if (vis[vertex[v][j]] == i) continue;
				vis[vertex[v][j]] = i;
				Q.push(vertex[v][j]);
			}
		}
		PQ.push({ num,i });
	}
	int max = PQ.top().first;
	int c = PQ.top().second;
	PQ.pop();

	priority_queue<int> pq; //<-컴번호>
	pq.push(-c);

	while (!PQ.empty())
	{
		if (max == PQ.top().first)
		{
			pq.push(-PQ.top().second);
			PQ.pop();
		}
		else break;
	}
	while (!pq.empty())
	{
		cout << -pq.top() << ' ';
		pq.pop();
	}
}