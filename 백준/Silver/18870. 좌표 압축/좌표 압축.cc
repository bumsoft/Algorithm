#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int arr[1'000'001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	priority_queue<pair<int, int>> PQ;

	cin >> N;
	int t;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		PQ.push({ -t,i });
	}
	int prev = -1000000001;
	int num = 0;
	while (!PQ.empty())
	{
		int v = -PQ.top().first;
		int l = PQ.top().second;
		PQ.pop();
		if (prev == v)
		{
			arr[l] = num-1;
			continue;
		}
		arr[l] = num++;
		prev = v;
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}