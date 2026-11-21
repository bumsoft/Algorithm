#include <bits/stdc++.h>
using namespace std;
#define INF 2'100'000'000
int N;
int board[125][125];
int D[125][125];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
priority_queue<tuple<int, int, int>> PQ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t = 0;
	while (true)
	{
		t++;
		cin >> N; if (N == 0) return 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
				D[i][j] = INF;
			}
		}
		D[0][0] = board[0][0];
		PQ.push(make_tuple(-D[0][0], 0, 0));
		while (!PQ.empty())
		{
			int Cost = -get<0>(PQ.top());
			int X = get<1>(PQ.top());
			int Y = get<2>(PQ.top());
			PQ.pop();
			if (D[X][Y] < Cost) continue;
			for (int i = 0; i < 4; i++)
			{
				int x = X + dx[i];
				int y = Y + dy[i];
				if (x < 0 || x >= N || y < 0 || y >= N) continue;
				if (Cost + board[x][y] < D[x][y])
				{
					D[x][y] = Cost + board[x][y];
					PQ.push(make_tuple(-D[x][y], x, y));
				}
			}
		}
		cout << "Problem " << t << ": " << D[N - 1][N - 1] << '\n';
	}
}