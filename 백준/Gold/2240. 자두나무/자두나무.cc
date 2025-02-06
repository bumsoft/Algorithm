#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//dp : 이동하거나 | 이동 안하거나
// dp[1000][30][2]
// 
// dp[i][j][k] : i초에 j번 움직였고 k나무에 있는 경우!

int arr[1001];

int dp[1001][31][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T, W;
	cin >> T >> W;
	for (int i = 1; i <= T; i++)
	{
		cin >> arr[i];
	}


	for (int i = 1; i <= T; i++)
	{
		for (int j = 0; j <= W; j++) //짝수라면, 1번나무 //홀수라면, 2번나무에 있음
		{
			//t가 j보다 작은경우??
			if (j == 0)
			{
				dp[i][j][1] = dp[i - 1][j][1];
				if (arr[i] == 1) dp[i][j][1]++;
				continue;
			}

			if (j % 2 == 0)//짝수
			{
				dp[i][j][1] = max(dp[i - 1][j - 1][2],dp[i - 1][j][1]);
				if (arr[i] == 1) dp[i][j][1]++;
			}
			else
			{
				dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]);
				if (arr[i] == 2) dp[i][j][2]++;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= W; i++)
	{

		ans = max(ans, dp[T][i][1]);
		ans = max(ans, dp[T][i][2]);
	}
	cout << ans;

	//for (int i = 1; i <= T; i++)
	//{
	//	for (int j = 0; j <= W; j++) //짝수라면, 1번나무 //홀수라면, 2번나무에 있음
	//	{
	//		cout << "dp[" << i << "][" << j << "][1]=" << dp[i][j][1] << ' ';
	//		cout << "dp[" << i << "][" << j << "][2]=" << dp[i][j][2] << '\n';
	//	}
	//}

	return 0;
}