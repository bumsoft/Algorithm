#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gate[100'001];

int f(int t)
{
	if (gate[t] == 0)
	{
		return -1;
	}
	if (gate[t] == t)
	{
		gate[t] = t - 1;
		return t - 1;
	}
	return gate[t] = f(gate[t]);


}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int G, P; cin >> G >> P;
	for (int i = 1; i <= G; i++)
	{
		gate[i] = i;
	}
	int t;
	int ans = 0;
	for (int i = 0; i < P; i++)
	{
		cin >> t;
		int r = f(t);
		if (r == -1)
		{
			cout << ans;
			return 0;
		}
		ans++;
	}
	cout << ans;
}