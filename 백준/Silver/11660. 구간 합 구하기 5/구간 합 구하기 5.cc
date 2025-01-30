#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;

int board[1025][1025];
ll dp[1025][1025];
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
			dp[i][j] = board[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	int x1, x2, y1, y2;
	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
	}
}