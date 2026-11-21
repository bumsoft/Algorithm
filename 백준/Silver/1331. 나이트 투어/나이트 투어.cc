#include <bits/stdc++.h>
using namespace std;

set<string> a;

int main()
{
	string t;
	string s;
	string first;
	cin >> s;
	first = s;
	a.insert(first);
	while (true)
	{
		cin >> t;
		if (a.count(t) == 1)
		{
			break;
		}
		
		if (abs(s[0] - t[0]) == 2)
		{
			if (abs(s[1] - t[1]) == 1)
			{
				s = t;
				a.insert(t);
				if (a.size() == 36) break;
				continue;
			}

			break;
		}
		else if (abs(s[0] - t[0]) == 1)
		{
			if (abs(s[1] - t[1]) == 2)
			{
				s = t;
				a.insert(t);
				if (a.size() == 36) break;
				continue;
			}
			break;
		}
		break;
		if (a.size() == 36) break;
	}

	if (a.size() != 36)
	{
		cout << "Invalid";
		return 0;
	}

	if (abs(first[0] - t[0]) == 2)
	{
		if (abs(first[1] - t[1]) == 1)
		{
			cout << "Valid";
			return 0;
		}
		else
		{

		}
	}
	else if (abs(first[0] - t[0]) == 1)
	{
		if (abs(first[1] - t[1]) == 2)
		{
			cout << "Valid";
			return 0;
		}
	}
	cout << "Invalid";

}