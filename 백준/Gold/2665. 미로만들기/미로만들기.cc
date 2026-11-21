#include <bits/stdc++.h>
using namespace std;

//검은방 비용을 1 흰방을 0으로 두고 다익스트라
#define INF 2'100'000'000
priority_queue<tuple<int, int, int>> PQ;//c,x,y
char board[51][51];
int D[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)D[i][j] = INF;

	D[1][1] = 0;
	PQ.push(make_tuple(0, 1, 1));
	while (!PQ.empty())
	{
		int cost = -get<0>(PQ.top());
		int x = get<1>(PQ.top());
		int y = get<2>(PQ.top());
		PQ.pop();
		if (D[x][y] < cost) continue;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (!(tx > 0 && tx <= n && ty > 0 && ty <= n))continue;
			int tc;
			if (board[tx][ty] == '1')//흰방
			{
				tc =  0;
			}
			else tc = 1;

			if (tc+cost < D[tx][ty])
			{
				D[tx][ty] = tc + cost;
				PQ.push(make_tuple(-D[tx][ty], tx, ty));
			}
		}
	}
	cout << D[n][n];

	
}