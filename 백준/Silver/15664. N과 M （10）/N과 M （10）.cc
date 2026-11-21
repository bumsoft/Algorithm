#include <bits/stdc++.h>

using namespace std;

int N, M;
int N_arr[9];
int arr[9];
bool visited[9];

void dfs(int _count, int index)
{
	if (_count == M)
	{
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int k = 0;
	for (int i = index; i < N; i++)
	{
		if (!visited[i] && N_arr[i] != k)
		{
			visited[i] = true;
			arr[_count] = N_arr[i];
			k = N_arr[i];
			dfs(_count + 1, i);
			visited[i] = false;
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