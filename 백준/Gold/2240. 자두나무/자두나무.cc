#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T, W;

int dp[1001][31]; // [i][j]: i시간에 j번 움직였을 때 최대 개수

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T >> W;
	int t;
	for (int i = 1; i <= T; i++) //시간
	{
		cin >> t;

		for (int j = 0; j <= W; j++) //움직임
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j];
				if (t == 1) dp[i][j]++;
				continue;
			}
			if (j % 2 == 0) //1번에 위치
			{
				//i초에 j번 움직여서 1번에 있으려면? i-1초에 j-1번 움직여서 2번에 있어야함
				//								또는 i-1초에 j번 움직였음
				dp[i][j] = max(dp[i - 1][j - 1], dp[i-1][j]);
				if (t == 1) dp[i][j]++;
			}
			else //2번에 위치
			{
				//i초에 j번 움직여서 2번에 있으려면? i-1초에 j-1번 움직여서 1번에 있어야함.
				//								또는 i-1초에 j번 움직였음
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
				if (t == 2) dp[i][j]++;
			}
		}
	}
	int max_ = 0;
	for (int i = 0; i <= W; i++)
	{
		max_ = max(max_, dp[T][i]);
	}
	cout << max_;
}