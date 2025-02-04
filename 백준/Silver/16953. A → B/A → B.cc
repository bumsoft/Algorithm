#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bitset<1'000'000'001> vis;
//BFS
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll A, B;
	cin >> A >> B;
	queue<pair<ll, int>> Q;
	Q.push({ A,0 });

	while (!Q.empty())
	{
		ll now = Q.front().first;
		int cost = Q.front().second;
		Q.pop();
		if (now > B) continue;
		if (vis[now]) continue;
		vis[now] = 1;
		if (now == B)
		{
			cout << cost + 1;
			return 0;
		}

		Q.push({ now * 2, cost + 1 });
		Q.push({ now * 10 + 1, cost + 1 });
	}
	cout << -1;
	return 0;
}