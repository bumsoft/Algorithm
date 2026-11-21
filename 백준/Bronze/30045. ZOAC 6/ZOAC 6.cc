#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N;
	int ans = 0;
	string t;
	cin >> N;
	while (N--)
	{
		cin >> t;
		for (int i = 0; i < t.length()-1; i++)
		{
			if (t[i] == '0' && t[i + 1] == '1')
			{
				ans++;
				break;
			}
			if (t[i] == 'O' && t[i + 1] == 'I')
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}