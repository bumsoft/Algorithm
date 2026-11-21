#include <bits/stdc++.h>
#define INF 2'100'000'000
using namespace std;

int N, M;
int s[1001];
int mem[10001];
bool ck[10001];
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < M; i++)
	{
		ck[s[i]] = true;
		for (int j = i + 1; j < M; j++)
		{
			if (s[i] + s[j] <= N)ck[s[i] + s[j]] = true;
		}
	}
	vector<int> mm;
	for (int i = 0; i <= N; i++)
	{
		if (ck[i])mm.push_back(i);
	}

	for (int i = 0; i <= N; i++)
	{
		mem[i] = INF;
	}
	mem[0] = 0;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < mm.size(); j++)
		{
			if (i + mm[j] <= N)
			{
				mem[i + mm[j]] = min(mem[i] + 1, mem[i + mm[j]]);
			}
		}
	}
	if (mem[N] == INF) cout << -1;
	else cout << mem[N];

	return 0;
}