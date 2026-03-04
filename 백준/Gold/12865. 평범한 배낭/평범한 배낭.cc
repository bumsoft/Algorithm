#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int W[101];
int V[101];

int dp[100'001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> W[i] >> V[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = K; j >= 0; j--)
		{
			if (j - W[i] < 0) continue;
			dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= K; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}
