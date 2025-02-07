#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int walk_time[101];
int walk_money[101];

int bike_time[101];
int bike_money[101];

int dp[101][100'000]; //dp[i][j] : i번도시까지, j시간에 걸려 왔을 때의 모금액

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> walk_time[i] >> walk_money[i] >> bike_time[i] >> bike_money[i];
	}
	for (int i = 0; i <= K; i++)
	{
		dp[1][i] = -1;
	}
	if (walk_time[1] == bike_time[1])
	{
		dp[1][walk_time[1]] = max(walk_money[1], bike_money[1]);
	}
	else
	{
		dp[1][walk_time[1]] = walk_money[1];
		dp[1][bike_time[1]] = bike_money[1];
	}


	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{

			/////////////////////////////////////////////////
			if (1)
			{
				if (j - walk_time[i] >= 0 && j - bike_time[i] >= 0)
				{
					if (dp[i-1][j - walk_time[i]] != -1 && dp[i-1][j - bike_time[i]] != -1)
					{
						dp[i][j] = dp[i - 1][j - walk_time[i]] + walk_money[i];
						dp[i][j] = max(dp[i - 1][j - bike_time[i]] + bike_money[i], dp[i][j]);
						continue;
					}
					if (dp[i-1][j - walk_time[i]] != -1 && dp[i-1][j - bike_time[i]] == -1)
					{
						dp[i][j] = dp[i - 1][j - walk_time[i]] + walk_money[i];
						continue;
					}
					if (dp[i-1][j - walk_time[i]] == -1 && dp[i-1][j - bike_time[i]] != -1)
					{
						dp[i][j] = dp[i - 1][j - bike_time[i]] + bike_money[i];
						continue;
					}
					else
					{
						dp[i][j] = -1;
					}
				}

				if (j - walk_time[i] >= 0 && j - bike_time[i] < 0)
				{
					if (dp[i-1][j - walk_time[i]] != -1)
					{
						dp[i][j] = dp[i - 1][j - walk_time[i]] + walk_money[i];
						continue;
					}
					else
					{
						dp[i][j] = -1;
						continue;
					}
				}


				if (j - walk_time[i] < 0 && j - bike_time[i] >= 0)
				{
					//if (i == 2 && j == 500) cout << "fuck" << j - bike_time[i];
					if (dp[i-1][j - bike_time[i]] != -1)
					{
						dp[i][j] = dp[i - 1][j - bike_time[i]] + bike_money[i];
						//cout << dp[i][j] << '\n';
						continue;
					}
					else
					{
						dp[i][j] = -1;
						continue;
					}
				}

				else
				{
					dp[i][j] = -1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= K; i++)
	{
		ans = max(ans, dp[N][i]);
	}
	cout << ans;
	//cout << '\n';
	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 0; j <= K; j++)
	//	{
	//		if (dp[i][j] == -1) continue;
	//		cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << ' ';
	//	}cout << '\n';
	//}
}