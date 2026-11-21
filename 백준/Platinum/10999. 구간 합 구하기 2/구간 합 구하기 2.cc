#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M, K;
ll seg[1'000'000<<2];
ll lazy[1'000'000 << 2];
// 느리게 갱신되는 세그먼트 트리.
// 업데이트할 구간이 모두 포함된 노드(구간)은 특별하게 진행함.
// lazy[node]에 자식이 더해야하는 값을 따로 저장해둠.
// 이렇게 했다면 앞으로 모든 노드방문에서 lazy[node]가 0인지 확인하는 과정을 해주어야함.

ll init(int node, int s, int e)
{
	if (s == e)
	{
		cin >> seg[node];
		return seg[node];
	}
	int mid = (s + e) / 2;
	return seg[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid+1,e);
}

void update(int node, int s, int e, int a, int b, ll p) //a~b p더함
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
	if (b<s || a>e) return; 

	if (a <= s && e <= b) //모두 포함된 구간임.
	{
		seg[node] += (e - s + 1) * p;
		if (s != e)
		{
			lazy[node * 2] += p;
			lazy[node * 2 + 1] += p;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, a, b, p);
	update(node * 2 + 1, mid + 1, e, a, b, p);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int node, int s, int e, int a, int b)
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
	if (b<s || a>e)return 0;
	if (a <= s && e <= b)return seg[node];
	int mid = (s + e) / 2;
	ll left = query(node * 2, s, mid, a, b);
	ll right = query(node * 2 + 1, mid + 1, e, a, b);
	return left + right;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	init(1, 1, N);
	int a, b, c;
	ll d;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			cin >> d;
			update(1, 1, N, b, c, d);
		}
		else
		{
			cout << query(1, 1, N, b, c) << '\n';
		}
	}
	return 0;
}