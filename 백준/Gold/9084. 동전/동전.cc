#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int coin[21];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)cin >> coin[i];
		cin >> M;
		int dp[10'001]{};
		dp[0] = 1;
		for (int i = 1; i <= N; i++)
		{
			for (int j = coin[i]; j <= M; j++)
			{
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[M] << '\n';
	}

	return 0;
}