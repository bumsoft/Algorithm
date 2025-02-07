#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//O(NlogN) LIS

vector<int> lis;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int t;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;

		auto pos = lower_bound(lis.begin(), lis.end(), t);

		if (pos == lis.end())
		{
			lis.push_back(t);
		}
		else
		{
			*pos = t;
			//또는
			//lis[pos-lis.begin()] = t;
		}
	}
	cout << lis.size();

}