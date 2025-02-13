#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
using ll = long long;

int N;
int R[1001];
int G[1001];
int B[1001];

ll dp[1001][3];
ll ans;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> R[i] >> G[i] >> B[i];
	}
	//0번집을 고정시키고 dp
	//빨강
	dp[0][0] = R[0];
	dp[0][1] = INF;
	dp[0][2] = INF;
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R[i];

		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G[i];

		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B[i];
	}
	ans = min(dp[N - 1][1], dp[N - 1][2]);

	//초록
	dp[0][0] = INF;
	dp[0][1] = G[0];
	dp[0][2] = INF;
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R[i];

		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G[i];

		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B[i];
	}
	ans = min({ ans, dp[N - 1][0], dp[N - 1][2] });

	//파랑
	dp[0][0] = INF;
	dp[0][1] = INF;
	dp[0][2] = B[0];
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R[i];

		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G[i];

		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B[i];
	}
	ans = min({ ans, dp[N - 1][0], dp[N - 1][1] });
	cout << ans;
	return 0;
}