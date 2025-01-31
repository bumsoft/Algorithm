#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
X: 목표
N: 개수 (1'000'000)
...: 두 개의 합이 X가 되어야 함

출력: 여러개인 경우, 두 개의 차이가 가장 큰 것을 출력
*/

bitset<200'000'001> exists;

int ss[1'000'001];

//1cm = 10000000 나노미터

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int x, n;
	while (cin >> x)
	{

		x *= 10'000'000;

		cin >> n;

		int l1 = -1;
		int l2 = -1;
		int diff = 0;

		int temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			ss[i] = temp;

			if (x - temp >= 0)
			{
				if (exists[x - temp] == true)
				{
					if (abs(x - temp - temp) >= diff)
					{
						l1 = temp;
						l2 = x - temp;
						diff = abs(x - temp - temp);
					}
				}
			}
			exists[temp] = true;
		}
		for (int i = 0; i < n; i++)
		{
			exists[ss[i]] = false;
		}
		if (l1 == -1)
		{
			cout << "danger\n";
			continue;
		}
		cout << "yes ";
		if (l1 < l2)
		{
			cout << l1 << ' ' << l2 << '\n';
		}
		else
		{
			cout << l2 << ' ' << l1 << '\n';
		}
	}

}