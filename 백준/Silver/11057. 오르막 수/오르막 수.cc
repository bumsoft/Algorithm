#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int dp[1001][10];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;

	//dp[0] 모두 0
	//1자리일때 i로 끝나는 개수
	for (int i = 0; i <=9; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int l = j; l <= 9; l++)
			{
				dp[i][j] += dp[i - 1][l];
				dp[i][j] %= 10007;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans += dp[N][i];
		ans %= 10007;
	}
	cout << ans;
	return 0;
}