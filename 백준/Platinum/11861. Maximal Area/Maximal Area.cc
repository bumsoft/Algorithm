#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 2'100'000'000
int N;
int seg[1'000'000<<2];
int arr[1'000'000];
int init(int node, int s, int e)
{
	if (e == s) return seg[node] = s;

	int mid = (s + e) / 2;

	int left = init(node * 2, s, mid);
	int right = init(node * 2 + 1, mid + 1, e);

	if (arr[left] <= arr[right])
	{
		return seg[node] = left;
	}
	else
	{
		return seg[node] = right;
	}
}

int query(int node, int s, int e, int a, int b)
{
	if (b<s || a>e) return 0;
	if (a <= s && e <= b) return seg[node];
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, a, b);
	int right = query(node * 2 + 1, mid + 1, e, a, b);
	return arr[left] >= arr[right] ? right : left;
}

int area_query(int a, int b)
{
	int min_index = query(1, 1, N, a, b);
	int max_area = arr[min_index] * (b - a + 1);


	if (min_index + 1 <= b)
	{
		int max_left = area_query(min_index + 1, b);
		max_area = max_area > max_left ? max_area : max_left;
	}

	if (min_index - 1 >= a)
	{
		int max_right = area_query(a, min_index - 1);
		max_area = max_area > max_right ? max_area : max_right;
	}

	return max_area;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	arr[0] = INF;
	init(1, 1, N);
	cout << area_query(1, N);
	return 0;
}