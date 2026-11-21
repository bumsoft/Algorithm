#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;
using ll = long long;


ll D1[200'001];
ll D2[200'001];
vector<pair<int, ll>> vertex[200'001];
priority_queue<pair<ll, int>> PQ;
int N, M, A, B;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M >> A >> B;
	int a, b;
	ll c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(b, c));
		vertex[b].push_back(make_pair(a, c));
	}
	for (int i = 1; i <= N; i++)
	{
		D1[i] = INF;
		D2[i] = INF;
	}
	//A->B
	D1[A] = 0;
	PQ.push(make_pair(0, A));
	while (!PQ.empty())
	{
		int Ver = PQ.top().second;
		ll Cost = -PQ.top().first;
		PQ.pop();
		if (Cost > D1[Ver])continue;
		for (int i = 0; i < vertex[Ver].size(); i++)
		{
			int nextVer = vertex[Ver][i].first;
			ll nextCost = vertex[Ver][i].second;
			if (Cost + nextCost < D1[nextVer])
			{
				D1[nextVer] = Cost + nextCost;
				PQ.push(make_pair(-D1[nextVer], nextVer));
			}
		}
	}
	//B->A
	D2[B] = 0;
	PQ.push(make_pair(0, B));
	while (!PQ.empty())
	{
		int Ver = PQ.top().second;
		ll Cost = -PQ.top().first;
		PQ.pop();
		if (Cost > D2[Ver])continue;
		for (int i = 0; i < vertex[Ver].size(); i++)
		{
			int nextVer = vertex[Ver][i].first;
			ll nextCost = vertex[Ver][i].second;
			if (Cost + nextCost < D2[nextVer])
			{
				D2[nextVer] = Cost + nextCost;
				PQ.push(make_pair(-D2[nextVer], nextVer));
			}
		}
	}
	// D1과 D2
	vector<int> ans;
	ll dis = D1[B];
	for (int i = 1; i <= N; i++)
	{
		if (D1[i] + D2[i] == dis)ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (ll i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}