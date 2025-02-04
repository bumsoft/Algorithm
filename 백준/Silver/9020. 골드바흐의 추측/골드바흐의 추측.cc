#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> prime;
bool p[10'001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 2; i < 10'000; i++)
	{
		if (p[i]) continue;
		for (int j = 2; i * j < 10'000; j++)
		{
			p[i * j] = true;
		}
	}
	for (int i = 2; i < 10'000; i++)
	{
		if (!p[i]) prime.push_back(i);
	}
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int ans = 0;
		int a, b;
		for (int i = 0; i < prime.size(); i++)
		{
			if (prime[i] > N / 2) break;
			if (!p[N - prime[i]])
			{
				a = prime[i];
				b = N - prime[i];
			}
		}
		cout << a<<' '<<b << '\n';
	}
	return 0;
}