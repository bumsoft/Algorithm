#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 2'100'000'000
int N;
int seg[1 << 18];
int arr[100'001];
int init(int node, int s, int e)
{
	if (e == s) return seg[node] = s; //인덱스를 저장

	int mid = (s + e) / 2;

	int left = init(node * 2, s, mid);
	int right = init(node * 2 + 1, mid + 1, e);

	if (arr[left] <= arr[right]) // 왼쪽 구간의 높이가 더 작다면?
	{
		return seg[node] = left;
	}
	else
	{
		return seg[node] = right;
	}
	// => 부모노드는 두 개의 자식들의 구간 중 가장 작은 높이를 가진다.
	
	//리프의 부모노드는 low와 high를 받게되고, 그 중 작은 걸 값으로 가짐. => 반복
}

//구간 a~b에서 가장 작은 높이를 가지는 인덱스를 반환하는 query : 즉 k가 반환되었다면, a~b구간에서 가장 작은 높이는 k이므로 넓이는 (b-a+1)*k가 된다
int query(int node, int s, int e, int a, int b)
{
	//범위를 벗어난 경우
	if (b<s || a>e) return 0;

	//범위에 속하는 경우 a <= s <= e <= b 인 경우
	if (a <= s && e <= b) return seg[node];

	//그 외
	int mid = (s + e) / 2;
	
	int left = query(node * 2, s, mid, a, b);
	int right = query(node * 2 + 1, mid + 1, e, a, b);
	return arr[left] >= arr[right] ? right : left;
}

//최소높이의 인덱스를 기준으로 왼쪽/오른쪽 구간의 최대넓이를 구함.
// 인덱스를 기준으로 왼쪽/오른쪽으로 정확히 나눠서 구하는 이유?
// 인덱스를 포함하고 왼/오른쪽을 다 포함시킨다면, 어차피 인덱스에서 높이가 가장 작기에 인덱스를 포함하는 구간에서는 무조건 1~N이 최대가 되기때문이다.
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