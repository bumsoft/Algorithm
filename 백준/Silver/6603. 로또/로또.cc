#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int K;

bool vis[13];

int S[13];

void sol(int start, int cnt)
{
	if (start > K) return;
	if (cnt == 6)
	{
		for (int i = 0; i < K; i++)
		{
			if (vis[i]) cout << S[i] << ' ';
		}
		cout << '\n';
		return;
	}

	vis[start] = 1;
	sol(start + 1, cnt + 1);

	vis[start] = 0;
	sol(start + 1, cnt);
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1)
	{
		cin >> K;
		if (K == 0) return 0;
		for (int i = 0; i < K; i++)
		{
			cin >> S[i];
		}
		sol(0, 0);
		cout << '\n';
	}

	
	return 0;
}
