#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//반전시킬시, 구간에 있는 전구수 - 노드값 : seg[node] = (e-s+1)-seg[node];
// lazy propagation
int N, M;
int seg[100'000 << 2];
int lazy[100'000 << 2];


void update(int node, int s, int e, int a, int b)
{
	if (lazy[node] != 0)//자식 전파
	{
		if (lazy[node] % 2 == 1) //홀수면
		{
			seg[node] = (e - s + 1) - seg[node];
		}
		if (s != e)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (b < s || e < a) return;
	if (a <= s && e <= b)
	{
		seg[node] = (e - s + 1) - seg[node];
		if (s != e)
		{
			lazy[node * 2]++;
			lazy[node * 2 + 1]++;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, a, b);
	update(node * 2 + 1, mid + 1, e, a, b);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int query(int node, int s, int e, int a, int b)
{
	if (lazy[node] != 0)//자식 전파
	{
		if (lazy[node] % 2 == 1) //홀수면
		{
			seg[node] = (e - s + 1) - seg[node];
		}
		if (s != e)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (b < s || e < a) return 0;
	if (a <= s && e <= b) return seg[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, a, b) + query(node * 2 + 1, mid + 1, e, a, b);
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if (a == 0)
		{
			update(1, 1, N, b, c);
		}
		else
		{
			cout << query(1, 1, N, b, c) << '\n';
		}
	}
	return 0;
}