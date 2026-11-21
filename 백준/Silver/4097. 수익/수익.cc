#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[250'001];
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	while (cin >> N)
	{
		if (N == 0) return 0;
		for (int i = 0; i < N; i++)
		{
			cin >> dp[i];
		}
		for (int i = 1; i < N; i++)
		{
			dp[i] = max(dp[i - 1] + dp[i], dp[i]);
		}
		ll maxx = -10001;
		for (int i = 0; i < N; i++)
		{
			maxx = max(maxx, dp[i]);
		}
		cout << maxx << '\n';
	}
}