//N과M(4)
//1부터 N까지 자연수 중 M개 고른 수열
//같은수 골라도 됨.
//(3)이랑 비슷한데 수열은 비내림차순으로
//3+2
#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[8];


void dfs(int _count,int index)
{
	if (_count == M)
	{
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = index; i <= N; i++)
	{
		arr[_count] = i;
		dfs(_count + 1,i);
	}
}

int main()
{
	cin >> N >> M;
	
	dfs(0,1);

	return 0;
}