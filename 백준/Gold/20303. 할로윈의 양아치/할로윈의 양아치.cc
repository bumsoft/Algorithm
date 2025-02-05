#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;
int candy[30'001];
vector<int> fr[30'001];
bool vis[30'001];
vector<pair<int, int>> save; //<candy, kidsm>
int sum;

int dp[30001][3001];

bool vis2[30'001];
int dfs(int s)
{
	int get = candy[s];
	sum++;
	for (int i = 0; i < fr[s].size(); i++)
	{
		if (vis[fr[s][i]]) continue;
		vis[fr[s][i]] = 1;
		get += dfs(fr[s][i]);
	}
	return get;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> candy[i];
	}
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		fr[a].push_back(b);
		fr[b].push_back(a);
	}
	save.push_back({ 0,0 });
	//dfs
	for (int i = 1; i <= N; i++)
	{
		if (vis[i]) continue;
		sum = 0;
		vis[i] = 1;
		int get = dfs(i);
		save.push_back({ get, sum });
	}

	//dp[i][j]: i번 그룹 선택ox, [j]명 울었을 때 최대값;
	for (int i = 1; i < save.size(); i++)
	{
		for (int j = 1; j < K; j++)
		{
			if (save[i].second > j) //i그룹 선택 못하는 경우
			{
				dp[i][j] = dp[i - 1][j];
			}
			else // 선택 가능한 경우, 1. 선택 안하는 경우와 2. 선택 하는 경우 중 선택
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - save[i].second] + save[i].first);
			}
		}
	}
	cout << dp[save.size() - 1][K - 1];

	return 0;
}