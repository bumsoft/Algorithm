#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<string, priority_queue<int>> m;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int Q;
	cin >> Q;

	int q;
	string name;
	int num;
	int cost;

	ll ans = 0;
	while (Q--)
	{
		cin >> q;
		cin >> name;
		cin >> num;

		if (q == 1) //고릴라 정보
		{
			priority_queue<int> pq = m[name];
			while (num--)
			{
				cin >> cost;
				pq.push(cost);
			}
			m[name] = pq;

		}
		else //구매
		{
			priority_queue<int> pq = m[name];
			while (num--)
			{
				if (pq.empty()) break;
				ans += pq.top();
				pq.pop();
			}
			m[name] = pq;
		}
	}
	cout << ans;

	return 0;
}