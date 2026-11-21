#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, K;

ll seg[1'000'000 << 2];

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
	return seg[node] = left + right;
}

ll update(int node, int s, int e, int b, ll c)
{
	if (s == e)
	{
		ll diff = seg[node] - c; //원래 수와의 차이
		seg[node] = c;
		return diff;
	}
	int mid = (s + e) / 2; //현재 구간의 중간

	if (b <= mid) // b가 mid의 왼쪽인 경우
	{
		ll diff = update(node * 2, s, mid, b, c);
		seg[node] -= diff;
		return diff;
	}
	else // b가 mid의 오른쪽인 경우
	{
		ll diff = update(node * 2 + 1, mid + 1, e, b, c);
		seg[node] -= diff;
		return diff;
	}
}

ll query(int node, int s, int e, int b, int c)
{
	if (b <= s && e <= c) //범위에 속하면 반환
	{
		return seg[node];
	}
	if (s > c || e < b) return 0;

	int mid = (s + e) / 2;
	ll left = query(node * 2, s, mid, b, c);
	ll right = query(node * 2 + 1, mid + 1, e, b, c);

	return left + right;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	init(1, 1, N);

	int a, b;
	ll c;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1) // b번째 수를 c로 교체
		{
			update(1, 1, N, b, c);
		}
		else // b번째~c번째 수까지의 합
		{
			cout << query(1, 1, N, b, c) << '\n';
		}
	}
	return 0;
}
