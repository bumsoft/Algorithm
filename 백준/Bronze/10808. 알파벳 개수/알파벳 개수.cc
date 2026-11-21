#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int al[26];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	char t;
	while (cin >> t)
	{
		al[t - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << al[i] << ' ';
	}
	return 0;
}