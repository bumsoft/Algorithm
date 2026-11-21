#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//메모리 : 
//비용 : 
// 
// 비용이 최소가 되면서 메모리를 M이상
// 가치가 최대가 되면서 무게가 M이하로

// => 메모리가 최대가 되면서, 비용이 최소가 되도록 dp?
// 무게 = 비용에 대해.

int N, M;
int memory[101];
int cost[101];

int dp[101][10001];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)cin >> memory[i];
	for (int i = 1; i <= N; i++)cin >> cost[i];
	int ans = INT_MAX;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 10000; j++) //비용
		{
			//비용별 최대의 메모리를 저장한다.
			if (cost[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i-1][j - cost[i]] + memory[i]);

			//cout << "dp[" << i << "][" << j << "]=" << dp[i][j] << endl;

			if (dp[i][j] >= M)
			{
				ans = min(j, ans);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}