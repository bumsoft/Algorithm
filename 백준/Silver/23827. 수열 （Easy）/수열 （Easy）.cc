#include <bits/stdc++.h>
using namespace std;
int N;
long long arr[500'001];
long long ssum[500'001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	long long sum = 0;
	for (int i = N-1; i >=0; i--)
	{
		sum += arr[i];
		sum %= 1'000'000'007;
		ssum[i] = sum % 1'000'000'007;
	}
	long long ans = 0;
	for (int i = 0; i < N-1; i++)
	{
		ans += (arr[i] * ssum[i+1]) % 1'000'000'007;
		ans %= 1'000'000'007;
	}




	cout << ans;

	return 0;
}