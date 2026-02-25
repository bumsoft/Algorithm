#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//1번에서 가장 먼 곳까지의 거리, 트리임

vector<pair<int,ll>> v[5001];
bool vis[5001];
ll ans = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;
	int A, B;
	ll C;
	for (int i = 1; i < N; i++)
	{
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
		v[B].push_back({ A,C });
	}
	queue<pair<int, ll>> Q;
	Q.push({ 1,0 });
	vis[1] = 1;
	while (!Q.empty())
	{
		int room = Q.front().first;
		ll dis = Q.front().second;
		Q.pop();
		ans = max(ans, dis);
		for (int i = 0; i < v[room].size(); i++)
		{
			int next_room = v[room][i].first;
			if (vis[next_room])continue;
			vis[next_room] = 1;
			ll next_dis = v[room][i].second;
			Q.push({ next_room, next_dis + dis });
		}
	}
	cout << ans;
	return 0;
}
