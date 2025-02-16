#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> vertex[201];
bool vis[201][201];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int t; cin >> t;
			if (t == 1) vertex[i].push_back(j);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		queue<int> q;
		q.push(i);
		vis[i][i] = 1;
		while (!q.empty())
		{
			int ver = q.front();
			q.pop();
			for (int k = 0; k < vertex[ver].size(); k++)
			{
				if (vis[i][vertex[ver][k]]) continue;
				vis[i][vertex[ver][k]] = 1;
				q.push(vertex[ver][k]);
			}
		}
	}
	int t, pre;
	cin >> pre;
	M--;
	while (M--)
	{
		cin >> t;
		if (vis[pre][t]) pre = t;
		else { cout << "NO";  return 0; }
	}
	cout << "YES";
	return 0;
}