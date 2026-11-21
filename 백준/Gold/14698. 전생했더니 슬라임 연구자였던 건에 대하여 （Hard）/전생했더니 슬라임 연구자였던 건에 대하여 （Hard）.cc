#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int T, N;
	cin >> T;
	while (T--)
	{
		priority_queue<ll> PQ;
		ll a, t, tt, sum = 1;
		cin >> N;
		while (N--)
		{
			cin >> a;
			PQ.push(-a);
		}
		while (PQ.size()>1)
		{
			t = -PQ.top(); PQ.pop();
			tt = -PQ.top(); PQ.pop();
			ll s = ((t % 1000000007) * (tt % 1000000007)) % 1000000007;
			PQ.push(-(t * tt));
			sum *= s;
			sum %= 1000000007;
		}
		cout << sum << '\n';
	}
	return 0;
}