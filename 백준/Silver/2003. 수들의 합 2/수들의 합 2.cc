#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[10'001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	int ans = 0;
	
	int s = 0;
	int e = 1;

	int n = arr[e];

	while (true)
	{
		if (e > N) break;
		if (n < M)
		{
			e++;
			n += arr[e];
			continue;
		}
		if (n > M)
		{
			s++;
			n -= arr[s - 1];
			continue;
		}
		if (n == M)
		{
			ans++;
			e++;
			n += arr[e];
			continue;
		}
	}


	cout << ans;

	return 0;
}