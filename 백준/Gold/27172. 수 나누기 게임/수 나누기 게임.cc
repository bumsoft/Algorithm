#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int arr[100'001];
bool num[1'000'001];
int ans[1'000'001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		num[arr[i]] = true;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 2; j * arr[i] <= 1'000'000; j++)
		{
			if (num[arr[i] * j])
			{
				ans[arr[i]]++;
				ans[arr[i] * j]--;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << ans[arr[i]] << ' ';
	}
	return 0;
}