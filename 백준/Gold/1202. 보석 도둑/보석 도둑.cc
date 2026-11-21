#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, K;
priority_queue<pair<int, int>> PQ;
multiset<int> s;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> K;
	int m, v;
	for (int i = 0; i < N; i++)
	{
		cin >> m >> v;
		PQ.push(make_pair(v, m));
	}
	int c;
	for (int i = 0; i < K; i++)
	{
		cin >> c;
		s.insert(c);
	}
	ll ans = 0;
	while (!PQ.empty() && !s.empty())
	{
		int price = PQ.top().first;
		int weight = PQ.top().second;
		PQ.pop();
		auto temp = s.lower_bound(weight);
		if (temp == s.end())continue;
		s.erase(temp);
		ans += price;
	}
	cout << ans;
	return 0;
}