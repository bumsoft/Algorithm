#include <bits/stdc++.h>
using namespace std;
/*
BFS: X+1 X-1 X*2  3중 1개 택
*/

queue<pair<int, int>> Q;
int vis[100'001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, K; //0<=100'000
	cin >> N >> K;
	if (N >= K)
	{
		cout << N - K;
		return 0;
	}
	for (int i = 0; i <= 100'000; i++)
	{
		vis[i] = INT_MAX;
	}

	Q.push({ N,0 });
	vis[N] = 0;
	int now;
	int cost;
	while (!Q.empty())
	{
		now = Q.front().first;
		cost = Q.front().second;
		Q.pop();

		//+1
		if (now + 1 <= 100'000 && vis[now + 1] > cost+1)
		{
			Q.push({ now + 1, cost + 1 });
			vis[now + 1] = cost+1;
		}
		//-1
		if (now - 1 >= 0 && vis[now - 1] > cost+1)
		{
			Q.push({ now - 1, cost + 1 });
			vis[now - 1] = cost+1;
		}
		//*2
		if (now * 2 <= 100'000 && vis[now * 2] > cost)
		{
			Q.push({ now * 2, cost });
			vis[now * 2] = cost;
		}
	}
	cout << vis[K];

	return 0;
}