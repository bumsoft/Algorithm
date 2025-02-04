#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
int board[1001][1001];

int dx[] = { -1,0,-1 };
int dy[] = { 0,-1,-1 };

int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = board[i][j];
			//이전에서 가장 큰 것 선택
			for (int k = 0; k < 3; k++)
			{
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (ni <= 0 || nj <= 0) continue;

				dp[i][j] = max(board[i][j] + dp[ni][nj], dp[i][j]);
			}
		}
	}
	cout << dp[N][M];
	return 0;
}