#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int walk_time[101];
int walk_money[101];

int bike_time[101];
int bike_money[101];

int dp[101][100'000]; //dp[i][j] : i번도시까지, j시간에 걸려 왔을 때의 모금액 => i-1번 도시에서 j-(i번소요시간) 시간 + i번금액 // i-1번 도시에서 j-(i번자전거소요시갼)시간 + i번자전거금액

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> walk_time[i] >> walk_money[i] >> bike_time[i] >> bike_money[i];
	}

	dp[1][walk_time[1]] = walk_money[1];
	dp[1][bike_time[1]] = bike_money[1];
	if (walk_time[1] == bike_time[1])
	{
		dp[1][walk_time[1] = max(walk_money[1], bike_money[1])];
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (j - walk_time[i] >= 0 && j - bike_time[i] >= 0)
			{
				if (dp[i - 1][j - walk_time[i]] && dp[i - 1][j - bike_time[i]]) dp[i][j] = max(dp[i - 1][j - walk_time[i]] + walk_money[i], dp[i - 1][j - bike_time[i]] + bike_money[i]);
				else if (dp[i - 1][j - walk_time[i]]) dp[i][j] = dp[i - 1][j - walk_time[i]] + walk_money[i];
				else if (dp[i - 1][j - bike_time[i]]) dp[i][j] = dp[i - 1][j - bike_time[i]] + bike_money[i];
			}
			else if (j - walk_time[i] >= 0 && j - bike_time[i] < 0 && dp[i-1][j-walk_time[i]]) dp[i][j] = dp[i - 1][j - walk_time[i]] + walk_money[i];
			else if (j - walk_time[i] < 0 && j - bike_time[i] >= 0 && dp[i-1][j-bike_time[i]]) dp[i][j] = dp[i - 1][j - bike_time[i]] + bike_money[i]; 
		}
	}
	int ans = 0;
	for (int i = 0; i <= K; i++)
	{
		ans = max(dp[N][i], ans);
	}
	cout << ans;
}