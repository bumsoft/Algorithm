#include <bits/stdc++.h>
#define INF 2'100'000'000
using namespace std;

int N, K;
int dp[10'001];
int arr[101];
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i <= K; i++)
	{
		dp[i] = INF;
	}
	dp[0] = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] <= K)
		{
			dp[arr[i]] = 1;
		}
	}
	for (int i = 0; i <= K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[j]+i > K)continue;
			dp[i + arr[j]] = min(dp[i + arr[j]], dp[i] + 1);
		}
	}
	if (dp[K] >= INF)cout << -1;
	else cout << dp[K];
}