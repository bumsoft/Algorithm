#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// a1*n + a0 <= cn , n>=n0
// => (a1-c)n + a0 <= 0 이어야함

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	// i) 양수
	if (a1 - c > 0)
	{
		cout << 0;
	}
	// ii) 음수
	else
	{
		if ((a1 - c) * n0 + a0 <= 0)
		{
			cout << 1;
		}
		else cout << 0;
	}
	return 0;
}