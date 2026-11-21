#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
int seg[1 << 18];
int arr[100'001];

// 노드에는 가장 작은 값의 인덱스를 저장해야함.
int init(int node, int s, int e)
{
	if (s == e)
	{
		return seg[node] = s;
	}

	int mid = (s + e) / 2;
	
	int left = init(node * 2, s, mid);
	int right = init(node * 2 + 1, mid + 1, e);

	return seg[node] = arr[left] > arr[right] ? right : left;

}

void update_query(int node, int s, int e, int i)
{
	if (s == e) return;

	int mid = (s + e) / 2;
	if (i <= mid)
	{
		update_query(node * 2, s, mid, i);
	}
	else
	{
		update_query(node * 2 + 1, mid + 1, e, i);
	}
	seg[node] = arr[seg[node * 2]] > arr[seg[node * 2 + 1]] ? seg[node * 2 + 1] : seg[node * 2];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	init(1, 1, N);

	cin >> M;
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c;
			arr[b] = c;
			update_query(1, 1, N, b);
		}
		else
		{
			cout << seg[1] << '\n';
		}
	}

	return 0;
}