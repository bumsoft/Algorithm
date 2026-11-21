#include <bits/stdc++.h>
using namespace std;

//a.다익스트라 1번 돌리고
//b.수색범위 내의 아이템 개수 모두 더함
//c.max 갱신
// a-b-c를 정점개수만큼 반복하고 max출력.

#define INF 2100000000;
vector<pair<int, int>> vertex[101];
int D[101];
int I[101];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int max = 0;
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> I[i];
	}
	int a, b, c;
	for (int i = 1; i <= r; i++)
	{
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(b, c));
		vertex[b].push_back(make_pair(a, c));
	}
	for (int i = 0; i <= 100; i++)
	{
		D[i] = INF;
	}

	priority_queue<pair<int, int>> PQ;
	for (int i = 1; i <= n; i++)
	{
		int arr[101];
		memcpy(&arr, &D, sizeof(int)*101);

		PQ.push(make_pair(0, i));
		arr[i] = 0;

		while (!PQ.empty())
		{
			int Cost = -PQ.top().first;//0
			int Ver = PQ.top().second;//2
			PQ.pop();
			if (arr[Ver] < Cost) continue;
			for (int j = 0; j < vertex[Ver].size(); j++)
			{

				int nextVer = vertex[Ver][j].first;
				int nextCost = vertex[Ver][j].second;

				if (Cost + nextCost < arr[nextVer])
				{
					arr[nextVer] = Cost + nextCost;
					PQ.push(make_pair(-arr[nextVer], nextVer));
				}
			}
		}
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (arr[j] <= m)
			{
				sum += I[j];
			}
		}
		max = sum > max ? sum : max;
	}
	cout << max;

	return 0;
}