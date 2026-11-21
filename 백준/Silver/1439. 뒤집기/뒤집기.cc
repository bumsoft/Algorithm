#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin >> s;
	char t;
	t = s[0];
	int zero = 0, one = 0;
	if (t == '0') zero++;
	else one++;
	for (int i = 1; i < s.length(); i++)
	{
		if (t == s[i]) continue;
		else
		{
			t = s[i];
			if (t == '0') zero++;
			else one++;
		}
	}
	cout << min(zero, one);
	return 0;
}