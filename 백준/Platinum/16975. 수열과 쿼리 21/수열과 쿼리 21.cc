#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll seg[100'000 << 2];
ll lazy[100'000 << 2];
ll init(int node, int s, int e)
{
	if (s == e)
	{
		cin >> seg[node];
		return seg[node];
	}
	int mid = (s + e) / 2;
	ll left = init(node * 2, s, mid);
	ll right = init(node * 2 + 1, mid + 1, e);
	seg[node] = left + right;
	return seg[node];
}

void query_1(int node, int s, int e, int i, int j, ll k)
{
	if (lazy[node] != 0)
	{
		seg[node] += (e - s + 1) * lazy[node];
		if (s != e)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (s > j || e < i) return;
	if (i<=s&&e<=j)
	{
		seg[node] += (e - s + 1) * k;
		if (s != e)
		{
			lazy[node * 2] += k;
			lazy[node * 2 + 1] += k;
		}
		return;
	}
	int mid = (s + e) / 2;
	query_1(node * 2, s, mid, i, j, k);
	query_1(node * 2+1, mid+1, e, i, j, k);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query_2(int node, int s, int e, int x)
{
	if (lazy[node] != 0)
	{
		seg[node] += (e - s + 1) * lazy[node];
		if (s != e)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (s == e)
	{
		return seg[node];
	}
	int mid = (s + e) / 2;
	if (x <= mid) return query_2(node * 2, s, mid, x);
	return query_2(node * 2 + 1, mid + 1, e, x);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	init(1, 1, N);
	cin >> M;
	int order, i, j, x;
	ll k;
	for (int ii = 0; ii < M; ii++)
	{
		cin >> order;
		if (order == 1)
		{
			cin >> i >> j >> k;
			query_1(1, 1, N, i, j, k);
		}
		else
		{
			cin >> x;
			cout << query_2(1, 1, N, x) << '\n';
		}
	}
	return 0;
}