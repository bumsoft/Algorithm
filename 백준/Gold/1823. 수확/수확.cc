#include <bits/stdc++.h>

using namespace std;

// 남은 구간을 상태로 보는 DP
int v[2001];
int dp[2001][2001]; // dp[i][j] : i 부터 j까지 남았을 때


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int t;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	
	for (int len = 1; len <= N; len++)
	{
		for (int l = 0; l <= N - len; l++)
		{
			int r = l + len - 1;
			int k = N - len + 1;

			if (l == r)
			{
				dp[l][r] = v[l] * k;
			}
			else
			{
				dp[l][r] = max(dp[l + 1][r] + v[l] * k, dp[l][r - 1] + v[r] * k);
			}
		}
	}
	cout << dp[0][N - 1];

	return 0;
}
