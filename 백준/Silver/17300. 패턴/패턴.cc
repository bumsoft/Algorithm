#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
bool vis[10];
int arr[10];
bool solve(int a, int b) //a에서 b를 갈 수 있는지
{
	if (a == 1)
	{
		if (b == 3 && !vis[2])return false;
		if (b == 9 && !vis[5])return false;
		if (b == 7 && !vis[4])return false;
	}
	if (a == 2)
	{
		if (b == 8 && !vis[5])return false;
	}
	if (a == 3)
	{
		if (b == 1 && !vis[2])return false;
		if (b == 7 && !vis[5])return false;
		if (b == 9 && !vis[6])return false;
	}
	if (a == 4)
	{
		if (b == 6 && !vis[5])return false;
	}
	if (a == 6)
	{
		if (b == 4 && !vis[5])return false;
	}
	if (a == 7)
	{
		if (b == 1 && !vis[4])return false;
		if (b == 3 && !vis[5])return false;
		if (b == 9 && !vis[8])return false;
	}
	if (a == 8)
	{
		if (b == 2 && !vis[5])return false;
	}
	if (a == 9)
	{
		if (b == 1 && !vis[5])return false;
		if (b == 3 && !vis[6])return false;
		if (b == 7 && !vis[8])return false;
	}
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int now = arr[0];
	vis[now] = true;
	for (int i = 1; i < N; i++)
	{
		if (vis[arr[i]])
		{
			cout << "NO";
			return 0;
		}
		vis[arr[i]] = true;
		if (solve(now, arr[i]))
		{
			now = arr[i];
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}