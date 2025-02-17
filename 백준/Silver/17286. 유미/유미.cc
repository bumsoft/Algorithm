#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<double, double> arr[4];

double cal(pair<double, double> a, pair<double, double> b)
{
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	double a, b;
	for (int i = 0; i < 4; i++)
	{
		cin >> a >> b;
		arr[i].first = a;
		arr[i].second = b;
	}
	int ans = INT_MAX;
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if (i == j)continue;
			for (int k = 1; k < 4; k++)
			{
				if (k == j || k == i)continue;
				int d = cal(arr[0], arr[i]) + cal(arr[i], arr[j]) + cal(arr[j], arr[k]);
				ans = min(ans, d);
			}
		}
	}
	cout << ans;

	return 0;
}