#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	int ans = 0;
	int num = 0;
	bool isCut = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			if (s[i + 1] == ')')
			{
				ans += num;
				i++;
			}
			else
			{
				num++;
			}
		}
		else
		{
			num--;
			ans++;
		}
	}
	cout << ans;
	return 0;
}