#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//3x + 5y <= w;
// 5y <= w-3x
//다 본다면? x는 8만정도.

int N, W;
ll g3[250'001];
ll g5[250'001];
ll sum3[250'001], sum5[250'001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a;
	int n3 = 0;
	int n5 = 0;
	cin >> N >> W;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == 3)
		{
			cin >> g3[n3++];
		}
		else
		{
			cin >> g5[n5++];
		}
	}
	sort(g3, g3 + n3);
	sort(g5, g5 + n5);
	int o = 1;
	for (int i = n3-1; i >=0; i--,o++)
	{
		sum3[o] = sum3[o-1] + g3[i];
	}
	o = 1;
	for (int i = n5-1; i >=0; i--,o++)
	{
		sum5[o] = sum5[o-1] + g5[i];
	}
	ll ans = 0;
	for (int i = 0; i <= n3; i++) //3그램의 개수
	{
		if (3 * i > W)break;

		ans = max(ans, sum3[i] + sum5[ min((W - 3 * i) / 5,n5) ]);
	}
	cout << ans;

	return 0;
}