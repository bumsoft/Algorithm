#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool board[101][101];
int N, M, K;
int cnt;
void dfs(int i, int j)
{
	board[i][j] = true;
	cnt++;
	for (int l = 0; l < 4; l++)
	{
		int di = i + dx[l];
		int dj = j + dy[l];
		if (di >= N || di < 0 || dj >= N || dj < 0)continue;
		if (board[di][dj])continue;
		dfs(di, dj);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!board[i][j])
			{
				cnt = 0;
				dfs(i, j);
				if (cnt % K == 0)ans += cnt / K;
				else ans += cnt / K + 1;
			}
		}
	}
	if (ans == 0)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}
	ans = M - ans;
	if (ans < 0)cout << "IMPOSSIBLE";
	else
	{
		cout << "POSSIBLE\n" << ans;
	}
}