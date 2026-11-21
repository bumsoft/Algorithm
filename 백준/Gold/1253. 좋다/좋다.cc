#include <bits/stdc++.h>
using namespace std;
int N;
int arr[2000];
int ans;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	bool c;
	for (int k = 0; k < N; k++)
	{
		c = false;
		for (int i = 0; i < N; i++)
		{
			if (k == i) continue;
			for (int j = i; j < N; j++)
			{
				if (j == i || j==k)continue;
				if (arr[i] + arr[j] > arr[k])break;
				if (arr[i]+arr[j]==arr[k])
				{
					c = true;
					ans++;
					break;
				}
			}
			if (c) break;
		}
	}
	cout << ans;
	return 0;
}