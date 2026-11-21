#include <bits/stdc++.h>
using namespace std;
/*
BFS: X+1 X-1 X*2  3중 1개 택
*/

queue<pair<pair<int, int>, queue<int>>> Q;
bool vis[100'001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, K; //0<=100'000
	cin >> N >> K;
	if (N >= K)
	{
		cout << N - K << '\n';
		for (int i = N; i >= K; i--)
		{
			cout << i << ' ';
		}
		return 0;
	}
	queue<int> q;
	q.push(N);
	Q.push({ {N,0}, q});
	vis[N] = 1;
	int now;
	int cost;
	while (!Q.empty())
	{
		now = Q.front().first.first;
		cost = Q.front().first.second;
		q = Q.front().second;
		Q.pop();
		if (now == K)
		{
			cout << cost << '\n';
			while (!q.empty())
			{
				cout << q.front() << ' ';
				q.pop();
			}
			return 0;
		}

		//+1
		if (now + 1 <= 100'000 && !vis[now + 1])
		{
			queue<int> qq = q;
			qq.push(now + 1);
			Q.push({ {now + 1, cost + 1 },qq });
			vis[now + 1] = 1;
		}
		//-1
		if (now - 1 >= 0 && !vis[now - 1])
		{
			queue<int> qq = q;
			qq.push(now - 1);
			Q.push({ { now - 1, cost + 1 },qq });
			vis[now - 1] = 1;
		}
		//*2
		if (now * 2 <= 100'000 && !vis[now * 2])
		{
			queue<int> qq = q;
			qq.push(now * 2);
			Q.push({ { now * 2, cost + 1 },qq });
			vis[now * 2] = 1;
		}
	}

	return 0;
}