#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cost[1001];


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	int N, K, X, Y, W;
	while (T--)
	{
		vector<int> E[1001];
		int degree[1001];
		queue<pair<int, int>> Q; // <정점,이전까지비용>
		int save[1001];
		cin >> N >> K;

		for (int i = 1; i <= N; i++)
		{
			cin >> cost[i];
			degree[i] = 0;
			save[i] = -1;
		}
		while (K--)
		{
			cin >> X >> Y;
			E[X].push_back(Y);
			degree[Y]++;
		}
		cin >> W;
		int mem = degree[W];
		for (int i = 1; i <= N; i++) //진입차수 0인 정점 모두 PUSH!
		{
			if (degree[i] == 0)
			{
				Q.push({ i,0 });
			}
		}
		int ans = -1;
		while (!Q.empty())
		{
			int v = Q.front().first;
			int c = Q.front().second;
			Q.pop();
			if (v == W)
			{
				mem--;
				ans = max(ans, c + cost[v]);
				if (mem == 0) break;
				continue;
			}
			for (int i = 0; i < E[v].size(); i++)
			{
				degree[E[v][i]]--; //간선 삭제

				save[E[v][i]] = max(save[E[v][i]], c + cost[v]);

				if (degree[E[v][i]] == 0)//E[v][i]의 진입차수가 0이라면?
				{
					//가장 큰 값으로 넣기
					Q.push({ E[v][i], save[E[v][i]] });
				}
			}
		}
		cout << ans << '\n';
	}

}