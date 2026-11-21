#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	int v;
	char c;
	string a;
	while (T--)
	{
		map<string, int> mp;
		cin >> a;
		int l = a.length();
		int cur = 0;
		string t = "";
		int cost = 0;
		while (cur<l)
		{
			c = a[cur++];
			if (c == ':')
			{
				continue;
			}
			if (c == ',')
			{
				mp.insert({ t,cost });
				t = "";
				cost = 0;
				continue;
			}
			if (c >= '0' && c <= '9')
			{
				cost *= 10;
				cost += c - '0';
				continue;
			}
			else
			{
				t += c;
			}
		}
		mp.insert({ t,cost });
		
		//계산
		int minn = INT_MAX;
		int seg_max = 0;
		cin >> a;
		l = a.length();
		cur = 0; 
		t = "";
		while (cur < l)
		{
			c = a[cur++];
			if (c == '&')
			{
				seg_max = max(seg_max, mp.at(t));
				t = "";
				continue;
			}
			if (c == '|')
			{
				
				seg_max = max(seg_max, mp.at(t));
				t = "";
				minn = min(seg_max, minn);
				seg_max = 0;
				continue;
			}
			else
			{
				t += c;
			}
		}
		seg_max = max(seg_max, mp.at(t));
		minn = min(seg_max, minn);
		cout << minn << '\n';
	}
}
