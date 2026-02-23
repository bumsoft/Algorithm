#include <bits/stdc++.h>

using namespace std;

string arr[101];
bool vis[101];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		for (int j = 'a'; j <= 'z'; j++)
		{
			vis[j] = 0;
		}
		char prev = 0;
		ans++;
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (vis[arr[i][j]] && prev != arr[i][j])
			{
				ans--;
				break;
			}
			prev = arr[i][j];
			vis[arr[i][j]] = 1;
		}
	}
	cout << ans;
	return 0;
}