#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
int arr[1'000'001];
int lis[1'000'001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int len = 0;
	for (int i = 0; i < N; i++)
	{
		int here = arr[i];
		auto pos = lower_bound(lis, lis + len, here);
		*pos = here;
		if (pos == lis + len) len++;
	}
	cout << len;


	return 0;
}