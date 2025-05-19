#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;

int burger[101];
int potato[101];

//남은 버거와 감자를 이용한 최대 주문 개수
int dp[301][301]; //dp[i][j]: 남은버거i, 남은감자j개 일 때 처리한 최대 주문수

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> burger[i] >> potato[i];
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = M; j >= 0; j--) //버거
		{
			if (j - burger[i] < 0) continue;
			for (int k = K; k >= 0; k--) //감자
			{
				if (k - potato[i] < 0) continue;

				dp[j][k] = max(dp[j][k], dp[j - burger[i]][k - potato[i]] + 1);

			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= M; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;


	return 0;
}
