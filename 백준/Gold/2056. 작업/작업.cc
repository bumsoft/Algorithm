#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int dp[10'001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int a, b;
	for (int i = 1; i <= N; i++)
	{
		cin >> a >> b;
		int t;
		dp[i] = 0;
		while (b--)
		{
			cin >> t;
			dp[i] = max(dp[t], dp[i]);
		}
		dp[i] += a;
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		ans = max(dp[i], ans);
	}cout << ans;
	return 0;
}