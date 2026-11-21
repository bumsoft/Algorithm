#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	set<string> s;
	map<string, int> m;
	string arr[5000];
	int loc = 0;
	int M;
	string t_s;
	int t;
	cin >> M;
	while (M--)
	{
		cin >> t_s >> t;
		if (s.count(t_s) == 0)
		{
			s.insert(t_s);
			m.insert({ t_s,t });
			arr[loc++] = t_s;
		}
		else
		{
			m.at(t_s) += t;
		}
	}
	for (int i = 0; i < loc; i++)
	{
		for (int j = 0; j < loc; j++)
		{
			if (j == i)continue;
			if (int(m.at(arr[i]) * 1.618) == m.at(arr[j]))
			{
				cout << "Delicious!";
				return 0;
			}
		}
	}
	cout << "Not Delicious...";

	return 0;
}