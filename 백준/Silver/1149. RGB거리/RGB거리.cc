#include <bits/stdc++.h>
using namespace std;
int N;
int R[1001];
int G[1001];
int B[1001];
int dp[1001][3]; //[i][r,g,b] : i번째집을 각각 r, g, b 로 칠했을 때 최소값
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> R[i] >> G[i] >> B[i];
	dp[1][0] = R[1];
	dp[1][1] = G[1];
	dp[1][2] = B[1];
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G[i];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B[i];
	}
	cout << min({ dp[N][0],dp[N][1],dp[N][2] });
	return 0;
}