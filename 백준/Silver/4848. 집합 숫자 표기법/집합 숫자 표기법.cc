#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<string>temp;
	temp.push_back("{}");
	for (int i = 1; i <= 15; i++)
	{
		string t = "{";
		for (int j = 0; j < temp.size(); j++)
		{
			t += temp[j];
			if (j + 1 != temp.size())
			{
				t += ",";
			}
		}
		t += "}";
		temp.push_back(t);
	}
	int T;
	cin >> T;
	string a, b;
	int aa, bb;
	while (T--)
	{
		cin >> a >> b;
		for (int i = 0; i < temp.size(); i++)
		{
			if (a == temp[i])
			{
				aa = i;
				break;
			}
		}
		for (int i = 0; i < temp.size(); i++)
		{
			if (b == temp[i])
			{
				bb = i;
				break;
			}
		}
		cout << temp[(aa + bb)] << '\n';
	}
}