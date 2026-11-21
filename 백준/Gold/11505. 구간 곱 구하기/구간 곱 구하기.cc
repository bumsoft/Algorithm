#include <bits/stdc++.h>
#define MMM 1'000'000'007
using namespace std;
using ll = long long;

int N, M, K;
ll seg[4'000'000];
ll arr[1'000'001];
int o = 1;
ll init(int node, int s, int e)
{
	if (s == e) return seg[node] = arr[o++];
	int mid = (s + e) / 2;
	return seg[node] = (init(node * 2, s, mid) * init(node * 2 + 1, mid + 1, e)) % MMM;
}

ll update(int node, int s, int e, int i)
{
	if (s == e) return seg[node] = arr[i];

	int mid = (s + e) / 2;

	if (i <= mid)
	{
		return seg[node] = (seg[node * 2 + 1] * update(node * 2, s, mid, i)) % MMM;
	}
	else
	{
		return seg[node] = (seg[node * 2] * update(node * 2 + 1, mid + 1, e, i)) % MMM;
	}
}

ll query(int node, int s, int e, int a, int b)
{
	if (b<s || a>e) return 1; // 범위벗어난 경우 1을 곱함
	if (a <= s && e <= b) return seg[node];
	if (s == e) return seg[node];

	int mid = (s + e) / 2;

	return (query(node * 2, s, mid, a, b) * query(node * 2+1, mid + 1, e, a, b)) % MMM;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >>  M >> K;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	init(1, 1, N);
	int a, b, c;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1) // [b]->c
		{
			arr[b] = c;
			update(1, 1, N, b);
		}
		else // b~c 출력
		{
			cout << query(1, 1, N, b, c) << '\n';
		}
	}
	return 0;
}