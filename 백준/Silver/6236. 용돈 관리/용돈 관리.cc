#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 이분탐색(매개변수)

int N, M;
int arr[100'001];

bool check(int amount) //amount일 때, 인출해야 하는 횟수가 M보다 작다면 TRUE!
{
	int left = amount; //남은 돈
	int num = 1; //인출횟수
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > amount) return false;
		if (arr[i] <= left)
		{
			left -= arr[i];
			continue;
		}
		else
		{
			num++;
			left = amount - arr[i];
		}
	}
	if (num <= M) return true;
	return false;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int s = 1;
	int e = 100'000 * 10'000;
	int mid;
	int ans = INT_MAX;
	while (s <= e)
	{
		mid = (s + e) / 2;
		if (check(mid))
		{
			e = mid - 1;
			ans = min(ans, mid);
		}
		else
		{
			s = mid + 1;
		}
	}
	cout << ans;
	return 0;
}