#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 두 중심 간 거리

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--)
	{
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double d = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));

		if (r1 + r2 == d)
		{
			cout << 1 << '\n';
			continue;
		}
		if (r1 + r2 < d)
		{
			cout << 0 << '\n';
			continue;
		}
		if (r1 + r2 > d)
		{
			//두 원의 중심이 같을 때
			if (d == 0)
			{
				if (r1 == r2) //같은 원
				{
					cout << -1 << '\n';
					continue;
				}
				// 중심같은 다른원
				cout << 0 << '\n';
				continue;
			}
			
			//한 원이 안에서 내접할때
			if (abs(r1 - r2) == d)
			{
				cout << 1 << '\n';
				continue;
			}
			//한 원이 안에서 접하지 않음
			if (abs(r1 - r2) > d)
			{
				cout << 0 << '\n';
				continue;
			}
			cout << 2 << '\n';
		}
	}

	return 0;
}