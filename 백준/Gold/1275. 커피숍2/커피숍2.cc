#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, Q;
ll seg[100'000 << 2];
ll arr[100'001];
ll init(int node, int s, int e)
{
	if (s == e) { cin >> arr[s]; return seg[node] = arr[s]; }
	int mid = (s + e) / 2;
	return seg[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

void update(int node, int s, int e, int i, ll diff)
{
	seg[node] -= diff;
	if (s == e)return;
	int mid = (s + e) / 2;
	if (i <= mid) return update(node * 2, s, mid, i, diff);
	else return update(node * 2 + 1, mid + 1, e, i, diff);
}

ll query(int node, int s, int e, int a, int b)
{
	if (b<s || a>e) return 0;
	if (a <= s && e <= b)return seg[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, a, b) + query(node * 2 + 1, mid + 1, e, a, b);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	init(1, 1, N);
	int a, b, c;
	ll d;
	for (int i = 0; i < Q; i++)
	{
		cin >> a >> b >> c >> d;
		if (a < b)cout << query(1, 1, N, a, b) << '\n';
		else cout << query(1, 1, N, b, a) << '\n';
		update(1, 1, N, c, arr[c] - d);
		arr[c] = d;
	}

	return 0;
}