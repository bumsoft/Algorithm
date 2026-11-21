//N과M(7)
//N개의 자연수 중 M개 고른 수열
//같은수 여러번 가능
//정렬해야됨

#include <bits/stdc++.h>

using namespace std;

int N, M;
int N_arr[9];

int arr[9];
//bool visited[9];

void dfs(int _count, int index)
{
	if (_count == M)
	{
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = index; i < N; i++)
	{
		//if (!visited[i])
		//{
			//visited[i] = true;
			arr[_count] = N_arr[i];
			dfs(_count + 1,i);
			//visited[i] = false;
		//}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> N_arr[i];
	}
	sort(N_arr,N_arr+N);

	dfs(0,0);

	return 0;
}