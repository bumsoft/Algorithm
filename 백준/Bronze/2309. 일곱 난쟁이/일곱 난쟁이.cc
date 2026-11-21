#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int arr[9];
int ans[7];
bool ck;
void find(int n,int l)
{
	if (n == 7)
	{
		int temp = 0;
		for (int i = 0; i < 7; i++)
		{
			temp += ans[i];
		}
		if (temp == 100)
		{
			ck = true;
		}
		return;
	}
	for (int i = l; i < 9; i++)
	{
		ans[n] = arr[i];
		find(n + 1, i+1);
		if (ck)return;
		find(n, i + 1);
		if (ck)return;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 9; i++)cin >> arr[i];
	find(0, 0);
	sort(ans, ans + 7);
	for (int i = 0; i < 7; i++)cout << ans[i] << '\n';
	return 0;
}