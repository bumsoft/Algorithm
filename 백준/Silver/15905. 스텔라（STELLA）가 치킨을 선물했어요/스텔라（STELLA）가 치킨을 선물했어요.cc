#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, ans;
int arr[66];
int main()
{
	cin >> N;
	int t;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i] >> t;
	}
	sort(arr, arr + N);

	int a = arr[N-5];
	for (int i = N-1; i>=0; i--)
	{
		if (a == arr[i])ans++;
		if (a > arr[i])break;
	}
	for (int i = N-1; i >= N-5; i--)
	{
		if (arr[i] == a)ans--;
	}
	cout << ans;
	return 0;
}