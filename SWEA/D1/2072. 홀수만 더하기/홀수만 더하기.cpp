#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for(int i=1;i<=t;i++)
	{
		int ans = 0;
		for (int j = 0; j < 10; j++)
		{
			int a; cin >> a;
			if (a % 2 == 0) continue;
			ans += a;
		}
		cout << "#" << i << " " << ans << '\n';
	}

	return 0;
}