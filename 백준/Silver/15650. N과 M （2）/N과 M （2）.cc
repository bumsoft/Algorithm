//N과M(2)
//1부터 N까지 자연수 중 중복없이 M개 고른 수열
//수열은 오름차순.
//앞을 고르면 안됨
#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[9];
bool _visit[9];

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
		if (!_visit[i])
		{
			_visit[i] = true;
			arr[_count] = i;
			dfs(_count + 1,i);
			_visit[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	
	dfs(0,1);

	return 0;
}