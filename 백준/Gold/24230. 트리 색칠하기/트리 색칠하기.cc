#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
vector<int> node[200'001];
int now[200'001];
int final[200'001];
bool vis[200'001];
int ans;
void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> final[i];
	}
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
}
void cal()
{
	if (now[1] != final[1])
	{
		ans++;
		now[1] = final[1];
	}
	for (int i = 1; i <= N; i++)
	{
		vis[i] = true;
		for (int j = 0; j < node[i].size(); j++)
		{
			int next = node[i][j];
			if (vis[next])continue;
			now[next] = final[i];
			if (final[next] != final[i])
			{
				now[next] = final[next];
				ans++;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	input();
	cal();
	cout << ans;
	return 0;
 }