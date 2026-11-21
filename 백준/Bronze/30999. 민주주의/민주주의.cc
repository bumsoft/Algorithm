#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, M, ans = 0;
	cin >> N >> M;
	string t;
	while (N--)
	{
		cin >> t;
		int o = 0;
		for (int i = 0; i < t.length(); i++)
		{
			if (t[i] == 'O')o++;
		}
		if (o > M / 2)ans++;
	}
	cout << ans;
}