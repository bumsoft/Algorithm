#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
using ll = long long;


ll vertex[11][11];
int N=9, M;

int vis[11];
bool vi[11];
ll ans;
void backtracking(int now)
{
	//cout << now;
	if (now == N+1)
	{
		ll temp = 0;
		//for (int i = 0; i <= N; i++)
		//{
		//	cout << vis[i] << ' ';
		//}
		//cout << '\n';
		for (int i = 0; i <= N; i++)
		{
			if (vertex[vis[i]][vis[i + 1]]==-1)
			{
				return;
			}
			temp += vertex[vis[i]][vis[i + 1]];
		}
		ans = max(temp, ans);
	}

	for (int i = 1; i <= N; i++)
	{
		if (vi[i])continue;
		vi[i] = true;
		vis[now] = i;
		backtracking(now + 1);
		vi[i] = false;
		//backtracking(now+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			vertex[i][j] = -1;
		}
	}
	int u, v;
	ll d;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> d;
		vertex[u][v] = max(d, vertex[u][v]);
	}
	backtracking(1);
	if (ans == 0) cout << -1;
	else cout << ans;


	return 0;
}