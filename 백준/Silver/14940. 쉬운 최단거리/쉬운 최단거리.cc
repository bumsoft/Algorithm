#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int board[1001][1001];
int D[1001][1001];
queue<pair<int,pair<int,int>>> Q;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1, 0,-1 };

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			D[i][j] = -1;
			if (board[i][j] == 0)
			{
				D[i][j] = 0;
				continue;
			}
			if (board[i][j] == 2)
			{
				D[i][j] = 0;
				Q.push({ 0,{i,j} });
			}
		}
	}
	while (!Q.empty())
	{
		int dis = Q.front().first;
		int vx = Q.front().second.first;
		int vy = Q.front().second.second;
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = vx + dx[i];
			int ny = vy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0 || D[nx][ny] != -1 || D[nx][ny] == 0) continue;
			D[nx][ny] = dis+1;
			Q.push({ dis + 1, {nx,ny} });
		}
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			cout << D[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}