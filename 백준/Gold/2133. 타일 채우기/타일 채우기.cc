#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[31];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	dp[0] = 1;
	for (int i = 2; i <= N; i+=2)
	{
		dp[i] += dp[i - 2] * 3;
		for (int j = i; j > 2; j -= 2)
		{
			dp[i] += dp[i - j] * 2;
		}
	}
	cout << dp[N];

	return 0;
}
