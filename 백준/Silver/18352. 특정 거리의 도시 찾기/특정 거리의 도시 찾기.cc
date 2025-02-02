#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//그냥 큐 다익스트라 or BFS
int N, M, K, X;

vector<int> vertex[300'001];
queue<pair<int,int>> Q;
int D[300'001];
bool vis[300'001];
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K >> X;
	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		vertex[A].push_back(B);
	}
	for (int i = 1; i <= N; i++) D[i] = INT_MAX;

	Q.push({ X,0 });
	vis[X] = 1;
	while (!Q.empty())
	{
		int v = Q.front().first;
		int c = Q.front().second;
		D[v] = c;
		Q.pop();

		for (int i = 0; i < vertex[v].size(); i++)
		{
			if (vis[vertex[v][i]]) continue;
			vis[vertex[v][i]] = true;
			Q.push({ vertex[v][i], c + 1 });
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (D[i] == K)
		{
			cout << i << '\n';
			ans++;
		}
	}
	if (ans == 0)cout << -1;

}