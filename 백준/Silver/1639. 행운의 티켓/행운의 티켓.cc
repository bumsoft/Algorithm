#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.length() - 1; i++) //시작위치
	{
		for (int j = 2; i + j <= s.length(); j+=2)
		{
			string t = s.substr(i, j);
			int f = 0;
			int b = 0;
			for (int k = 0; k < j / 2; k++)
			{
				f += t[k] - 48;
				b += t[t.length() - k - 1] - 48;
			}
			if (f == b) ans = max(ans, j);
		}
	}
	cout << ans;
	return 0;
}