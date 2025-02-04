#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[500 * 500];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M, B;
	cin >> N >> M >> B;
	int min_ = 257;
	int max_ = -1;
	for (int i = 0; i < N * M; i++)
	{
		cin >> arr[i];
		min_ = min(min_, arr[i]);
		max_ = max(max_, arr[i]);
	}
	int t;
	int ans = INT_MAX;
	int height;
	for (int i = min_; i <= max_; i++)
	{
		int numB = B;
		t = 0;
		for (int j = 0; j < M * N; j++)
		{
			if (arr[j] > i)
			{
				t += (arr[j] - i) * 2;
				numB += arr[j] - i;
			}
			else if (arr[j] == i) continue;
			else
			{
				t += i - arr[j];
				numB -= i - arr[j];
			}
		}
		if (numB < 0) continue;
		if (ans >= t)
		{
			ans = t;
			height = i;
		}
	}
	cout << ans <<' '<< height;
	return 0;
}