#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T, W;

int dp[31]; //dp[i]: i번 움직였을 때의 최대 자두 개수
//홀수면 2번나무, 짝수면 1번나무에 위치해있다.

int main()
{
	cin >> T >> W;
	int tree;
	while (T--)
	{
		cin >> tree;
		for (int i = 0; i <= W; i++)
		{
			if (tree == 1) //1번 나무에서 떨어짐
			{
				if (i == 0)
				{
					dp[i]++;
					continue;
				}
				if (i % 2 == 0) //1번나무에 위치
				{
					//움직여서 i번 되는 경우 vs 원래 i번인 경우
					dp[i] = max(dp[i], dp[i - 1]) + 1;
				}
				else //2번나무에 위치
				{
					//움직여서 i번 되는 경우 vs 원래 i번인 경우
					dp[i] = max(dp[i], dp[i - 1]);
				}
			}
			else //2번 나무에서 떨어짐
			{
				if (i == 0) continue;
				if (i % 2 == 0) //1번나무에 위치
				{
					dp[i] = max(dp[i], dp[i - 1]);
				}
				else //2번나무에 위치
				{
					dp[i] = max(dp[i], dp[i - 1]) + 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= W; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}

