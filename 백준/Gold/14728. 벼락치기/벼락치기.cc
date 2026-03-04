#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[10'001]; // dp[i]: i시간동안 공부해서얻는 최대점수
ll ttime[101];
ll score[101];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, T;
	cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		cin >> ttime[i] >> score[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = T; j >= 0; j--)
		{
			if (j - ttime[i] < 0) continue;
			dp[j] = max(dp[j], dp[j - ttime[i]] + score[i]);
		}
	}
	ll ans = 0;
	for (int i = 0; i <= T; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}
