#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, Q;
ll seg[1'000'000 << 2];


void update(int node, int s, int e, int p, int x)
{
	seg[node] += x;
	if (s == e)
	{
		return;
	}
	int mid = (s + e) / 2;
	if (p <= mid)return update(node * 2, s, mid, p, x);
	return update(node * 2 + 1, mid + 1, e, p, x);
}

ll query(int node, int s, int e, int a, int b)
{
	if (a <= s && e <= b) return seg[node];
	if (b<s || a>e)return 0;
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, a, b) + query(node * 2 + 1, mid + 1, e, a, b);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> Q;

	int order, a, b;
	for (int i = 0; i < Q; i++)
	{
		cin >> order >> a >> b;
		if (order == 1)
		{
			update(1, 1, N, a, b);
		}
		else
		{
			cout << query(1, 1, N, a, b) << '\n';
		}
	}
}