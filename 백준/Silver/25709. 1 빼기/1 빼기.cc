#include <bits/stdc++.h>
using namespace std;

int N;
int ans;
int main()
{
	cin >> N;
	while (true)
	{
		bool m = true;
		string n = to_string(N);

		for (int i = 0; i < n.length(); i++)
		{
			if (n[i] == '1')
			{
				bool ck = false;
				string s = "";
				for (int j = 0; j < n.length(); j++)
				{
					if (j == i) continue;
					if (n[j] != '0') ck = true;
					if (ck) s += n[j];
				}
				n = s;
				m = false;
				break;
			}
		}
		ans++;
		if (n.length()==0) break;
		N = stoi(n);
		if (m) N--;
	}
	cout << ans;
	
	return 0;
}