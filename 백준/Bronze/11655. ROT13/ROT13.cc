#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//A 65 Z 90
//a : 97
//z : 122
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	char t;
	while (cin.get(t))
	{
		if (t == 32)
		{
			cout << ' ';
			continue;
		}
		int i = t;
		if (i >= 'A' && i <= 'Z')
		{
			i += 13;
			if (i > 'Z')
			{
				cout << char(i - 26);
			}
			else cout << char(i);
		}
		else if ((i >= 'a' && i <= 'z'))
		{
			i += 13;
			if (i > 'z')
			{
				cout << char(i - 26);
			}
			else cout << char(i);
				
		}
		else
		{
			cout << char(i);
		}
	}
	return 0;
}