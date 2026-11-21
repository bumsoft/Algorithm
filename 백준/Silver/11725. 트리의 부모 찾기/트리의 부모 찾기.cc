#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100001];
int ans[100001];
bool c[100001];
void sol(int n)
{
	c[n] = true;
	for (int i = 0; i < tree[n].size(); i++)
	{
		if (c[tree[n][i]]) continue;
		ans[tree[n][i]] = n;
		sol(tree[n][i]);
	}
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N, a, b;
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	sol(1);
	for (int i = 2; i <= N; i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}