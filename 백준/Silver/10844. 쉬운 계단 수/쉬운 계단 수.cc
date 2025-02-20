#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1'000'000'000
int N;

ll dp[101][10];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[1][3] = 1;
	dp[1][4] = 1;
	dp[1][5] = 1;
	dp[1][6] = 1;
	dp[1][7] = 1;
	dp[1][8] = 1;
	dp[1][9] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j + 1] % MOD;
				continue;
			}
			if (j == 9)
			{
				dp[i][j] = dp[i - 1][j - 1] % MOD;
				continue;
			}
			dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % MOD;
		}
	}
	ll ans = 0;
	for (int j = 0; j <= 9; j++)
	{
		ans += dp[N][j] % MOD;
		ans %= MOD;
	}
	cout << ans;


	return 0;
}