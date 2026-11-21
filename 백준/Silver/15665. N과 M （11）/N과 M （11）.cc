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
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if ((N_arr[i] != 0)&&k!=N_arr[i])
		{
			//visited[i] = true;
			k = N_arr[i];
			arr[_count] = N_arr[i];
			dfs(_count + 1, i);
			//visited[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> N_arr[i];
	}

	sort(N_arr, N_arr + N);

	dfs(0,0);

	return 0;
}