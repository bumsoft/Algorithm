#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;

bool f[10];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	int t;
	for (int i = 0; i < M; i++)
	{
		cin >> t;
		f[t] = true;
	}
	if (M == 10 || N==100)
	{
		cout << abs(100 - N);
		return 0;
	}

	int ans = abs(100 - N);

	string s;
	for (int i = 0; i<1'000'000; i++)
	{
		bool ck = false;
		s = to_string(i);
		for (int j = 0; j < s.length(); j++)
		{
			if (f[s[j] - 48])
			{
				ck = true;
				break;
			}
		}
		if (ck) continue;
		int b = ans;
		ans = min(ans, (int)s.length() + abs(i - N));
	}
	cout << ans;
}