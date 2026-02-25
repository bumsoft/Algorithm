#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/**
. : 바다
# : 암초
* : 보물
K : 배
*/

int H, W;

// 우상 우 우하
int dx0[] = { -1, 0, 1 };
int dy0[] = { 1, 1, 1 };

//상 좌상 좌 좌하 하
int dx1[] = { -1, -1, 0, 1, 1 };
int dy1[] = { 0, -1, -1, -1, 0 };

char board[501][501];
int D[501][501];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int start_x = 0;
	int start_y = 0;

	int end_x = 0;
	int end_y = 0;

	cin >> H >> W;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			D[i][j] = INT_MAX;
			cin >> board[i][j];
			if (board[i][j] == 'K')
			{
				start_x = i;
				start_y = j;
				D[i][j] = 0;
			}
			else if (board[i][j] == '*')
			{
				end_x = i;
				end_y = j;
			}
		}
	}

	deque<pair<int, pair<int, int>>> DQ;
	DQ.push_front({ 0, {start_x, start_y} });
	while (!DQ.empty())
	{
		int cx = DQ.front().second.first;
		int cy = DQ.front().second.second;
		int cdis = DQ.front().first;
		DQ.pop_front();
		if (cdis > D[cx][cy]) continue;
		for (int i = 0; i < 3; i++) //0
		{
			int nx = cx + dx0[i];
			int ny = cy + dy0[i];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] == '#') continue;

			if (cdis >= D[nx][ny]) continue;
			D[nx][ny] = cdis;
			DQ.push_front({ cdis, {nx,ny} });
		}
		for (int i = 0; i < 5; i++) //1
		{
			int nx = cx + dx1[i];
			int ny = cy + dy1[i];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] == '#') continue;

			if (cdis + 1 >= D[nx][ny]) continue;
			D[nx][ny] = cdis + 1;
			DQ.push_back({ cdis + 1, {nx, ny} });
		}
	}
	if (D[end_x][end_y] == INT_MAX) cout << -1;
	else cout << D[end_x][end_y];
	return 0;
}
