#include <bits/stdc++.h>
using namespace std;
using area = pair<int, int>;
int N, M;
int arr[8][8];
int nw;
int MAX=100, mm;
bool vis[8][8];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void bfs(int i, int j)
{
	queue<area> Q;
	Q.push({ i,j });
	while (!Q.empty())
	{
		area now = Q.front();
		Q.pop();
		mm++;
		for (int t = 0; t < 4; t++)
		{
			int a = now.first + dx[t];
			int b = now.second + dy[t];

			if (a < 0 || a >= N || b < 0 || b >= M) continue;
			if (vis[a][b] || arr[a][b] != 0) continue;
			vis[a][b] = true;
			Q.push({ a,b });
		}
	}
}
void sol(area a, area b, area c)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			vis[i][j] = false;
		}
	}
	mm = 0;
	arr[a.first][a.second] = 1;
	arr[b.first][b.second] = 1;
	arr[c.first][c.second] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vis[i][j])continue;
			if (arr[i][j] == 2)
			{
				bfs(i, j);
			}
		}
	}
	arr[a.first][a.second] = 0;
	arr[b.first][b.second] = 0;
	arr[c.first][c.second] = 0;
	MAX = min(MAX, mm);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)nw++;
		}
	}
	for (int i = 0; i < N * M; i++)
	{
		if (arr[i / M][i % M]==1 || arr[i / M][i % M] == 2) continue;
		for (int j = i; j < N * M; j++)
		{
			if (arr[j / M][j % M] == 1 || arr[j / M][j % M] == 2) continue;
			for (int l = j; l < N * M; l++)
			{
				if (arr[l / M][l % M] == 1 || arr[l / M][l % M] == 2) continue;
				sol({ i / M,i % M }, { j / M,j % M }, { l / M,l % M });
			}
		}
	}
	cout << N * M - 3 - MAX - nw;
	return 0;
}