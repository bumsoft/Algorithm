#include <bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	while (n--)
	{
		unordered_map<ll, int> m;

		int max_cnt = 0;
		ll max_num = 0;

		int num; cin >> num;
		ll t;
		for (int i = 0; i < num; i++)
		{
			cin >> t;
			int cur = ++m[t];
			if (cur > max_cnt)
			{
				max_cnt = cur;
				max_num = t;
			}
		}

		if (max_cnt * 2 > num) cout << max_num << '\n';
		else cout << "SYJKGW\n";

	}
	
	return 0;
}
