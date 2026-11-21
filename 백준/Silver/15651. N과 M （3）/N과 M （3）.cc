//N과M(3)
//1부터 N까지 자연수 중 M개 고른 수열
//같은수 골라도 됨.
//(2)에서 visit만 없으면 됨
#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[8];


void dfs(int _count)
{
	if (_count == M)
	{
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		arr[_count] = i;
		dfs(_count + 1);
	}
}

int main()
{
	cin >> N >> M;
	
	dfs(0);

	return 0;
}