#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sum[10'001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}

	int ans = 0;
	for (int i = 0; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (sum[j] - sum[i] < M)
			{
				continue;
			}
			if (sum[j] - sum[i] > M)
			{
				break;
			}
			if (sum[j] - sum[i] == M) ans++;
		}
	}
	cout << ans;

	return 0;
}