#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// i번을, i번 이후 값들중 가장 작은 것보다 작게 만들어야함.
int arr[101];
int N;
bool check()
{
	int pre = arr[1];
	for (int i = 2; i <= N; i++)
	{
		if (pre < arr[i])
		{
			pre = arr[i];
		}
		else return false;
	}
	return true;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	while (!check())
	{
		for (int i = 1; i < N; i++)
		{
			int mini = 20001;
			for (int j = i + 1; j <= N; j++)
			{
				mini = min(mini, arr[j]);
			}
			if (arr[i] >= mini)
			{
				ans += arr[i] - mini + 1;
				arr[i] = mini - 1;
			}
		}
	}

	cout << ans;


	return 0;
}