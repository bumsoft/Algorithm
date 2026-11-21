#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
bool pri[4'000'001];
ll sum[4'000'001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		if (pri[i])continue;
		for (int j = 2;; j++)
		{
			if (i * j > N)break;
			pri[i * j] = true;
		}
	}
	int o = 1;
	for (int i = 2; i <= N; i++)
	{
		if (!pri[i]) { sum[o] = sum[o - 1] + i; o++; }// cout << sum[o - 1] << ' '; }
	}
	//cout << "\n\n";
	// S[i]-S[k] = N이 되어야함
	// S[k] = S[i]-N 이도록.
	int ans = 0;
	for (int i = o-1; i >= 1; i--)
	{
		if (sum[i] - N == sum[lower_bound(sum, sum + i, sum[i] - N) - sum])
		{
			ans++;
		//	cout << "sum[" << i << "]=" << sum[i] << " " << lower_bound(sum + 1, sum + i, sum[i] - N) - sum << endl;
		}
	}
	cout << ans;
	return 0;
}