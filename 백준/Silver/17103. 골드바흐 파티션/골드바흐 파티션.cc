#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> prime;
bool p[1'000'001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 2; i < 1'000'000; i++)
	{
		if(p[i]) continue;
		for (int j = 2; i*j<1'000'000; j++)
		{
			p[i * j] = true;
		}
	}
	for (int i = 2; i < 1'000'000; i++)
	{
		if (!p[i]) prime.push_back(i);
	}
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int ans = 0;

		for (int i = 0; i<prime.size(); i++)
		{
			if (prime[i] > N/2) break;
			if (!p[N - prime[i]]) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}