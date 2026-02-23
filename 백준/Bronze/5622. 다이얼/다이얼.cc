#include <bits/stdc++.h>

using namespace std;

//A=65 - 65 %=3
//B=66 1
//C=67 2
//D=68 3 1 + 3 4

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1') ans += 2;
		else if (s[i] >= 'P')
		{
			if (s[i] == 'P' || s[i] == 'Q' || s[i] == 'R' || s[i] == 'S')
				ans += 8;
			else if (s[i] == 'T' || s[i] == 'U' || s[i] == 'V')
				ans += 9;
			else if (s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'Z')
				ans += 10;
		}

		else
			ans += (s[i] - 65) / 3 + 3;
	}
	cout << ans;
	return 0;
}