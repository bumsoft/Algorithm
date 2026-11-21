#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> out[32001];

int arr[32001]; //진입차수 저장
queue<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> N >> M;
	while (M--)
	{
		cin >> a >> b;
		out[a].push_back(b);
		arr[b]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 0) { q.push(i); }

	}
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		cout << v << ' ';

		for (int i = 0; i < out[v].size(); i++)
		{
			if (--arr[out[v][i]] == 0)
			{
				q.push(out[v][i]);
			}
		}
	}
	return 0;
}