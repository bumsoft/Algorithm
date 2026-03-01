#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	int N;
	cin >> N >> s;
	vector<string> v;
	string temp = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C')
		{
			if (temp != "")
			{
				if (temp.size() == 1) temp += "0";
				v.push_back(temp);
			}
			temp = s[i];
			continue;
		}
		else 
		{
			temp += s[i];
			if (temp.size() == 1) temp += "0";
			v.push_back(temp);
			temp = "";
		}
	}
	if (temp.size() == 1) temp += "0";
	v.push_back(temp);

	for (int i = 0; i < N; i++)
	{
		if (v[i] == "C+" || v[i] == "C0" || v[i] == "C-")
		{
			cout << "B";
			continue;
		}
		if (v[i] == "B0" || v[i] == "B-")
		{
			if (i == 0 || v[i - 1] == "C+" || v[i - 1] == "C0" || v[i - 1] == "C-")
			{
				cout << "D";
				continue;
			}
			cout << "B";
			continue;
		}
		if (v[i] == "A-" || v[i] == "B+")
		{
			if (i == 0 || v[i - 1] == "C+" || v[i - 1] == "C0" || v[i - 1] == "C-" || v[i - 1] == "B-" || v[i - 1] == "B0")
			{
				cout << "P";
				continue;
			}
			cout << "D";
			continue;
		}
		if (v[i] == "A0")
		{
			if (i != 0 && (v[i - 1] == "A+" || v[i - 1] == "A0"))
			{
				cout << "P";
				continue;
			}
			cout << "E";
		}
		else cout << "E";
	}

	return 0;
}
