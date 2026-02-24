#include <bits/stdc++.h>

using namespace std;

int n;
// x 1 2 3
int dp[10'000][3]; // dp[i][j] : i번째 잔에서, 이번 걸 j번째로 마실 때 최대값

// dp[10][0] : 10번째거를 안마셨을 때 = max(dp[9][0], dp[9][1], dp[9][2], dp[9][3]) + t
// dp[10][1] : 10번째거를 1번째로 마셨을 때 = dp[9][0] + t
// dp[10][2] : 10번째거를 2번째로 마셨을 때 = dp[9][1] + t
// dp[10][3] : 10번째거를 3번째로 마셨을 때 = dp[9][2] + t

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int t;
	cin >> t;
	dp[0][0] = 0;
	dp[0][1] = t;
	dp[0][2] = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> t;
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = t + dp[i - 1][0];
		dp[i][2] = t + dp[i - 1][1];
	}
	int ans = 0;
	for (int i = 0; i < 3; i++)
	{
		ans = max(ans, dp[n - 1][i]);
	}
	cout << ans;
	return 0;
}