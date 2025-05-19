#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int cost[21];
int value[21];

int dp[101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> value[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 100; j >= 0; j--)
		{
			if (j - cost[i] < 0) continue;
			dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) ans = max(ans, dp[i]);
	cout << ans;

	return 0;
}
