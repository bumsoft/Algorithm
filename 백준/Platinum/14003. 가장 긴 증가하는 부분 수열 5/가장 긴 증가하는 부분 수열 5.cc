#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, len;
int arr[1'000'001];
int LIS[1'000'001];

int dp[1'000'001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		int here = arr[i];
		auto pos = lower_bound(LIS, LIS + len, here);
		*pos = here;
		if (pos == LIS + len)
		{
			len++;
			dp[i] = len;
		}
		else dp[i] = pos - LIS + 1;
	}
	cout << len << '\n';
	stack<int> st;
	for (int i = N-1; i >= 0; i--)
	{
		if (dp[i] == len)
		{
			len--;
			st.push(arr[i]);
			int t = arr[i];
			for (int j = i-1; j >= 0; j--)
			{
				if (t > arr[j] && dp[j] == len)
				{
					len--;
					st.push(arr[j]);
					t = arr[j];
				}
			}
			break;
		}
	}
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}