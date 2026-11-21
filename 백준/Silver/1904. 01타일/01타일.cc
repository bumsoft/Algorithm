#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
dp[n] = dp[n-1] + dp[n-2];
끝에 1이 오는 경우, n-1자리 == dp[n-1]
끝에 00이 오는 경우, n-2자리 == dp[n-2]

*/

int dp[1'000'001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	ll ans = 0;
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[N];
	return 0;
}