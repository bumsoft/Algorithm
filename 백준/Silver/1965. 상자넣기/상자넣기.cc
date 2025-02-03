#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//O(N^2) LIS

int arr[1'001];
int dp[1'001]; //dp[i]: arr[i]를 가장 큰 수로 하는 수열의 길이

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		maxx = max(maxx, dp[i]);
	}
	cout << maxx;
}