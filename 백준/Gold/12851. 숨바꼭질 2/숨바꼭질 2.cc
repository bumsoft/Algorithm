#include <bits/stdc++.h>
using namespace std;
/* 
BFS: X+1 X-1 X*2  3중 1개 택
*/

queue<pair<int,int>> Q;
bool vis[100'001];

pair<int, int> ways[100'001]; //<cost,ways>

int main() {
	
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, K; //0<=100'000
	cin >> N >> K;
	if (N >= K)
	{
		cout << N - K << '\n' << 1;
		return 0;
	}
	
	//init ways
	for (int i = 0; i <= 100'000; i++)
	{
		ways[i].first = 0;
		ways[i].second = 0;
	}

	Q.push({N,0});
	vis[N] = 1;
	int now;
	int cost;
	ways[N].first = 0;
	ways[N].second = 1;
	while (!Q.empty())
	{
		now = Q.front().first;
		cost = Q.front().second;
		Q.pop();



		if (now == K)
		{
			cout << cost << '\n' << ways[now].second;
			return 0;
		}

		//+1
		if (now+1 <= 100'000 && !vis[now+1])
		{
			Q.push({ now + 1, cost + 1 });
			vis[now + 1] = 1;

			ways[now + 1].first = cost + 1;
			ways[now + 1].second = ways[now].second;
		}
		else if (now + 1 <= 100'000 && vis[now + 1] && ways[now + 1].first == cost + 1)
		{
			ways[now + 1].second += ways[now].second;
		}

		//-1
		if (now - 1 >= 0 && !vis[now - 1])
		{
			Q.push({ now - 1, cost + 1 });
			vis[now - 1] = 1;

			ways[now - 1].first = cost + 1;
			ways[now - 1].second = ways[now].second;
		}
		else if (now - 1 >=0 && vis[now - 1] && ways[now - 1].first == cost + 1)
		{
			ways[now - 1].second += ways[now].second;
		}

		//*2
		if (now * 2 <= 100'000 && !vis[now * 2])
		{
			Q.push({ now * 2, cost + 1 });
			vis[now * 2] = 1;

			ways[now * 2].first = cost + 1;
			ways[now * 2].second = ways[now].second;
		}
		else if (now * 2 <= 100'000 && vis[now * 2] && ways[now * 2].first == cost + 1)
		{
			ways[now * 2].second += ways[now].second;
		}
	}

	return 0;
}