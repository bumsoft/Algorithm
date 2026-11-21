// min() max()를 사용할 때 인자의 뒤부터 실행되기에 순서 조심해야함
#include <bits/stdc++.h>
#define INF 2'100'000'000
using namespace std;
using ll = long long;

int N, M;

int min_seg[1 << 18];
int max_seg[1 << 18];
int arr[100'001];
int o = 1;
int init_min(int node, int s, int e)
{
	if (s == e) return min_seg[node] = arr[o++];
	int mid = (s + e) / 2;

	return min_seg[node] = min(init_min(node * 2 + 1, mid + 1, e), init_min(node * 2, s, mid));
}

int init_max(int node, int s, int e)
{
	if (s == e) return max_seg[node] = arr[o++];
	int mid = (s + e) / 2;
	return max_seg[node] = max(init_max(node * 2 + 1, mid + 1, e), init_max(node * 2, s, mid));
}

int query_min(int node, int s, int e, int a, int b)
{
	if (b<s || a>e) return INF;
	if (a <= s && e <= b) return min_seg[node];
	if (s == e) return min_seg[node];
	int mid = (s + e) / 2;

	return min(query_min(node * 2, s, mid, a, b), query_min(node * 2 + 1, mid + 1, e, a, b));
}
int query_max(int node, int s, int e, int a, int b)
{
	if (b<s || a>e) return 0;
	if (a <= s && e <= b) return max_seg[node];
	if (s == e) return max_seg[node];
	int mid = (s + e) / 2;

	return max(query_max(node * 2, s, mid, a, b), query_max(node * 2 + 1, mid + 1, e, a, b));
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	init_min(1, 1, N);
	o = 1;
	init_max(1, 1, N);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << query_min(1, 1, N, a, b) << ' ' << query_max(1, 1, N, a, b) << '\n';
	}
	return 0;
}