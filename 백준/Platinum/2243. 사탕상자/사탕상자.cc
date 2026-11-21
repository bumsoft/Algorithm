#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//노드에 사탕의 개수를 저장,
int seg[1'000'000 << 2];

int N;

//사탕을 넣거나 빼는 경우
void in_out(int node, int s, int e, int i, int c)
{
	//if (i<s || i>e) return;
	seg[node] += c;
	if (s == e) return;
	int mid = (s + e) / 2;
	if (i <= mid) return in_out(node * 2, s, mid, i, c);
	else return in_out(node * 2+1, mid + 1, e, i, c);
}
//사탕을 주는 경우(출력)
int out(int node, int s, int e, int i)
{
	seg[node] -= 1;
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (i <= seg[node * 2]) return out(node * 2, s, mid, i);
	else return out(node * 2 + 1, mid + 1, e, i - seg[node * 2]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;

	int a, b, c;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == 1) //꺼냄
		{
			cin >> b;
			cout << out(1, 1, 1'000'000, b) << '\n';
		}
		else
		{
			cin >> b >> c; //b위치에 c증가
			in_out(1, 1, 1'000'000, b, c);
		}
	}
	return 0;
}