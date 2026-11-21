#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, M, m;
int arr[51];
int ans;

void d_front()
{
	ans++;
	for (int i = m; i < M; i++)
	{
		arr[i]--;
		if (arr[i] == 0)
		{
			arr[i] = n;
		}
	}
}
void d_back()
{
	ans++;
	for (int i = m; i < M; i++)
	{
		arr[i]++;
		if (arr[i] > n)
		{
			arr[i] = 1;
		}
	}
}
void d_pop()
{
	n--;
	m++;
	for (int i = m; i < M; i++)
	{
		arr[i]--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> M;
	for (int i = 0; i < M; i++)cin >> arr[i];

	while (m<M)
	{
		if (arr[m] == 1)
		{
			d_pop();
			continue;
		}
		if (n + 1 - arr[m] <= arr[m]-1)
		{
			d_back();
		}
		else
		{
			d_front();
		}
	}
	cout << ans;
	return 0;
}