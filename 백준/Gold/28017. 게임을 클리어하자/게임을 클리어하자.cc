#include <bits/stdc++.h>

using namespace std;

//직전 회차 무기만 사용하지 않으면 됨
int N, M;
vector<int> V[501];
int dp[501][501];

pair<int,int> last[501][2];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int t;
	last[0][0].first = INT_MAX;
	last[0][1].first = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> t;
			V[i].push_back(t);
			if (i == 0)
			{
				dp[0][j] = t;

				if (t < last[0][0].first)
				{
					last[0][1] = last[0][0];
					last[0][0] = { t, j };
				}
				else if (t == last[0][0].first)
				{
					last[0][1] = { t,j };
				}
				else if (t < last[0][1].first)
				{
					last[0][1] = { t,j };
				}
			}
		}
	}
	//cout << '\n';
	//cout << last[0][0].first << '\n';
	//cout << last[0][1].first << '\n';
	for (int i = 1; i < N; i++)
	{
		pair<int, int> last_first = last[i - 1][0];
		pair<int, int> last_second = last[i - 1][1];

		last[i][0].first = INT_MAX;
		last[i][1].first = INT_MAX;
		for (int j = 0; j < M; j++)
		{
			if (j != last_first.second)
			{
				dp[i][j] = last_first.first + V[i][j];
			}
			else
			{
				dp[i][j] = last_second.first + V[i][j];
			}

			if (dp[i][j] < last[i][0].first)
			{
				last[i][1] = last[i][0];
				last[i][0] = { dp[i][j], j };
			}
			else if (dp[i][j] == last[i][0].first)
			{
				last[i][1] = { dp[i][j],j };
			}
			else if (dp[i][j] < last[i][1].first)
			{
				last[i][1] = { dp[i][j],j };
			}
		}
	}
	cout << last[N - 1][0].first;

	return 0;
}