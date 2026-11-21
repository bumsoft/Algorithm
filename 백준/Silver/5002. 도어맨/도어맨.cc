#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int ans;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int X;
	cin >> X;

	cin >> s;

	int m = 0;
	int w = 0;
	for (int i = 0; i < s.length(); i++)
	{
		char n1 = s[i];
		int tm = m;
		int tw = w;

		//첫번째 입장시 차이
		if (n1 == 'M')
		{
			tm++;
		}
		else
		{
			tw++;
		}
		if (abs(tm - tw) <= X)
		{
			m = tm;
			w = tw;
			ans++;
			continue;
		}
		tm = m;
		tw = w;
		//두번째 입장시 차이
		if (i + 1 < s.length())
		{
			char n2 = s[i + 1];
			if (n2 == 'M')
			{
				tm++;
			}
			else
			{
				tw++;
			}
			if (abs(tm - tw) <= X)
			{
				m = tm;
				w = tw;
				ans++;

				s[i + 1] = s[i];
				continue;
			}
			else
			{
				break;
			}
		}


	}
	cout << ans;


	return 0;
}