#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 1~N까지 자연수 중 중복 없이 M개를 고른 모든 수열을 사전순으로 출력
// 1 2 3
// 1 2 4 ...

int N, M;

int ans[10];
bool vis[10];

void back_tracking(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (vis[i]) continue;
		ans[cnt] = i;
		vis[i] = 1;
		back_tracking(cnt+1);
		vis[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	 cin >> N >> M;

	 back_tracking(0);
	
	return 0;
}
