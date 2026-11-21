#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll N, ans;
	cin >> N;
	ans = 1;
	for (int i = 2; i <= N; i++)
	{
		ans *= i;
		if (ans % 10 == 0) //10의 배수면?
		{
			while (ans % 10 == 0)
			{
				ans /= 10;
			}
			ans %= 1000000;
		}
		else ans %= 1000000;
		//cout << "i:"<<i<<" "<<ans << '\n';
	}
	cout << ans%10;
	return 0;
}