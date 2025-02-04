#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[100'001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> dp[i];
		dp[i] = max(dp[i - 1] + dp[i], dp[i]);
	}
	int ans = dp[1];
	for (int i = 2; i <= N; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}