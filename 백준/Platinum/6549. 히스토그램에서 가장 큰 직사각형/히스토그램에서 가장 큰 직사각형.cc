#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 2'100'000'000
int N;
ll seg[1 << 18];
ll arr[100'001];
ll init(int node, int s, int e)
{
	if (e == s) return seg[node] = s; //인덱스를 저장

	ll mid = (s + e) / 2;

	ll left = init(node * 2, s, mid);
	ll right = init(node * 2 + 1, mid + 1, e);

	if (arr[left] <= arr[right]) // 왼쪽 구간의 높이가 더 작다면?
	{
		return seg[node] = left;
	}
	else
	{
		return seg[node] = right;
	}
}

ll query(int node, int s, int e, int a, int b)
{
	//범위를 벗어난 경우
	if (b<s || a>e) return 0;

	//범위에 속하는 경우 a <= s <= e <= b 인 경우
	if (a <= s && e <= b) return seg[node];

	//그 외
	ll mid = (s + e) / 2;

	ll left = query(node * 2, s, mid, a, b);
	ll right = query(node * 2 + 1, mid + 1, e, a, b);
	return arr[left] >= arr[right] ? right : left;
}
ll area_query(int a, int b)
{
	ll min_index = query(1, 1, N, a, b);
	ll max_area = arr[min_index] * (b - a + 1);


	if (min_index + 1 <= b)
	{
		ll max_left = area_query(min_index + 1, b);
		max_area = max_area > max_left ? max_area : max_left;
	}

	if (min_index - 1 >= a)
	{
		ll max_right = area_query(a, min_index - 1);
		max_area = max_area > max_right ? max_area : max_right;
	}

	return max_area;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		for (int i = 1; i <= N; i++)cin >> arr[i];
		arr[0] = INF;
		init(1, 1, N);
		cout << area_query(1, N) << '\n';
	}
	return 0;
}