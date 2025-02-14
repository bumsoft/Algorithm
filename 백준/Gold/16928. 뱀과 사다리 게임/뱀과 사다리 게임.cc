#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// dp[i] : i번에 오기위한 최소 횟수.
// dp[i] = min(dp[i], dp[i-1], i-2, i-3, i-4, i-5, i-6)
// i가 사다리 또는 뱀이라면? => dp[i] = INF, dp[목적지] = min(dp[i-1,i-2,...i-6]) + 1

int dp[101];
int r[101];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		r[a] = b;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		r[a] = b;
	}
	for (int i = 1; i <= 100; i++)
	{
		dp[i] = INT_MAX;
	}
	dp[1] = 0;

	for (int i = 2; i <= 7; i++)
	{
		if (r[i] == 0) dp[i] = 1;
		else if (r[i] > i) //사다리
		{
			dp[i] = INT_MAX;
			dp[r[i]] = 1;
		}
		else
		{
			dp[i] = INT_MAX;
			dp[r[i]] = 1;
		}
	}

	for (int i = 8; i <= 100; i++)
	{
		if (dp[i] != INT_MAX) continue;

		if (r[i] != 0)
		{
			//사다리
			if (r[i] > i)
			{
				dp[r[i]] = min(dp[i], min(dp[i - 1], min(dp[i - 2], min(dp[i - 3], min(dp[i - 4], min(dp[i - 5], dp[i - 6]))))) + 1);
			}
			//뱀
			else
			{
				dp[i] = INT_MAX;
				//뱀 도착지점
				dp[r[i]] = min(dp[r[i]], min(dp[i], min(dp[i - 1], min(dp[i - 2], min(dp[i - 3], min(dp[i - 4], min(dp[i - 5], dp[i - 6])))))) + 1);
			}
		}
		else
		{
			dp[i] = min(dp[i], min(dp[i - 1], min(dp[i - 2], min(dp[i - 3], min(dp[i - 4], min(dp[i - 5], dp[i - 6]))))) + 1);
		}
	}
	//이 상태에서, 각 칸에 도착하는 최소 횟수가 저장됨. 여기서 다시 dp
	for (int i = 2; i <= 100; i++)
	{
		if (dp[i] == INT_MAX)
		{
			//사다리라면?

			int n = 7;
			while (n--)
			{
				if (i - n <= 1) continue;
				if (dp[i - n] == INT_MAX)continue;
				dp[r[i]] = min(dp[r[i]], dp[i - n] + 1);
			}
			continue;
		}
		int n = 7;
		while (n--)
		{
			if (i - n <= 1) continue;
			if (dp[i - n] == INT_MAX)continue;
			dp[i] = min(dp[i], dp[i - n]+1);
		}
	}
	cout << dp[100];
}