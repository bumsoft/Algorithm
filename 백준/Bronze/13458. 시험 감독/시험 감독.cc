#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
ll ans;
ll arr[1'000'001];
int B, C;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	ans += N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++)
	{
		arr[i] -= B;
		if (arr[i] < 0)continue;
		if (arr[i] % C == 0)
		{
			ans += arr[i] / C;
		}
		else
		{
			ans += arr[i] / C + 1;
		}
	}
	cout << ans;
	return 0;
}