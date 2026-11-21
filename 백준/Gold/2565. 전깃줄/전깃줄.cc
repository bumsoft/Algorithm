#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<pair<int, int>> v;
int arr[101];
int dp[101];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		arr[i] = v[i].second;
	}

	//dp[a]=b : arr[a]를 끝으로 하는 수열의 길이 = b
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (i == 0) { dp[0] = 1; continue; }
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << N - ans;
	return 0;
}