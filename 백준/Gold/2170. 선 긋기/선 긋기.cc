#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<pair<int, int>> v;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int a, b;
	while (N--)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int start = v[0].first;
	int preEnd = v[0].second;
	int r = 0;
	for(int i=1;i<v.size();i++)
	{
		a = v[i].first;
		b = v[i].second;
		if (preEnd >= a)
		{
			if (preEnd > b) continue;
			else preEnd = b;
		}
		else
		{
			r += a - preEnd;
			preEnd = b;
		}
	}
	cout << preEnd - start - r;
	

	return 0;
}