#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int C, N;
int money[21], value[21];
int dp[21][100'001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> C >> N;
	for (int i = 1; i <= N; i++)cin >> money[i] >> value[i];
	int ans = 1000000;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0;; j++)
		{
			if (money[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - money[i]] + value[i]);
			if (dp[i][j] >= C)
			{
				ans = min(ans, j);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}