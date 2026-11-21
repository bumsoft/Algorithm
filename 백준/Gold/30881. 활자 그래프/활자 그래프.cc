#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll D[200'001];
ll save_D2[200'001];
ll save_D2_1[200'001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T, v_num, q_num, v, w;
	ll x, xx;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		cin >> v_num >> q_num;
		vector<vector<pair<int, ll>>> vertex(v_num + 1);
		for (int i = 1; i <= v_num; i++)D[i] = LLONG_MAX;
		
		for (int q = 0; q < q_num; q++) //간선추가.
		{
			cin >> v >> w >> xx;
			if (xx < 0)
			{
				x = save_D2[abs(xx)];
				if (x <= 1'000'000'000'000'000'000)
				{
					vertex[v].push_back({ w,x });
				}
				x = save_D2_1[abs(xx)];
				if (x <= 1'000'000'000'000'000'000)
				{
					vertex[w].push_back({ v,x });
				}

			}
			else vertex[v].push_back({ w,xx });
		} //end of making graph
		//start dijkstra;
		priority_queue<pair<ll, int>> PQ;
		PQ.push({ 0,1 });
		D[1] = 0;
		while (!PQ.empty())
		{
			int Ver = PQ.top().second;
			ll Cost = -PQ.top().first;
			PQ.pop();
			if (Ver == 2) break;

			if (Cost > 1'000'000'000'000'000'000) continue;
			if (Cost > D[Ver]) continue;
			if (D[Ver] > 1'000'000'000'000'000'000)continue;
			for (int i = 0; i < vertex[Ver].size(); i++)
			{
				int nextVer = vertex[Ver][i].first;
				ll nextCost = vertex[Ver][i].second;

				if (D[Ver] + nextCost < D[nextVer])
				{
					D[nextVer] = D[Ver] + nextCost;
					PQ.push({-D[nextVer], nextVer});
				}
			}
		}
		save_D2[t] = D[2];
		priority_queue<pair<ll, int>> PQ2;
		PQ2.push({ 0,2 });
		for (int i = 1; i <= v_num; i++)D[i] = LLONG_MAX;
		D[2] = 0;
		while (!PQ2.empty())
		{
			int Ver = PQ2.top().second;
			ll Cost = -PQ2.top().first;
			PQ2.pop();
			if (Ver == 1) break;
			if (Cost > 1'000'000'000'000'000'000) continue;
			if (Cost > D[Ver]) continue;
			if (D[Ver] > 1'000'000'000'000'000'000)continue;
			for (int i = 0; i < vertex[Ver].size(); i++)
			{
				int nextVer = vertex[Ver][i].first;
				ll nextCost = vertex[Ver][i].second;

				if (D[Ver] + nextCost < D[nextVer])
				{
					D[nextVer] = D[Ver] + nextCost;
					PQ2.push({ -D[nextVer], nextVer });
				}
			}
		}
		save_D2_1[t] = D[1];
	}
	if (save_D2[T] > 1'000'000'000'000'000'000) cout << -1;
	else cout << save_D2[T];
	return 0;
}
