#include <bits/stdc++.h>
using namespace std;

int N;
bool vis[200'001];
// a : 사람번호
// b : 1-in 0-out
int ans;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (vis[a]) //in인 경우
		{
			if (b == 1) //in인 경우
			{
				ans++;
			}
			else
			{
				vis[a] = false;
			}
		}
		else //out인 경우
		{
			if (b == 0)
			{
				ans++;
			}
			else
			{
				vis[a] = true;
			}
		}
	}
	for (int i = 1; i <= 200'000; i++)
	{
		if (vis[i])
		{
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}