#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 100'000
// g가 주어졌을 때, 이분탐색으로 g이하의 빈 게이트를 찾으면 됨

// -4 -3 -2 -1
// 
// -4 -1 -1

// 도킹된 게이트는 리스트에서 제거해야함. 빠르게 제거해야하는데...

// logN * logN * N
int ans;
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int G, P; cin >> G >> P;
	set<int> S;
	for (int i = 1; i <= G; i++)
	{
		S.insert(-i);
	}
	int temp;
	bool c = false;
	for (int i = 0; i < P; i++)
	{
		cin >> temp;
		if (c) continue;
		temp = -temp;

		auto t = S.lower_bound(temp);
		if (t == S.end())
		{
			c = true;
			continue;
		}
		S.erase(t);
		ans++;
	}
	cout << ans;
}