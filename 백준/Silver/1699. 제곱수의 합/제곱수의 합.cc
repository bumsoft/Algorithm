#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[100'001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j <= sqrt(i); j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[N];

	return 0;
}