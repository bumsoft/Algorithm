#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	int ans = 0;
	string s;
	while (N--)
	{
		cin >> s;
		stack<char> ST;
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];

			if (!ST.empty() && ST.top() == c)
				ST.pop();
			else
				ST.push(c);
		}
		if (ST.empty()) ans++;
	}
	cout << ans;

	return 0;
}
