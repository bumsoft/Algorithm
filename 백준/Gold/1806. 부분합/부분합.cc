#include <bits/stdc++.h>
using namespace std;
int N, S;
int sum[100'001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> S;
	for (int i = 1; i <= N; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	int ans = INT_MAX;
	for (int i = N; i>=1; i--)
	{
		//sum[i] - sum[k] >= S가 되도록.
		// sum[k] <= sum[i] - S여야함.
		int index = upper_bound(sum + 1, sum + i + 1, sum[i] - S) - sum - 1;
		if (sum[i] - sum[index] < S)continue;
		ans = min(ans, i - index);
	}
	if (ans == INT_MAX)cout << 0;
	else cout << ans;
	return 0;
}