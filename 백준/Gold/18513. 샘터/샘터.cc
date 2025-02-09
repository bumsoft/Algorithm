#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K;
queue<pair<int,ll>> Q;
bool vis[200'300'001];

ll ans;
int cnt;
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	int t;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		Q.push({ t + 100'110'000,0 });
		vis[t + 100'110'000] = true;
	}
	cnt = -N;
	while (!Q.empty())
	{
		int loc = Q.front().first;
		ll cost = Q.front().second;
		ans += cost;
		cnt++;
		Q.pop();

		if (cnt == K) break;

		if (!vis[loc - 1])
		{
			vis[loc - 1] = true;
			Q.push({ loc - 1, cost + 1 });
		}
		if (!vis[loc + 1])
		{
			vis[loc + 1] = true;
			Q.push({ loc + 1, cost + 1 });
		}
	}
	cout << ans;
	return 0;
}